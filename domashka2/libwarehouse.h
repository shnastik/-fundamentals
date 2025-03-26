#pragma once
#include "libproduct.h"

class Warehouse {
public:
    Product *list; // Указатель на массив продуктов
    int index; // Текущий индекс для вставки продукта
    char id[4]; // Идентификатор склада
    enum TYPE { CENTRE = 1, WEST, EAST }; // Перечисление типов склада
    double w_longitude; // Долгота
    double w_latitude; // Широта
    int max_capacity; // Максимальная вместимость
    int total_stock; // Общее количество на складе

public:
    Warehouse(); // Конструктор по умолчанию
    Warehouse(int n); // Конструктор с параметром
    Warehouse(const Warehouse &w); // Конструктор копирования
    ~Warehouse(); // Деструктор
    void menu(int &opc); // Метод для отображения меню
    void set_size(int n); // Метод для установки размера массива
    int get_size(); // Метод для получения размера массива
    void insert_product(); // Метод для вставки продукта
    Product get_product(int pos); // Метод для получения продукта по позиции
    void print_warehouse(); // Метод для печати склада
    int search_by_describe(); // Метод для поиска по описанию
    void update_product(); // Метод для обновления продукта
    void delete_product(); // Метод для удаления продукта
};