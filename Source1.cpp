#include "Header1.h"
#include <iostream>
#include <vector>
#include <fstream>

int main() {
	setlocale(LC_ALL, "RU");
	std::ifstream file("input.txt");
	int N;
	file >> N;
	Massiv MyMassiv(N);
	std::cout << std::endl;
	std::cout << "Before ++ " << std::endl;
	std::cout << std::endl;
	MyMassiv.Print();


	MyMassiv++;
	std::cout << std::endl;
	std::cout << "After ++ " << std::endl;
	std::cout << std::endl;
	MyMassiv.Print();
	MyMassiv.Print_To_File();

	return 0;
}