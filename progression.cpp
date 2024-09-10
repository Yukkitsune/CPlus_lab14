#include "progression.h"

invalid_progression::invalid_progression(const std::string message,double first_element, double denominator, double* massive, size_t size) : invalid_argument(message) { // Конструктор для вывода ошибок об определенном объекте
	this->first_element = first_element;
	this->denominator = denominator;
	this->massive = massive;
	this->size = size;
}
void invalid_progression::print() const { // Вывод 
	std::cout << "Invalid progression :(" << std::endl;
	std::cout << "First element: " << first_element << std::endl;
	std::cout << "Denominator: " << denominator << std::endl;
	std::cout << "Size: " << size << std::endl;
	for (size_t i = 0; i < size; ++i) {
		std::cout << massive[i] << " ";
	}
	std::cout << std::endl;
}
geometric_progression::geometric_progression(double first_elem, double denom, double* mass, size_t siz) { // Конструктор объекта с поиском ошибок в нём
	first_element = first_elem;
	denominator = denom;
	massive = mass;
	size = siz;
	if (massive[0] != first_element) throw invalid_progression("Invalid first element ",first_element,denominator, massive, size);
	for (size_t i = 0; i < size - 1;++i) {
		if (massive[i+1]/massive[i]!=denominator) throw invalid_progression("Invalid denominator ",first_element,denominator, massive, size);
	}

}
void geometric_progression::print_progress() const { // Вывод в консоль
	std::cout << "Geometric progression: " << std::endl; 
	std::cout << "First element: " << first_element<<std::endl;
	std::cout << "Denominator: " << denominator << std::endl;
	std::cout << "Size: " << size << std::endl;
	for (size_t i = 0; i < size; ++i) {
		std::cout << massive[i] << " ";
	}
	std::cout << std::endl;
}
geometric_progression::~geometric_progression() { // Деструктор
	if (massive != nullptr) {
		delete[] massive;
	}
}
