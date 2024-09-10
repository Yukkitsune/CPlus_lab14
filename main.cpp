#include "progression.h"

void fill_massives(std::string& elems, double* array, size_t size) { // Заполнение массивов чисел и операций
    std::string temp_num;
    std::string new_elem = elems + ' ';
    int i = 0;
    int j = 0;
    while (i < new_elem.size()) {
        if (isdigit(new_elem[i])) temp_num += new_elem[i];
        else {
            array[j] = stod(temp_num);
            ++j;
            temp_num = "";
        }
        ++i;
    }
}
void print(double* array, size_t size) {
    for (size_t i = 0; i < size;++i) {
        std::cout << array[i] << " ";
    }
}
int main()
{
    size_t user_size;
    std::string temp; // Строка для парсинга в массив
    std::cout << "Input array size: ";
    std::cin >> user_size;
    double* user_array = new double[user_size];
    std::cout << "Input the array elements separated by a space: ";
    std::cin.ignore();
    std::getline(std::cin, temp);
    fill_massives(temp, user_array, user_size); // Парсим строку для заполнения массива
    std::cout << "Enter the first element of the array: ";
    double user_first_elem;
    std::cin >> user_first_elem;
    std::cout << "Enter the denominator of the array: ";
    std::cin.ignore();
    double user_denominator;
    std::cin >> user_denominator;
    try {
        geometric_progression progress(user_first_elem, user_denominator, user_array, user_size); // Создаём объект класса и ищем ошибки
        progress.print_progress();
    }
    catch (const invalid_progression& inv) {
        std::cerr << "Error: " << inv.what() << std::endl;
        inv.print();
    }
    double invalid[]{ 1,3,9,27 }; // Массив для некорректных примеров
    try {
        geometric_progression invalid_frst(2, 3, invalid, 4);
        invalid_frst.print_progress();
    }
    catch (const invalid_progression& inv) {
        std::cerr << "Error: " << inv.what() << std::endl;
        inv.print();
    }
    try {
        geometric_progression invalid_denominator(1, 5, invalid, 4);
        invalid_denominator.print_progress();
    }
    catch (const invalid_progression& inv) {
        std::cerr << "Error: " << inv.what() << std::endl;
        inv.print();
    }


    return 0;

}
