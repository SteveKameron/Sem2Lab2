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

	int* a = new int[4];
	for (int i = 0; i < 4; i++) {
		a[i] = i;
	}
	Massiv A_a(a, 4);
	Massiv A_b(a, 4);
	A_a = Massiv(a, 4);
	A_a = Massiv(A_a);
	A_a.Print();
	A_a = A_a;
	A_a.Print();
	A_a = A_b;
	Massiv A, B(1), C(2);
	return 0;
}