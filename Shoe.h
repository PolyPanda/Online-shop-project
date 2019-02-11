/*
 * Shoe.h
 *
 *  Created on: 2017Äê5ÔÂ28ÈÕ
 *      Color: jl901
 */

#ifndef Shoe_H_
#define Shoe_H_

#include <string>
#include <ostream>
using namespace std;

class Shoe {
private:
    string Brand;
    string Color;
    string Gender;
    int CRN;
    string size;
    double price; 
    
public:
    
    /**Constructors*/
    Shoe();
    Shoe(string b, string c,string g, int r, string s, double p);
    
    
    /**Access Functions*/
    string get_Brand();
    string get_Color();
    string get_Gender();
    int get_CRN();
    string get_size();
    double get_price();
    int getPrimaryKey();
    string getSecondaryKey();
    
    /**Manipulation Procedures*/
    void set_Brand(string b);
    void set_Color(string c);
    void set_Gender(string g);
    void set_CRN(int r);
    void set_size(string s);
    void set_price(double p);
    
    
    /**Additional Functions*/
    
    friend ostream& operator<<(ostream& os, const Shoe& Shoe);
    //prints out a Shoe to the designated stream in the following format
    //<Brand> by <Color>
    //$<price>
    //size #<size>
    //note that the << is required to be a friend function, not a member function
    //note2: do not print out the <> as part of the output
    
    bool operator==(const Shoe& Shoe);
    //compares two Shoes to determine if they are the same Shoe
    
    bool operator<(const Shoe& Shoe);
    //compares two Shoes to determine if one comes before the other
    //alphabetically by Brand and secondarily by Color if the two
    //Shoes contain the same Brand
    //returns false if the two Shoes are the same
    
    bool operator>(const Shoe& Shoe);
    //compares two Shoes to determine if one comes after the other
    //alphabetically by Brand and secondarily by Color if the two
    //Shoes contain the same Brand
    //returns false if the two Shoes are the same
    bool operator>=(const Shoe& shoe);
    bool operator!=(const Shoe& shoe);
    bool operator<=(const Shoe& shoe);
};
#endif /* Shoe_H_ */

