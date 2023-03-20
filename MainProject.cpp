#include <iostream>
#include <fstream>
#include <string>

#include "StockRecord.h"
#include "SalesRecord.h"
#include "PurchaseRecord.h"

using namespace std;

// Function Prototypes
void writeStocksToFile(const StockRecord stocks[], int numStocks, const string fileName);
void writeSalesRecordsToFile(const SalesRecord sales[], int numSales, const string fileName);
void writePurchaseRecordsToFile(const PurchaseRecord purchase[], int numPurchase, const string fileName);

// Main Functions --------------------------------
int main() {

    cout << "\n ------------ Muhammad Moiz : 221073 ----------------\n" << endl;

    const string STOCKS_FILE = "stocks.txt";
    const string SALES_FILE = "sales.txt";
    const string PURCHASE_FILE = "purchase.txt";
    const int MAX_RECORDS = 100;

    // Load data from files into arrays of objects
    StockRecord stocks[MAX_RECORDS];
    SalesRecord sales[MAX_RECORDS];
    PurchaseRecord purchases[MAX_RECORDS];
    int numStocks = 0, numSales = 0, numPurchases = 0;

    ifstream stocksFile(STOCKS_FILE);
    if (stocksFile.is_open()) {
        while (numStocks < MAX_RECORDS && stocksFile >> stocks[numStocks].code >>
            stocks[numStocks].name >> stocks[numStocks].type >>
            stocks[numStocks].manufacturer >> stocks[numStocks].price >>
            stocks[numStocks].discount >> stocks[numStocks].quantity) {
            numStocks++;
        }
        stocksFile.close();
    }

    ifstream salesFile(SALES_FILE);
    if (salesFile.is_open()) {
        while (numSales < MAX_RECORDS && salesFile >> sales[numSales].invoiceNo >>
            sales[numSales].dateTime >> sales[numSales].customerName >>
            sales[numSales].noOfItems >> sales[numSales].totalAmount) {
            numSales++;
        }
        salesFile.close();
    }

    ifstream purchasesFile(PURCHASE_FILE);
    if (purchasesFile.is_open()) {
        while (numPurchases < MAX_RECORDS && purchasesFile >> purchases[numPurchases].invoiceNo >>
            purchases[numPurchases].supplierName >> purchases[numPurchases].productName >>
            purchases[numPurchases].productType >> purchases[numPurchases].manufacturerName >>
            purchases[numPurchases].retailPrice >> purchases[numPurchases].costPrice >>
            purchases[numPurchases].unitsPurchased) {
            numPurchases++;
        }
        purchasesFile.close();
    }

    // Display menu and get user inputAC
    int choice = -1;
    while (choice != 7) {
        cout << "Menu:\n" <<
            "1. Add a new stock record\n" <<
            "2. Print existing stock record\n" <<
            "3. Record a sale\n" <<
            "4. Print sales\n" <<
            "5. Record a purchase\n" <<
            "6. Print purchases\n" <<
            "7. exit\n" <<
            "Enter your choice (1-7): ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1: {
            // Add a new stock record
            if (numStocks >= MAX_RECORDS) {
                cout << "Error: maximum number of records reached.\n";
                break;
            }
            string code, name, type, manufacturer;
            double price, discount;
            int quantity;
            cout << "Enter code: ";
            cin >> code;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter type: ";
            cin >> type;
            cout << "Enter manufacturer: ";
            cin >> manufacturer;
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter discount: ";
            cin >> discount;
            cout << "Enter quantity: ";
            cin >> quantity;
            stocks[numStocks++] = StockRecord(code, name, type, manufacturer, price, discount, quantity);
            writeStocksToFile(stocks, numStocks, STOCKS_FILE);
            cout << "\nBack to Main Menu\n";
            choice = -1;
            break;
        }

        case 2: {
            // Print existing stock record
            if (numStocks == 0) {
                cout << "Error: no records found.\n";
                break;
            }
            for (int i = 0; i < numStocks; i++) {
                stocks[i].display();
            }
            choice = -1;
            break;
        }

        case 3: {
            for (int i = 0; i < numStocks; i++) {
                stocks[i].display();
            }
            cout << "\nWhat you want to buy?";
            cout << " \nEnter Product Code: ";
            int productCode = 0;
            cin >> productCode;
            
                string invoiceNo;
                string dateTime;
                string customerName;
                int noOfItems;
                double totalAmount;
                cout << "Enter invoiceNo: ";
                cin >> invoiceNo;
                cout << "Enter date/time: ";
                cin >> dateTime;
                cout << "Enter customer name: ";
                cin >> customerName;
                cout << "Enter number of items: ";
                cin >> noOfItems;
                cout << "Enter total amount: ";
                cin >> totalAmount;
                sales[numSales++] = SalesRecord(invoiceNo, dateTime, customerName, noOfItems, totalAmount);
                writeSalesRecordsToFile(sales, numSales, SALES_FILE);
                cout << "\nBack to Main Menu\n";
                choice = -1;
            
            break;
        }
        case 4: {
            for (int i = 0; i < numSales; i++) {
                sales[i].display();
            }
            choice = -1;
            break;
        }
        case 5: {
            cout << "Enter Purchasing Data\n";
            string invoiceNo;
            string supplierName;
            string productName;
            string productType;
            string manufacturerName;
            double retailPrice;
            double costPrice;
            int unitsPurchased;
            cout << "Enter invoice:";
            cin >> invoiceNo;
            cout << "Enter supplier:";
            cin >> supplierName;
            cout << "Enter product:";
            cin >> productName;
            cout << "Enter product type:";
            cin >> productType;
            cout << "Enter manufacturer:";
            cin >> manufacturerName;
            cout << "Enter retail price:";
            cin >> retailPrice;
            cout << "Enter cost price:";
            cin >> costPrice;
            cout << "Enter units purchased:";
            cin >> unitsPurchased;
            purchases[numPurchases++] = PurchaseRecord(invoiceNo, supplierName, productName, productType, manufacturerName, retailPrice, costPrice, unitsPurchased);
            writePurchaseRecordsToFile(purchases, numPurchases, PURCHASE_FILE);
            cout << "Back to Main Menu\n";
            choice = -1;
            break;
        }
        case 6: {
            for (int i = 0; i < numPurchases; i++) {
                purchases[i].display();
            }
            choice = -1;
            break;
        }
        case 7:
            break;
        default: {
            cout << "\nError: invalid choice.\n";
            break;
        }
        }
    }

    cout << "\n ------------ Muhammad Moiz : 221073 ----------------\n";

    return 0;
}

void writeStocksToFile(const StockRecord stocks[], int numStocks,
    const string fileName) {
    ofstream outFile(fileName);
    if (outFile.is_open()) {
        for (int i = 0; i < numStocks; i++) {
            outFile << stocks[i].code << " " << stocks[i].name << " " << stocks[i].type << " " <<
                stocks[i].manufacturer << " " << stocks[i].price << " " << stocks[i].discount << " " <<
                stocks[i].quantity << endl;
        }
        outFile.close();
        cout << "Stock records saved to file." << endl;
    } else {
        cout << "Error opening file." << endl;
    }
}

void writeSalesRecordsToFile(const SalesRecord sales[], int numSales,
    const string fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
        for (int i = 0; i < numSales; i++) {
            file << sales[i].invoiceNo << " " << sales[i].dateTime << " " << sales[i].customerName << " " <<
                sales[i].noOfItems << " " << sales[i].totalAmount << endl;
        }
        file.close();
        cout << "Sales records saved to file." << endl;
    } else {
        cout << "Error opening file." << endl;
    }
}

void writePurchaseRecordsToFile(const PurchaseRecord purchase[], int numPurchase,
    const string fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
        for (int i = 0; i < numPurchase; i++) {
            file << purchase[i].invoiceNo << " " << purchase[i].supplierName << " " <<
                purchase[i].productName << " " << purchase[i].productType << " " <<
                purchase[i].manufacturerName << " " << purchase[i].retailPrice << " " <<
                purchase[i].costPrice << " " << purchase[i].unitsPurchased << endl;
        }
        file.close();
        cout << "Purchase records saved to file." << endl;
    } else {
        cout << "Error opening file." << endl;
    }
}
