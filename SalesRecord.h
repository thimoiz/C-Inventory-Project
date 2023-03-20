#ifndef SALESRECORD_H
#define SALESRECORD_H

#include <string>
#include <iostream>
using namespace std;

class SalesRecord {
    public: string invoiceNo;
    string dateTime;
    string customerName;
    int noOfItems;
    double totalAmount;

    SalesRecord();

    SalesRecord(string, string, string, int, double);

    void display();
};

#endif