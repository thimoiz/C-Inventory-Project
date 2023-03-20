#include "SalesRecord.h"
#include <string>
#include <iostream>

using namespace std;

SalesRecord::SalesRecord() {}

SalesRecord::SalesRecord(string invoiceNo, string dateTime, string customerName,
    int noOfItems, double totalAmount) {
    this -> invoiceNo = invoiceNo;
    this -> dateTime = dateTime;
    this -> customerName = customerName;
    this -> noOfItems = noOfItems;
    this -> totalAmount = totalAmount;
}

void SalesRecord::display() {
    cout << "Invoice No: " << invoiceNo << endl <<
        "Date/Time: " << dateTime << endl <<
        "Customer Name: " << customerName << endl <<
        "Number of Items Sold: " << noOfItems << endl <<
        "Total Amount Paid: $" << totalAmount << endl << endl;
}