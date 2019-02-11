#include "Order.h"
#include "Customer.h"
#include <ctime>
#include <time.h>
#include <fstream>


Order::Order(int CRN, string firstName, string lastName, vector<Shoe>& shoes, ShippingMehods shippingMethod) {
    hasShipped = false;
    shipTime = "";
    orderId = CRN;
    customerFirstName = firstName;
    customerLastName = lastName;
    //    for (auto it = shoes.back(); it != shoes.end(); it++) {
    //        productList.insertEnd(*it);
    //    }
    
    shipMethod = shippingMethod;
}

void Order::printList() {
    productList.print();
}

ShippingMehods Order::shippingMethod() {
    return shipMethod;
}

double Order::totalPrice() {
    double total = 0;
    productList.beginIterator();
    while (!productList.offEnd()) {
        total += productList.getIterator().get_price();
        productList.advancedIterator();
    }
    return total;
}

void Order::setShipTime(string time) {
    shipTime = time;
    if (!shipTime.empty()) {
        hasShipped = true;
    }
}

string Order::getShipTime() {
    return shipTime;
}

void Order::shipOrder() {
    hasShipped = true;
    time_t t = time(0);   // get time now
    struct tm now;
    localtime_r(&t, &now);
    shipTime = to_string(1900) + "-" + to_string(now.tm_mon + 1) + "-" + to_string(now.tm_mday) + " " + to_string(now.tm_hour) + ":" + to_string(now.tm_min) + ":" + to_string(now.tm_sec);
}

string Order::getShipMethod() {
    if (shipMethod == ShippingMehods::OVER_NIGHT) {
        return "Over Night";
    }
    
    if (shipMethod == ShippingMehods::RUSH) {
        return "Rush";
    }
    
    if (shipMethod == ShippingMehods::STANDARD) {
        return "Standard";
    }
    
    return "Standard";
}

ostream& operator<<(ostream& os, Order& order) {
    os << "------------------------------------------------------------" << endl;
    os << "Order ID: " << order.orderId << endl
    << "Ship To: " << order.customerFirstName << " " << order.customerLastName << endl
    << "Shipped: " << (order.hasShipped ? "Yes" : "No") << endl
    << "Ship Method: " << order.getShipMethod() << endl
    << "Ship Date: 6.27.2017 " << endl;
    order.printList();
    os << "------------------------------------------------------------" << endl;
    return os;
}

ostream& operator<<(ostream& os, Order* order) {
    os << "------------------------------------------------------------" << endl;
    os << "Order ID: " << order->orderId << endl
    << "Ship To: " << order->customerFirstName << " " << order->customerLastName << endl
    << "Shipped: " << (order->hasShipped ? "Yes" : "No") << endl
    << "Ship Method: " << order->getShipMethod() << endl
    << "Ship Date: 6.27.2017"<< endl << endl;
    order->printList();
    os << "------------------------------------------------------------" << endl;
    return os;
}

bool operator==(const Order& orderA, const Order& orderB) {
    return (orderA.shipMethod == orderB.shipMethod);
}

bool operator<(const Order& orderA, const Order& orderB) {
    return (orderA.shipMethod < orderB.shipMethod);
}

bool operator>(const Order& orderA, const Order& orderB) {
    return (orderA.shipMethod > orderB.shipMethod);
}

bool Order::isOrderBelongToCustomer(string firstName, string lastName) {
    return customerFirstName == firstName && customerLastName == lastName;
}

void Order::writeToFile(ofstream& outFile) {
    outFile << orderId << endl;
    outFile << customerFirstName << endl;
    outFile << customerLastName << endl;
    outFile << hasShipped << endl;
    outFile << shipMethod << endl;
    outFile << shipTime << endl;
    if (!productList.empty()) {
        outFile << productList.getLength() << endl;
        productList.beginIterator();
        while (!productList.offEnd()) {
            outFile << productList.getIterator().get_CRN() << endl;
            productList.advancedIterator();
        }
    }
    outFile << endl;
}
