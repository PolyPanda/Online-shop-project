////
////  main.cpp
////  Online Store Project
////
////  Created by Andie Yu on 6/24/17.
////  Copyright © 2017 Andie Yu. All rights reserved.
////
//
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
#include "userInterface.h"
//void chooseUserType();
//void start();
//void clearInputBuffer();
//void customerLogin();
//void newCustomerMenu(string firstName, string lastName);
//
int main() {
	Manager storeManager;
	Menu mainMenu(&storeManager);
	mainMenu.start();
}
//    BST<Shoe> primaryKeyBST;
//    BST<Shoe> secondaryKeyBST;
//    HashTable<Customer> customerTable;
//    Heap<Order> orders;
//    string Brand, Color,Gender,CRN = "";
//    string size = " ";
//    double price = 0;
//    
//    
//    ifstream input;
//    string userName;
//    string passWord;
//    cout << "Welcome to the Best Shoes App! " << endl;
//    cout <<"User: ";
//    getline(cin,userName);
//    cout<< "Password: ";
//    getline(cin,passWord);
//    cout<<endl;
//    if (passWord == "1234" && userName == "staff")
//    {
//        cout << "Welcome Staff"<<endl;
//        cout << "Here is all the storage."<<endl;
//        //choice primary key or secondary key
//        cout<<endl;
//        input.open("data.txt");
//        
//        while (input.peek() != EOF) {
//            
//            getline(input, Brand,',');
//            getline(input, Color,',');
//            getline(input, Gender,',');
//            input >> price;
//            getline(input, size,',');
//            input >> CRN;
//            input >> ws;
//            
//            Shoe shoe_new1(Brand,Color,Gender,CRN,size,price);
//            primaryKeyBST.insertData(shoe_new1);
//            secondaryKeyBST.insertData(shoe_new1);
//        }
//        
//        input.close();
//        string command;
//        primaryKeyBST.inOrderPrint(cout);
//        secondaryKeyBST.inOrderPrint(cout);
//        cout<<"What you want do to manage the product? Please enter manage product or manage customer page."<<endl;
//        getline(cin,command);
//        if(command == "manage product")
//        {
//            string insertOrDelete;
//            cout<<"You want insert or delete product?";
//            getline(cin,insertOrDelete);
//            if (insertOrDelete == "insert")
//            {
//                cout<<"What is the brand for the product? ";
//                getline(cin,Brand);
//                cout<<"What is the gender for the product? ";
//                getline(cin,Gender);
//                cout<<"What is the color for the product? ";
//                getline(cin,Color);
//                cout<<"What is the CRN for the product? ";
//                getline(cin,CRN);
//                cout<<"What is the size for the product? ";
//                getline(cin,size);
//                cout<<"What is the price for the product? ";
//                cin>>price;
//                Shoe shoe_new2(Brand,Color,Gender,CRN,size,price);
//                ShoeTree1.insert(shoe_new2);
//                ShoeTree2.insertsecond(shoe_new2);
//                cout<<endl;
//                cout<<"Insert successful."<<endl;
//                cout<<"Here is the new storage list"<<endl;
//                cout<<endl;
//                ShoeTree1.inOrderPrint();
//            }
//            if(insertOrDelete == "delete")
//            {
//                cout<<"What is the brand for the product? ";
//                getline(cin,Brand);
//                cout<<"What is the gender for the product? ";
//                getline(cin,Gender);
//                cout<<"What is the color for the product? ";
//                getline(cin,Color);
//                cout<<"What is the CRN for the product? ";
//                getline(cin,CRN);
//                cout<<"What is the size for the product? ";
//                getline(cin,size);
//                cout<<"What is the price for the product? ";
//                cin>>price;
//                Shoe shoe_delete1(Brand,Color,Gender,CRN,size,price);
//                ShoeTree1.remove(shoe_delete1);
//                cout<<endl;
//                cout<<"Delete successful."<<endl;
//                cout<<"Here is the new storage list"<<endl;
//                cout<<endl;
//            }
//        }
//    }
//    else
//    {
//        cout << "Here are all the shoes that is ready for you to order."<<endl;
//        cout<<endl;
//        input.open("data.txt");
//        
//        while (input.peek() != EOF) {
//            
//            getline(input, Brand,',');
//            getline(input, Color,',');
//            getline(input, Gender,',');
//            input >> price;
//            getline(input, size,',');
//            input >> CRN;
//            input >> ws;
//            
//            Shoe shoe_new1(Brand,Color,Gender,CRN,size,price);
//            ShoeTree1.insert(shoe_new1);
//            ShoeTree2.insertsecond(shoe_new1);
//        }
//        
//        input.close();
//        
//        string firstName, lastName, address, city, state;
//        int zip;
//        ShoeTree1.inOrderPrint(cout);
//        cout << "First Name:";
//        getline(cin,firstName);
//        cout << "Last Name:";
//        getline(cin,lastName);
//        cout << "Address:";
//        getline(cin,address);
//        cout <<"City: ";
//        getline(cin, city);
//        cout <<"State: ";
//        getline(cin, state);
//        cout<< "Zip: ";
//        cin>>zip;
//        HashTable ht;
//        Customer c(firstName, lastName, address, city, state, zip);
//        ht.insertData(c);
//        int index = ht.hash(c.getFirst_name()+c.getLast_name());
//        ht.printBucket(index);
//    }
//    
//    return 0;
//}
//
//void start() {
//    chooseUserType();
//    
//    if (isEmployee) {
//        showEmployeeMainMenu();
//    }
//    else {
//        customerLogin();
//    }
//}
//
//void clearInputBuffer() {
//    cin.clear();
//    cin.ignore(INT_MAX, '\n');
//}
//
//void chooseUserType() {
//    int type = 0;
//    bool validInput = false;
//    
//    while (!validInput) {
//        cout << "Please choose user type:" << endl
//        << "1. Customer" << endl
//        << "2. Employee" << endl;
//        
//        cin >> type;
//        clearInputBuffer();
//        
//        if (type == 1 || type == 2) {
//            validInput = true;
//            if (type == 1) {
//                isEmployee = false;
//                break;
//            }
//            else if (type) {
//                isEmployee = true;
//                break;
//            }
//        }
//    }
//}
//
//void customerLogin() {
//    cout << "------------------------------------------------------------" << endl;
//    cout << "Please Enter your first name and last name:" << endl;
//    string firstName = "";
//    string lastName = "";
//    cin >> firstName;
//    cin >> lastName;
//    clearInputBuffer();
//    
//    Customer* customer = manager->searchCustomerByName(firstName, lastName);
//    if (customer == NULL) {
//        newCustomerMenu(firstName, lastName);
//    }
//    curCustomer = manager->searchCustomerByName(firstName, lastName);
//    showCustomerMainMenu();
//}
//
//void newCustomerMenu(string firstName, string lastName) {
//    cout << "------------------------------------------------------------" << endl;
//    cout << "Can't find customer, now will create a new one:" << endl;
//    cout << "Please enter your address:" << endl;
//    string address = "";
//    getline(cin, address);
//    
//    cout << "Please enter your city:" << endl;
//    string city = "";
//    getline(cin, city);
//    
//    cout << "Please enter your state:" << endl;
//    string state = "";
//    getline(cin, state);
//    
//    cout << "Please enter your zip code:" << endl;
//    int zipCode = 0;
//    cin >> zipCode;
//    clearInputBuffer();
//    
//    manager->addNewCustomer(firstName, lastName, address, city, state, zipCode);
//}
