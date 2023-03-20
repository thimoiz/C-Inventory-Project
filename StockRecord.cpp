#include "StockRecord.h"

#include <string>

#include <iostream>

using namespace std;

StockRecord::StockRecord() {}

StockRecord::StockRecord(string code, string name, string type, string manufacturer,
    double price, double discount, int quantity) {
    this -> code = code;
    this -> name = name;
    this -> type = type;
    this -> manufacturer = manufacturer;
    this -> price = price;
    this -> discount = discount;
    this -> quantity = quantity;
}

void StockRecord::display() {
    cout << "Code: " << code << endl <<
        "Name: " << name << endl <<
        "Type: " << type << endl <<
        "Manufacturer: " << manufacturer << endl <<
        "Price: $" << price << endl <<
        "Discount: " << discount << "%" << endl <<
        "Quantity: " << quantity << endl << endl;
}