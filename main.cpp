#include <clocale>
#include <iostream>
#include "lab4.h"

int main() {
    std::setlocale(LC_ALL, "Russian");

    int choice = -1;
    while (choice != 0) {
        std::cout << std::endl << "=== МЕНЮ ЛАБОРАТОРНОЙ №4 (ВАРИАНТ 1) ===" << std::endl
            << "1. Задание 1 (Класс Time и добавление минут)" << std::endl
            << "2. Задание 2 (Перегрузка операторов)" << std::endl
            << "0. Выход" << std::endl;

        std::cout << "Выбор: ";
        choice = readInt();

        switch (choice) {
        case 1: Task1(); break;
        case 2: Task2(); break;
        case 0: std::cout << "Выход." << std::endl; break;
        default: std::cout << "Неверный пункт." << std::endl; break;
        }
    }

    return 0;
}