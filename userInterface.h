//
//  userInterface.hpp
//  Online Store Project
//
//  Created by Andie Yu on 6/26/17.
//  Copyright © 2017 Andie Yu. All rights reserved.
//

#ifndef userInterface_hpp
#define userInterface_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "BST.h"
#include "Shoe.h"
#include "Order.h"
#include "HashTable.h"
#include "List.h"
#include "Shoe.h"
#include "Customer.h"
#include "manage.h"

class Menu {
private:
    Manager* manager;
    Customer* curCustomer;
    bool isEmployee;
    
    void chooseUserType();
    void clearInputBuffer();
    // Customer Menus
    void customerLogin();
    void newCustomerMenu(string firstName, string lastName);
    void showCustomerMainMenu();
    void searchProductMenu();
    void listProductMenu();
    void placeOrderMenu();
    void viewPurchaseMenu();
    
    // Employee Menus
    void showEmployeeMainMenu();
    void searchCustomerMenu();
    void displayAllCustomerMenu();
    void displayAllOrdersMenu();
    void shipOrderMenu();
    void addProductMenu();
    void deleteProductMenu();
    
public:
    Menu(Manager* mgr) {
        manager = mgr;
        isEmployee = false;
        curCustomer = NULL;
    }
    
    void start();
    
};
#endif /* userInterface_hpp */
