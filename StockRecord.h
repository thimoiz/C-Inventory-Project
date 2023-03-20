#ifndef STOCKRECORD_H
#define STOCKRECORD_H

#include <string>
#include <iostream>
using namespace std;

class StockRecord {
    public: string code;
    string name;
    string type;
    string manufacturer;
    double price;
    double discount;
    int quantity;

    StockRecord();

    StockRecord(string, string, string, string, double, double, int);

    void display();
};

#endif