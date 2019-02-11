/*
 * Customer.h
 *
 *  Created on: Jun 24, 2017
 *      Author: xinghuang
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>
#include <ostream>
#include "Order.h"
using namespace std;

class Customer {
private:
    string first_name;
    string last_name;
    string address;
    string city;
    string state;
    int zip;
    List<Order> orders;
    //List<Order> orders;


public:

//Constructors
    Customer();
    Customer(string f, string l,string a, string c, string s,int z );


    //Access Functions
    string getFirst_name();
    string getLast_name();
    string getAddress();
    string getCity();
    string getState();
    int    getZip();


    //Manipulation Procedures
    void setFrist_name(string f);
    void setLast_name(string l);
    void setAddress(string a);
    void setCity(string c);
    void setState(string s);
    void setZip(int z);


    friend ostream& operator<<(ostream& os, const Customer& customer);

        bool operator==(const Customer& customer);

        bool operator<(const Customer& customer);

        bool operator>(const Customer& customer);
    
    void addOrder(Order order);
    string getPrimaryKey();
    void writeToFile(fstream& outFile);

};





#endif /* CUSTOMER_H_ */
        //
