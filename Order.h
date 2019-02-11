
#ifndef ORDER_H_
#define ORDER_H_
#include <iostream>
#include <string>
#include "List.h"
#include "Shoe.h"
#include <time.h>
#include <ctime>
#include <time.h>
#include <vector>
using namespace std;

enum ShippingMehods {
    OVER_NIGHT,
    RUSH,
    STANDARD,
};

class Order {
private:
    List<Shoe> productList;
    ShippingMehods shipMethod;
    string customerFirstName;
    string customerLastName;
    bool hasShipped;
    string shipTime;
    int orderId;
public:
    Order(int CRN, string firstName, string lastName, vector<Shoe>& shoes, ShippingMehods shippingMethod);
    double totalPrice();
    void printList();
    ShippingMehods shippingMethod();
    void shipOrder();
    void setShipTime(string time);
    string getShipTime();
    friend ostream& operator<<(ostream& os, Order& shoe);
    friend ostream& operator<<(ostream& os, Order* shoe);
    friend bool operator==(const Order& OrderA, const Order& OrderB);
    friend bool operator<(const Order& OrderA, const Order& OrderB);
    friend bool operator>(const Order& OrderA, const Order& OrderB);
    string getShipMethod();
    bool isOrderBelongToCustomer(string firstName, string lastName);
    void writeToFile(ofstream& outFile);
};
#endif
