#include <iostream>
#include <cstring>
#include <iomanip>
#include "libwarehouse.h"

using namespace std;

Warehouse::Warehouse() {    
    this->index = 0;
    this->list = new Product[this->size]; }
Warehouse::~Warehouse() {
    delete[] this->list;
}

void Warehouse::menu(int &opc) {
    cout << left;
    cout << "--------------------" << endl;
    cout << "MENU OF PRODUCTS" << endl;
    cout << "--------------------" << endl;
    cout << "[1]. Insert product" << endl;
    cout << "[2]. Print list of products" << endl;
    cout << "[3]. Search product by description" << endl;
    cout << "[4]. Update product" << endl;
    cout << "[5]. Delete product" << endl;
    cout << "[6]. Exit" << endl;
    cout << "---------------------------------" << endl;
    cout << "Enter option: "; 
    cin >> opc;
}
Warehouse::Warehouse(int n) {
    this->max_capacity = n; 
    this->list = new Product[n]; 
    this->index = 0; }

Warehouse::~Warehouse() {
    delete[] this->list; 
}

void Warehouse::insert_product() {
    cout << "Insert new product..." << endl;

  
    if (this->index >= this->size) {
        cout << "Warehouse is full. Cannot insert new product." << endl;
        return;
    }

    cout << "Description: "; 
    cin >> this->list[this->index].descr; 

    this->index++; 
}