/*
 * Customer.cpp
 *
 *  Created on: Jun 24, 2017
 *      Author: xinghuang
 */

#include "Customer.h"
#include <iostream>
#include <iomanip>
#include <fstream>

Customer :: Customer()
{
    first_name = "";
    last_name = "";
    address = "";
    city = "";
    state = "";
    zip =0;
}

Customer::Customer(string f, string l, string a, string c,string s,int z) {
    first_name = f;
    last_name = l;
    address = a;
    city = c;
    state = s;
    zip =z;
}

//Access Functions

string Customer::getFirst_name() {
    return first_name;
}

string Customer::getLast_name() {
    return last_name;
}

string Customer::getAddress() {
    return address;
}

string Customer ::getCity() {
    return city;
}
string Customer:: getState(){
	return state;
}
int Customer::getZip(){
	return zip;
}

//Manipulation Procedures

void Customer::setFrist_name(string f){
    first_name = f;
}

void Customer::setLast_name(string l)
{
	last_name = l;
}
void Customer::setAddress(string a){
	address =a;
}
void Customer::setCity(string c){
	city = c;
}
void Customer::setState(string s){
	state = s;
}
void Customer:: setZip(int z){
	zip = z;
}




bool Customer::operator==(const Customer& customer) {
    return (first_name ==customer.first_name && last_name==customer.last_name);// so we rank the books according to the name
}
//To-do: Add <, > and << here
ostream& operator<<(ostream& os, const Customer&customer)
{
	os<<customer.first_name<<" "<<customer.last_name<<endl;
	os<<"address "<<customer.address<<endl;
	os<<"city "<<customer.city<<endl;
	os<<"state "<<customer.state<<endl;
	os<<"zip "<<customer.zip<<endl;
	return os;
}
bool Customer::operator<(const Customer& customer)// talked with tutors
{
	if(first_name==customer.first_name)

		return (last_name<customer.last_name);

	return(first_name<customer.first_name);
}
bool Customer::operator>(const Customer&customer)// talked with tutors
{
	if(first_name == customer.first_name)

		return (last_name>customer.last_name);

	return (first_name>customer.first_name);
}//
//

void Customer::addOrder(Order order) {
    orders.insertEnd(order);
}

string Customer::getPrimaryKey() {
    string primaryKey = first_name + last_name;
    return primaryKey;
}

void Customer::writeToFile(fstream& outFile) {
    outFile << first_name << endl;
    outFile << last_name << endl;
    outFile << address << endl;
    outFile << city << endl;
    outFile << state << endl;
    outFile << zip << endl;
}

