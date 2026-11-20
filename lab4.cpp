#include "lab4.h"

int readInt() {
	int val = 0;
	while (!(std::cin >> val)) {
		std::cout << "Ошибка! Введите целое число: ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
	return val;
}

void Time::normalized(int hours, int minutes) {
	int total = hours * 60 + minutes;
	int diff = total % 1440;
	if (diff < 0) {
		diff += 1440;
	}
	hours_ = diff / 60;
	minutes_ = diff % 60;
}

Time::Time() {
	hours_ = 0;
	minutes_ = 0;
}

Time::Time(int hours, int minutes) {
	normalized(hours, minutes);
}

Time::Time(const Time& other) {
	hours_ = other.hours_;
	minutes_ = other.minutes_;
}

int Time::getHours() const {
	return hours_;
}

int Time::getMinutes() const {
	return minutes_;
}

void Time::setHours(int hours) {
	normalized(hours, minutes_);
}

void Time::setMinutes(int minutes) {
	normalized(hours_, minutes);
}

Time Time::addMinutes(unsigned int minutes) const {
	return Time(hours_, minutes_ + static_cast<int>(minutes));
}

Time& Time::operator++() {
	normalized(hours_, minutes_ + 1);
	return *this;
}

Time Time::operator++(int) {
	Time old(*this);
	++(*this);
	return old;
}

Time& Time::operator--() {
	normalized(hours_, minutes_ - 1);
	return *this;
}

Time Time::operator--(int) {
	Time old(*this);
	--(*this);
	return old;
}

Time Time::operator+(unsigned int minutes) const {
	return Time(hours_, minutes_ + static_cast<int>(minutes));
}

Time Time::operator-(unsigned int minutes) const {
	return Time(hours_, minutes_ - static_cast<int>(minutes));
}

Time::operator short int() const {
	return static_cast<short int>(hours_);
}

Time::operator bool() const {
	return hours_ != 0 || minutes_ != 0;
}

void Time::getInfo() const {
	if (hours_ < 10) {
		std::cout << '0';
	}
	std::cout << hours_ << ":";
	if (minutes_ < 10) {
		std::cout << '0';
	}
	std::cout << minutes_;
}

void Task1() {
	std::cout << std::endl << "--- Задание 1 (Класс Time и добавление минут) ---"
		<< std::endl;

	Time tDefault;
	std::cout << "1. Конструктор по умолчанию: ";
	tDefault.getInfo();
	std::cout << std::endl;

	std::cout << "Введите часы: ";
	int h = readInt();
	std::cout << "Введите минуты: ";
	int m = readInt();

	Time tUser(h, m);
	std::cout << "2. Конструктор с параметрами (после нормализации): ";
	tUser.getInfo();
	std::cout << std::endl;

	Time tCopy(tUser);
	std::cout << "3. Конструктор копирования: ";
	tCopy.getInfo();
	std::cout << std::endl;

	int addMins = -1;
	while (addMins < 0) {
		std::cout << "Введите количество минут для добавления (неотрицательное): ";
		addMins = readInt();
	}

	Time tAdded = tUser.addMinutes(static_cast<unsigned int>(addMins));
	std::cout << "Исходное время: ";
	tUser.getInfo();
	std::cout << std::endl;

	std::cout << "Новое время (+ " << addMins << " мин.): ";
	tAdded.getInfo();
	std::cout << std::endl;
}

void Task2() {
	std::cout << std::endl << "Задание 2 (Перегрузка операторов для Time)"
		<< std::endl;

	std::cout << "Введите часы: ";
	int h = readInt();
	std::cout << "Введите минуты: ";
	int m = readInt();

	Time base(h, m);
	std::cout << "Исходное время: ";
	base.getInfo();
	std::cout << std::endl;

	// Префиксный ++t от исходного времени
	Time tPreInc(h, m);
	++tPreInc;
	std::cout << "Префиксный ++t: ";
	tPreInc.getInfo();
	std::cout << std::endl;

	// Постфиксный t++ от исходного времени
	Time tPostInc(h, m);
	Time oldPostInc = tPostInc++;
	std::cout << "Постфиксный t++ (старое): ";
	oldPostInc.getInfo();
	std::cout << ", стало: ";
	tPostInc.getInfo();
	std::cout << std::endl;

	// Префиксный --t от исходного времени
	Time tPreDec(h, m);
	--tPreDec;
	std::cout << "Префиксный --t: ";
	tPreDec.getInfo();
	std::cout << std::endl;

	// Постфиксный t-- от исходного времени
	Time tPostDec(h, m);
	Time oldPostDec = tPostDec--;
	std::cout << "Постфиксный t-- (старое): ";
	oldPostDec.getInfo();
	std::cout << ", стало: ";
	tPostDec.getInfo();
	std::cout << std::endl;

	// Приведение к short int (часы)
	short int onlyHours = static_cast<short int>(base);
	std::cout << "Приведение к short int (часы): " << onlyHours << std::endl;

	// Приведение к bool (true если время не 00:00)
	if (base) {
		std::cout << "Приведение к bool: true (время не равно 00:00)"
			<< std::endl;
	}
	else {
		std::cout << "Приведение к bool: false (время равно 00:00)"
			<< std::endl;
	}

	// Бинарные + и - от исходного времени
	int delta = -1;
	while (delta < 0) {
		std::cout << "Введите количество минут для + и - (неотрицательное): ";
		delta = readInt();
	}
	unsigned int uDelta = static_cast<unsigned int>(delta);

	Time sumRes = base + uDelta;
	std::cout << "Результат (+ " << uDelta << " мин.): ";
	sumRes.getInfo();
	std::cout << std::endl;

	Time diffRes = base - uDelta;
	std::cout << "Результат (- " << uDelta << " мин.): ";
	diffRes.getInfo();
	std::cout << std::endl;
}