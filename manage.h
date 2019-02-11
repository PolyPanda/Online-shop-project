//
//  manage.hpp
//  Online Store Project
//
//  Created by Andie Yu on 6/26/17.
//  Copyright � 2017 Andie Yu. All rights reserved.
//

#ifndef manage_hpp
#define manage_hpp

#include <stdio.h>
#include "BST.h"
#include "Customer.h"
#include "Shoe.h"
#include "PriorityQueue.h"
#include "HashTable.h"
#include "Order.h"

class Manager {
private:
    BST<Shoe*> primaryKeyBST;
    BST<Shoe*> secondaryKeyBST;
    HashTable<Customer*> customerTable;
    Heap<Order*> orders;
    
    void loadStoreProducts();
    void loadCustomerInfoFromFile();
    void loadOrdersFromFile();
    void saveCustomerInfoToFile();
    void saveStoreProducts();
    void saveOrdersToFile();
    
    void addNewProduct(Shoe* newShoe);
    
    int getNewOrderId();
    
public:
    Manager() {
        loadStoreProducts();
        loadOrdersFromFile();
        loadCustomerInfoFromFile();
    }
    
    // Customer Actions
    Shoe* searchProductWithPrimaryKey(int CRN);
    Shoe* searchProductWithSecondaryKey(string name);
    
    void printProductsOrderedByPrimaryKey();
    void printProductsOrderedBySecondaryKey();
    
    void placeOrder(string customerFirstName, string customerLastName, vector<Shoe>& shoes, ShippingMehods shipMethod);
    void placeOrder2(Customer* customer, vector<Shoe>& shoe, ShippingMehods shipMethod);
    
    void printOrdersForCustomer(Customer customer);
    void saveToFiles();
    
    // Employee Actions
    Customer* searchCustomerByName(string firstName, string lastName);
    void printCustomerInfoByName(string firstName, string lastName);
    void printAllCustomerDetailedInfo();
    void addNewCustomer(string first_name, string last_name, string address, string city, string state, int zip);
    Order* topOrder();
    void shipAnOrder();
    void addNewProduct(int CRN, string brand, string gender, string color, string size, double price);
    void removeProduct(int CRN);
    void printOrders();
};

#endif /* manage_hpp */
