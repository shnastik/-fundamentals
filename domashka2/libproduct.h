#pragma once

class Product {
public:
    int productCode;          
    char description[50];    
    double productPrice;      
    int productQuantity;      
    double productLongitude;   
    double productLatitude;   

public:
    Product();
    Product(int productCode, char description[50], double productPrice, int productQuantity, double productLongitude, double productLatitude);
    Product(const Product &p);
    ~Product();
    void print();
    void set_all(int productCode, char description[50], double productPrice, int productQuantity, double productLongitude, double productLatitude);
    void get_all(int &productCode, char description[50], double &productPrice, int &productQuantity, double &productLongitude, double &productLatitude);
};