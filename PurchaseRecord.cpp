#include "PurchaseRecord.h"
#include <string>
#include <iostream>

using namespace std;

PurchaseRecord::PurchaseRecord() {}

PurchaseRecord::PurchaseRecord(string invoiceNo, string supplierName, string productName,
    string productType, string manufacturerName,
    double retailPrice, double costPrice, int unitsPurchased) {
    this -> invoiceNo = invoiceNo;
    this -> supplierName = supplierName;
    this -> productName = productName;
    this -> productType = productType;
    this -> manufacturerName = manufacturerName;
    this -> retailPrice = retailPrice;
    this -> costPrice = costPrice;
    this -> unitsPurchased = unitsPurchased;
}

void PurchaseRecord::display() {
    cout << "Invoice No: " << invoiceNo << endl <<
        "Supplier Name: " << supplierName << endl <<
        "Product Name: " << productName << endl <<
        "Product Type: " << productType << endl <<
        "Manufacturer Name: " << manufacturerName << endl <<
        "Retail Price: $" << retailPrice << endl <<
        "Cost Price: $" << costPrice << endl <<
        "Units Purchased: " << unitsPurchased << endl << endl;
}