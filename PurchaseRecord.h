#ifndef PURCHASERECORD_H
#define PURCHASERECORD_H

#include <string>
#include <iostream>
using namespace std;


class PurchaseRecord {
    public: 
    string invoiceNo;
    string supplierName;
    string productName;
    string productType;
    string manufacturerName;
    double retailPrice;
    double costPrice;
    int unitsPurchased;

    PurchaseRecord();

    PurchaseRecord(string, string, string, string, string, double, double, int);

    void display();
};

#endif