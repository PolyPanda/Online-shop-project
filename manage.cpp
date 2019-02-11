//
//  manage.cpp
//  Online Store Project
//
//  Created by Andie Yu on 6/26/17.
//  Copyright � 2017 Andie Yu. All rights reserved.
//

#include "manage.h"
#include <fstream>

bool cmpWithCRN(Shoe* a, Shoe* b) {
    return a->get_CRN() < b->get_CRN();
}

bool cmpWithName(Shoe* a, Shoe* b) {
    return a->get_Brand() < b->get_Brand();
}

bool cmpWithShippingMethod(Order* a, Order* b) {
    return a->getShipTime() < b->getShipTime();
}

// Customer Functions

Shoe* Manager::searchProductWithPrimaryKey(int CRN) {
    return primaryKeyBST.findByPrimaryKey(CRN);
}

Shoe* Manager::searchProductWithSecondaryKey(string name) {
    return secondaryKeyBST.findBySecondaryKey(name);
}

void Manager::printProductsOrderedByPrimaryKey() {
    cout << "------------------------------------------------------------" << endl;
    cout << "List Products By Primary Key (CRN):" << endl;
    cout << "------------------------------------------------------------" << endl;
    primaryKeyBST.inOrderPrint(cout);
}

void Manager::printProductsOrderedBySecondaryKey() {
    cout << "------------------------------------------------------------" << endl;
    cout << "List Products By Secondary Key (Name):" << endl;
    cout << "------------------------------------------------------------" << endl;
    secondaryKeyBST.inOrderPrint(cout);
}

Customer* Manager::searchCustomerByName(string firstName, string lastName) {
    return customerTable.find(firstName + lastName);
}

void Manager::placeOrder(string customerFirstName, string customerLastName, vector<Shoe>& shoes, ShippingMehods shipMethod) {
    Customer* customer = searchCustomerByName(customerFirstName, customerLastName);
    if (customer == NULL) {
        return;
    }
    
    placeOrder2(customer, shoes, shipMethod);
}

void Manager::placeOrder2(Customer* customer, vector<Shoe>& shoes, ShippingMehods shipMethod) {
    int CRN = getNewOrderId();
    Order* newOrder = new Order(CRN, customer->getFirst_name(),customer->getLast_name(), shoes,shipMethod);
    orders.insert(newOrder, cmpWithShippingMethod);
}

void Manager::printOrdersForCustomer(Customer customer) {
    vector<Order*> orderArray = orders.getArray();
    vector<Order*> ordersForUser;
    for (int i = 0; i < orderArray.size(); i++) {
        if (orderArray[i]->isOrderBelongToCustomer(customer.getFirst_name(), customer.getLast_name())) {
            ordersForUser.push_back(orderArray[i]);
        }
    }
    
    for (int i = 0; i < ordersForUser.size(); i++) {
        cout << ordersForUser[i];
    }
    
    cout << endl;
}

// Employee Functions

void Manager::printCustomerInfoByName(string firstName, string lastName) {
    Customer* customer = searchCustomerByName(firstName, lastName);
    if (customer == NULL) {
        return;
    }
    
    cout << "------------------------------------------------------------" << endl;
    cout << "Customer Info:" << endl;
    cout << customer;
}

void Manager::printAllCustomerDetailedInfo() {
    customerTable.printtable();
}

void Manager::addNewCustomer(string firstName, string lastName, string address, string city, string state, int zip) {
    Customer* customer = new Customer(firstName, lastName, address, city, state, zip);
    customerTable.insert(customer->getPrimaryKey(), customer);
}

void Manager::printOrders() {
    orders.sort();
    cout << "------------------------------------------------------------" << endl;
    cout << "Orders for Customer:" << endl;
    cout << "------------------------------------------------------------" << endl;
    orders.print();
}

int Manager::getNewOrderId() {
    return orders.getSize();
}

Order* Manager::topOrder() {
    orders.sort();
    if (orders.isEmpty()) {
        cout << "No order to ship " << endl;
        return NULL;
    }
    
    return orders.top();
}

void Manager::shipAnOrder() {
    orders.sort();
    if (orders.isEmpty()) {
        cout << "No order to ship " << endl;
        return;
    }
    
    Order* order = orders.top();
    order->shipOrder();
    orders.pop();
}

void Manager::addNewProduct(int CRN, string name, string gender, string color, string size, double price) {
    Shoe* shoeToAdd = primaryKeyBST.findByPrimaryKey(CRN);
    if (shoeToAdd != NULL) {
        cout << "CRN already exists!" << endl;
        return;
    }
    
    shoeToAdd = secondaryKeyBST.findBySecondaryKey(name);
    if (shoeToAdd != NULL) {
        cout << "Shoes name already exists!" << endl;
        return;
    }
    
    Shoe* newShoe = new Shoe(name, color, gender, CRN, size , price);
    addNewProduct(newShoe);
}

void Manager::addNewProduct(Shoe* newShoe) {
    primaryKeyBST.insert(newShoe, cmpWithCRN);
    secondaryKeyBST.insert(newShoe, cmpWithName);
}

void Manager::removeProduct(int CRN) {
    Shoe* shoeToRemove = primaryKeyBST.findByPrimaryKey(CRN);
    if (shoeToRemove == NULL) {
        return;
    }
    
    primaryKeyBST.remove(shoeToRemove, cmpWithCRN);
    secondaryKeyBST.remove(shoeToRemove, cmpWithCRN);
}

// File operations

void Manager::saveToFiles() {
    saveStoreProducts();
    saveCustomerInfoToFile();
    saveOrdersToFile();
}

void Manager::loadStoreProducts() {
    ifstream input;
    input.open("data.txt");
    string Brand, Color,size,Gender = "";
    int CRN =0;
    double price;
    while (input.peek() != EOF) {
        
        getline(input, Brand,',');
        getline(input, Color,',');
        getline(input, Gender,',');
        input >> price;
        getline(input, size,',');
        input >> CRN;
        input >> ws;
        input>>ws;
        
        Shoe* shoe_new1 = new Shoe(Brand,Color,Gender,CRN,size,price);
        primaryKeyBST.insertData(shoe_new1);
        secondaryKeyBST.insertData(shoe_new1);
    }
    
    input.close();
    string command;
    primaryKeyBST.preOrderPrint(cout);
    //secondaryKeyBST.inOrderPrint(cout);
}

void Manager::saveStoreProducts() {
    ofstream outFile;
    outFile.open("shoe.txt");
    
    primaryKeyBST.inOrderPrint(outFile);
    outFile.close();
}

void Manager::loadOrdersFromFile() {
    ifstream input;
    while (input.peek() != EOF) {
        string Brand, Color,size,Gender = "";
        int CRN;
        double price;
        getline(input, Brand,',');
        getline(input, Color,',');
        getline(input, Gender,',');
        input >> price;
        getline(input, size,',');
        input >> CRN;
        input >> ws;
        
        Shoe* shoe_new1 = new Shoe(Brand,Color,Gender,CRN,size,price);
        primaryKeyBST.insertData(shoe_new1);
        secondaryKeyBST.insertData(shoe_new1);
    }
}

void Manager::saveOrdersToFile() {
    ofstream outFile;
    outFile.open("Orders.txt");
    
    orders.writeToFile(outFile);
    outFile.close();
}

void Manager::loadCustomerInfoFromFile() {
    fstream inFile;
    inFile.open("Customer.txt");
    
    vector<Order*> orderArray = orders.getArray();
    if (inFile) {
        string firstName = "";
        string lastName = "";
        string address = "";
        string city = "";
        string state = "";
        int zipCode = 0;
        
        while (inFile.peek() != EOF) {
            getline(inFile, firstName);
            getline(inFile, lastName);
            getline(inFile, address);
            getline(inFile, city);
            getline(inFile, state);
            inFile >> zipCode;
            while (inFile.peek() == '\n')
                inFile.get();
            addNewCustomer(firstName, lastName, address, city, state, zipCode);
            Customer* customer = customerTable.find(firstName + lastName);
            for (auto it = orderArray.begin(); it != orderArray.end(); it++) {
                if ((*it)->isOrderBelongToCustomer(firstName, lastName)) {
                    customer->addOrder(*(*it));
                }
            }
        }
    }
    
    inFile.clear();
    inFile.close();
}

void Manager::saveCustomerInfoToFile() {
    fstream outFile;
    outFile.open("Customer.txt");
    
    customerTable.writeToFile(outFile);
    outFile.close();
}
