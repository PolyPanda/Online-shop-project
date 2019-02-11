//
//  userInterface.cpp
//  Online Store Project
//
//  Created by Andie Yu on 6/26/17.
//  Copyright � 2017 Andie Yu. All rights reserved.
//

#include "userInterface.h"

void Menu::clearInputBuffer() {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}

void Menu::start() {
    chooseUserType();
    
    if (isEmployee) {
        showEmployeeMainMenu();
    }
    else {
        customerLogin();
    }
}

void Menu::chooseUserType() {
    int type = 0;
    bool validInput = false;
    
    while (!validInput) {
        cout << "Please choose user type:" << endl
        << "1. Customer" << endl
        << "2. Staff" << endl;
        
        cin >> type;
        clearInputBuffer();
        
        if (type == 1 || type == 2) {
            validInput = true;
            if (type == 1) {
                isEmployee = false;
                break;
            }
            else if (type) {
                isEmployee = true;
                break;
            }
        }
    }
}

void Menu::customerLogin() {
    cout << "------------------------------------------------------------" << endl;
    cout << "Please Enter your first name and last name:" << endl;
    string firstName = "";
    string lastName = "";
    cin >> firstName;
    cin >> lastName;
    clearInputBuffer();
    
    Customer* customer = manager->searchCustomerByName(firstName, lastName);
    if (customer == NULL) {
        newCustomerMenu(firstName, lastName);
    }
    curCustomer = manager->searchCustomerByName(firstName, lastName);
    showCustomerMainMenu();
}

void Menu::newCustomerMenu(string firstName, string lastName) {
    cout << "------------------------------------------------------------" << endl;
    cout << "Can't find customer, now will create a new one:" << endl;
    cout << "Please enter your address:" << endl;
    string address = "";
    getline(cin, address);
    
    cout << "Please enter your city:" << endl;
    string city = "";
    getline(cin, city);
    
    cout << "Please enter your state:" << endl;
    string state = "";
    getline(cin, state);
    
    cout << "Please enter your zip code:" << endl;
    int zipCode = 0;
    cin >> zipCode;
    clearInputBuffer();
    
    manager->addNewCustomer(firstName, lastName, address, city, state, zipCode);
}

void Menu::showCustomerMainMenu() {
    int command = 0;
    while (command != 5) {
        cout << "------------------------------------------------------------" << endl;
        cout << "Customer Menu" << endl
        << "1. Search for a product" << endl
        << "2. List Products" << endl
        << "3. Place an order" << endl
        << "4. View purchases" << endl
        << "5. Quit" << endl;
        
        cin >> command;
        clearInputBuffer();
        
        if (command == 1) {
            searchProductMenu();
            break;
        }
        else if (command == 2) {
            listProductMenu();
            //no need to break
        }
        else if (command == 3) {
            placeOrderMenu();
            break;
        }
        else if (command == 4) {
            viewPurchaseMenu();
            break;
        }
        else if (command == 5) {
            manager->saveToFiles();
            break;
        }
    }
}

void Menu::searchProductMenu() {
    int command = 0;
    while (command != 3) {
        cout << "------------------------------------------------------------" << endl;
        cout << "Search for a product" << endl
        << "1. Search by CRN" << endl
        << "2. Search by shoe name" << endl
        << "3. Go back to previous menu" << endl;
        
        cin >> command;
        
        if (command == 1) {
            cout << "Please input CRN" << endl;
            int CRN = 0;
            cin>>CRN;
            Shoe* shoe = manager->searchProductWithPrimaryKey(CRN);
            cout << "------------------------------------------------------------" << endl;
            if (shoe != NULL) {
                cout << *shoe << endl;
            }
            else {
                cout << "Can't find Shoe with CRN " << CRN << endl;
            }
            clearInputBuffer();
        }
        else if (command == 2) {
            string shoeName = "";
            cout << "Please input shoe name" << endl;
            clearInputBuffer();
            getline(cin, shoeName);
            Shoe* shoe = manager->searchProductWithSecondaryKey(shoeName);
            cout << "------------------------------------------------------------" << endl;
            if (shoe != NULL) {
                cout << *shoe << endl;
            }
            else {
                cout << "Can't find shoes with shoe name " << shoeName << endl;
            }
        }
        else if (command == 3) {
            break;
        }
    }
    
    showCustomerMainMenu();
}

void Menu::listProductMenu() {
    int command = 0;
    while (command != 3) {
        cout << "------------------------------------------------------------" << endl;
        cout << "List products" << endl
        << "1. List by CRN" << endl
        << "2. List by Shoe Name" << endl
        << "3. Go back to previous menu" << endl;
        
        cin >> command;
        clearInputBuffer();
        
        if (command == 1) {
            manager->printProductsOrderedByPrimaryKey();
        }
        else if (command == 2) {
            manager->printProductsOrderedBySecondaryKey();
        }
        else if (command == 3) {
            break;
        }
        
        clearInputBuffer();
    }
}

void Menu::placeOrderMenu() {
    cout << "------------------------------------------------------------" << endl;
    cout << "Place an order" << endl;
    
    cout << "------------------------------------------------------------" << endl;
    cout << "Please input number of shoes you want to buy" << endl;
    int number = 0;
    cin >> number;
    clearInputBuffer();
    cout << "Please input " << number << " shoe CRN you want to buy" << endl;
    vector <Shoe> purchses;
    for (int i = 0; i < number; i++) {
        int CRN = 0;
        cin>>CRN;
        clearInputBuffer();
        Shoe* shoe = manager->searchProductWithPrimaryKey(CRN);
        if (shoe != NULL) {
            purchses.push_back(*shoe);
        }
        else {
            cout << "Invalid CRN" << endl;
        }
    }
    
    int shipMethod = 0;
    
    cout << "------------------------------------------------------------" << endl;
    cout << "Please input shipping method" << endl
    << "1. Overnight Shipping" << endl
    << "2. Rush Shipping" << endl
    << "3. Standard Shipping" << endl;
    
    cin >> shipMethod;
    clearInputBuffer();
    
    ShippingMehods sm = ShippingMehods::STANDARD;
    if (shipMethod == 1) {
        sm = ShippingMehods::OVER_NIGHT;
    }
    else if (shipMethod == 2) {
        sm = ShippingMehods::RUSH;
    }
    manager->placeOrder2(curCustomer, purchses, sm);
    showCustomerMainMenu();
}

void Menu::viewPurchaseMenu() {
    manager->printOrdersForCustomer(*curCustomer);
    showCustomerMainMenu();
}

// Emlopyee Menu
void Menu::showEmployeeMainMenu() {
    int command = 0;
    while (command != 8) {
        cout << "------------------------------------------------------------" << endl;
        cout << "Employee Menu" << endl
        << "1. Search for a customer" << endl
        << "2. Display all customer" << endl
        << "3. View all orders" << endl
        << "4. Ship an order" << endl
        << "5. List Products" << endl
        << "6. Add a new product" << endl
        << "7. Delete a product" << endl
        << "8. Quit" << endl;
        
        cin >> command;
        clearInputBuffer();
        
        if (command == 1) {
            searchCustomerMenu();
            break;
        }
        else if (command == 2) {
            displayAllCustomerMenu();
            break;
        }
        else if (command == 3) {
            displayAllOrdersMenu();
            break;
        }
        else if (command == 4) {
            shipOrderMenu();
            break;
        }
        else if (command == 5) {
            listProductMenu();
            //no need to break
        }
        else if (command == 6) {
            addProductMenu();
            break;
        }
        else if (command == 7) {
            deleteProductMenu();
            break;
        }
        else if (command == 8) {
            manager->saveToFiles();
            break;
        }
    }
}

void Menu::searchCustomerMenu() {
    cout << "------------------------------------------------------------" << endl;
    cout << "Please input the customer first name and last name" << endl;
    string firstName = "";
    string lastName = "";
    cin >> firstName;
    cin >> lastName;
    clearInputBuffer();
    
    Customer* customer = manager->searchCustomerByName(firstName, lastName);
    if (customer != NULL) {
        cout << customer << endl;
    }
    else {
        cout << "Can't find customer" << endl;
    }
    
    showEmployeeMainMenu();
}

void Menu::displayAllCustomerMenu() {
    manager->printAllCustomerDetailedInfo();
    showEmployeeMainMenu();
}

void Menu::displayAllOrdersMenu() {
    manager->printOrders();
    showEmployeeMainMenu();
}

void Menu::shipOrderMenu() {
    cout << "------------------------------------------------------------" << endl;
    Order* curOrder = manager->topOrder();
    if (curOrder != NULL) {
        cout << curOrder << endl;
        char ship = 'N';
        cout << "Confirm to ship? (Y/N)" << endl;
        cin >> ship;
        //clearInputBuffer();
        if (ship == 'Y' || ship == 'y') {
            manager->shipAnOrder();
            cout << "Order Shipped on: " << curOrder->getShipTime() << endl;
        }
    }
    
    showEmployeeMainMenu();
}

void Menu::addProductMenu() {
    cout << "------------------------------------------------------------" << endl;
    cout << "Register new shoe product" << endl;
    Shoe* shoe = NULL;
    int CRN = 0;
    
    while (CRN == 0) {
        cout << "Please input CRN" << endl;
        cin>>CRN;
        clearInputBuffer();
        shoe = manager->searchProductWithPrimaryKey(CRN);
        if (shoe != NULL) {
            cout << "Shoe CRN already exists!" << endl;
            shoe = 0;
        }
    }
    getchar();
    
    string name = "";
    while (name.empty()) {
        cout << "Please input Shoe name" << endl;
        getline(cin, name);
        shoe = manager->searchProductWithSecondaryKey(name);
        if (shoe != NULL) {
            cout << "Shoes already exists!" << endl;
            name = "";
        }
    }
    
    cout << "Please input the color" << endl;
    string color = "";
    getline(cin, color);
    
    cout << "Please input the gender" << endl;
    string gender = "";
    getline(cin, gender);
    
    cout << "Please input the size " << endl;
    string size = "";
    getline(cin,size);
    clearInputBuffer();
    getchar();
    
    cout << "Please input shoe price" << endl;
    double price = 0;
    cin >> price;
    clearInputBuffer();
    getchar();
    
    manager->addNewProduct(CRN, name, color, gender, size, price);
    cout << "Shoes Register Complete!" << endl;
    
    showEmployeeMainMenu();
}

void Menu::deleteProductMenu() {
    cout << "------------------------------------------------------------" << endl;
    cout << "Please input the CRN to unregister" << endl;
    int CRN = 0;
    cin>>CRN;
    clearInputBuffer();
    
    Shoe* shoeToRemove = manager->searchProductWithPrimaryKey(CRN);
    if (shoeToRemove == NULL) {
        cout << "Can't find shoes to unregister" << endl;
    }
    else {
        cout << "------------------------------------------------------------" << endl;
        cout << *shoeToRemove << endl;
        char confirm = 'n';
        cout << "------------------------------------------------------------" << endl;
        cout << "Confirm unregister? (Y/N)" << endl;
        cin >> confirm;
        clearInputBuffer();
        if (confirm == 'Y' || confirm == 'y') {
            manager->removeProduct(CRN);
            cout << "Unregister Completed!" << endl;
        }
        else {
            cout << "Unregister Canceled" << endl;
        }
        
    }
    
    showEmployeeMainMenu();
}
