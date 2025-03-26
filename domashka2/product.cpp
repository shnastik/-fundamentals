#include "libproduct.h"
#include <iostream>

class Warehouse {
public:
    Product *products;
    int index;
    char id[4];
    enum TYPE { CENTRE = 1, WEST, EAST };
    double longitude;
    double latitude;
    int capacity;
    int size;

public:
    Warehouse();
    Warehouse(int n);
    Warehouse(const Warehouse &w);
    ~Warehouse();
    void menu(int &opc);
    void set_size(int n);
    int get_size();
    void insert_product();
    Product get_product(int pos);
    void print_warehouse();
    int search_by_description();
    void update_product();
    void delete_product();
};

Warehouse::Warehouse() : capacity(10), size(0) {
    products = new Product[capacity];
}

Warehouse::Warehouse(int n) : capacity(n), size(0) {
    products = new Product[capacity];
}

Warehouse::Warehouse(const Warehouse &w) {
    capacity = w.capacity;
    size = w.size;
    products = new Product[capacity];
    for (int i = 0; i < size; i++) {
        products[i] = w.products[i];
    }
}

Warehouse::~Warehouse() {
    delete[] products;
}

void Warehouse::insert_product() {
    if (size >= capacity) {
        std::cout << "Warehouse is full. Cannot insert new product." << std::endl;
        return;
    }

    int productCode;
    char description[50];
    double productPrice;
    int productQuantity;
    double productLongitude, productLatitude;

    std::cout << "Enter product code: ";
    std::cin >> productCode;
    std::cout << "Enter product description: ";
    std::cin.ignore();
    std::cin.getline(description, 50);
    std::cout << "Enter product price: ";
    std::cin >> productPrice;
    std::cout << "Enter product quantity: ";
    std::cin >> productQuantity;
    std::cout << "Enter product longitude: ";
    std::cin >> productLongitude;
    std::cout << "Enter product latitude: ";
    std::cin >> productLatitude;

    products[size] = Product(productCode, description, productPrice, productQuantity, productLongitude, productLatitude);
    size++;
}

void Warehouse::print_warehouse() {
    std::cout << "Warehouse Products:" << std::endl;
    for (int i = 0; i < size; i++) {
        products[i].print();
    }
}

int Warehouse::get_size() {
    return size;
}