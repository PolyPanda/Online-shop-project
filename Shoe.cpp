#include "Shoe.h"
#include <iostream>
#include <iomanip>

Shoe::Shoe():Brand(""), Color(""),Gender(""),CRN(0),size(""), price(0.0){};

Shoe::Shoe(string b, string c,string g, int r, string s, double p) {
    Brand = b;
    Color = c;
    Gender = g;
    CRN = r;
    size = s;
    price = p;
}

/**Access Functions*/

string Shoe::get_Brand() {
    return Brand;
}

string Shoe::get_Gender() {
    return Gender;
}
string Shoe::get_Color() {
    return Color;
}
int Shoe::get_CRN() {
    return CRN;
}
string Shoe::get_size() {
    return size;
}

double Shoe::get_price() {
    return price;
}

int Shoe::getPrimaryKey() {
    return get_CRN();
}

string Shoe::getSecondaryKey() {
    return Brand;
}

/**Manipulation Procedures*/

void Shoe::set_Brand(string b){
    Brand = b;
}

void Shoe::set_Gender(string g) {
    Gender = g;
}
void Shoe::set_Color(string c) {
    Color = c;
}
void Shoe::set_CRN(int r) {
    CRN = r;
}
void Shoe::set_size(string s) {
    size = s;
}

void Shoe::set_price(double p) {
    price = p;
}

/**Additional Functions*/

//To-do: Add <, > and << here
bool Shoe::operator==(const Shoe& shoe) {
    return (Brand == shoe.Brand);
}
ostream& operator<<(ostream& os, const Shoe& shoe)
{
    os << "Brand: " << shoe.Brand << endl;
    os << "Gender: " << shoe.Gender << endl;
    os << "Color: " << shoe.Color << endl;
    os << "CRN : " << shoe.CRN<< endl;
    os << "size: " << shoe.size<< endl;
    os << "Price: $" << shoe.price << endl;
    return os;
}

/*
 bool Shoe::operator<(const Shoe& shoe)
 {
 if (Brand < shoe.Brand)
 return true;
 else if (Brand == shoe.Brand && Gender< shoe.Gender)
 return true;
 else
 return false;
 }
 
 bool Shoe::operator>(const Shoe& shoe)
 {
 if (Brand > shoe.Brand)
 return true;
 else if (Brand == shoe.Brand && Gender > shoe.Gender)
 return true;
 else
 return false;
 }
 */
bool Shoe::operator<(const Shoe& shoe)
{
    if (Brand != shoe.Brand)
    {
        for (int a = 0; a < Brand.length(); a++)
        {
            if (Brand[a] < shoe.Brand[a])
                return true;
            else if (Brand[a] > shoe.Brand[a])
                return false;
        }
    }else
    {
        for (int b = 0; b < Gender.length(); b++)
        {
            if (Gender[b] < shoe.Gender[b])
                return true;
            else if (Gender[b] > shoe.Gender[b])
                return false;
        }
    }
    return false;
}
bool Shoe::operator>(const Shoe& shoe)
{
    if (Brand != shoe.Brand)
    {
        for (int a = 0; a < Brand.length(); a++)
        {
            if (Brand[a] > shoe.Brand[a])
                return true;
            else if (Brand[a] < shoe.Brand[a])
                return false;
        }
    }else
    {
        for (int b = 0; b < Gender.length(); b++)
        {
            if (Gender[b] > shoe.Gender[b])
                return true;
            else if (Gender[b] < shoe.Gender[b])
                return false;
        }
    }
    return false;
}
bool Shoe::operator<=(const Shoe& shoe)
{
    if (Gender < shoe.Gender)
        return true;
    else if (Gender == shoe.Gender && Brand< shoe.Brand)
        return true;
    else
        return false;
}
bool Shoe::operator>=(const Shoe& shoe)
{
    if (Gender > shoe.Gender)
	       return true;
    else if (Gender == shoe.Gender && Brand > shoe.Brand)
	       return true;
    else
	       return false;
}
bool Shoe::operator!=(const Shoe& shoe)
{
    return (Gender == shoe.Gender );
}
