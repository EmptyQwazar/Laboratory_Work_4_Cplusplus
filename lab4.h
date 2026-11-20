#ifndef LAB4_H_
#define LAB4_H_

#include <iostream>

int readInt();

class Time {
private:
    int hours_ = 0;
    int minutes_ = 0;

    void normalized(int hours, int minutes);

public:
    // Конструкторы (не менее трех: по умолчанию, с параметрами, копирования)
    Time();
    Time(int hours, int minutes);
    Time(const Time& other);

    // Свойства (геттеры и сеттеры)
    int getHours() const;
    int getMinutes() const;
    void setHours(int hours);
    void setMinutes(int minutes);

    // Метод добавления произвольного количества минут (возвращает новый Time)
    Time addMinutes(unsigned int minutes) const;

    // Унарные операторы (++ и -- для минут)
    Time& operator++();
    Time operator++(int);
    Time& operator--();
    Time operator--(int);

    // Бинарные операторы (+ и - с количеством минут)
    Time operator+(unsigned int minutes) const;
    Time operator-(unsigned int minutes) const;

    // Операторы приведения типа
    explicit operator short int() const;
    operator bool() const;

    // Вывод на экран
    void getInfo() const;
};

void Task1();
void Task2();

#endif