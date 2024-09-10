#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

class invalid_progression : public std::invalid_argument { // Класс некорректная прогрессия, наследуемый от стандартного класса ошибок
private:
	double first_element;
	double denominator;
	double* massive;
	size_t size;
public:
	invalid_progression(const std::string message, double first_element,double denominator, double* massive, size_t size);
	void print() const;
};
class geometric_progression { // Класс создание прогрессии
private:
	double first_element;
	double denominator;
	double* massive;
	size_t size;
public:
	geometric_progression(double first_element,double denominator,  double* massive, size_t size); // Конструктор
	~geometric_progression(); // Деструктор
	void print_progress() const; // Вывод
};
