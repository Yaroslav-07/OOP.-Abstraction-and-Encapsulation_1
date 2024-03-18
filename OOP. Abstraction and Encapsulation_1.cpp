#include <iostream>
#include <string>
#include <fstream>

class Address {
private:
    std::string city;
    std::string street;
    int home;
    std::string apartment;

public:
    Address(std::string city, std::string street, int home, std::string apartment) : city(city), street(street), home(home), apartment(apartment) {}

    std::string getOutputAddress() const {
        return city + ", " + street + ", " + std::to_string(home) + ", " + apartment;
    }
};

int main()
{
    std::ifstream inFile("in.txt");
    if (!inFile.is_open()) {
        std::cerr << "Ошибка, файл не был найден" << std::endl;
        return 1;
    }

    int n;
    inFile >> n;
    Address** addressArray = new Address* [n];

    for (int i = 0; i < n; ++i) {
        std::string city, street, apartment;
        int home;
        inFile >> city >> street >> home >> apartment;
        addressArray[i] = new Address(city, street, home, apartment);
    }
    inFile.close();

    std::ofstream outFile("out.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open output file." << std::endl;
        return 1;
    }

    outFile << n << std::endl;
    for (int i = n - 1; i >= 0; --i) {
        outFile << addressArray[i]->getOutputAddress() << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        delete addressArray[i];
    }
    delete[] addressArray;

    outFile.close();

    return 0;
}