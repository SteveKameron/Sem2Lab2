#include "Header1.h"
#include <iostream>
#include <vector>
#include <fstream>

int Massiv::Get_Size() {
	return Size;
}

Massiv::Massiv(int n) {
	this->Size = n;
	this->data = new int[n];
	for (int i = 0; i < n; i++) {
		data[i] = i;
	}
}

Massiv::Massiv(int* data_new, int n) {
	data = new int[n];
	for (int i = 0; i < n; i++) {
		data[i] = data_new[i];
	}
	Size = n;
}

Massiv::Massiv() {
	this->Size = 0;
	this->data = nullptr;
}

Massiv::Massiv(const Massiv& Another_Massiv) {
	this->Size = Another_Massiv.Size;
	this->data = new int[Another_Massiv.Size];
	for (int i = 0; i < Another_Massiv.Size; i++) {
		this->data[i] = Another_Massiv.data[i];
	}
}

Massiv Massiv::operator ++(int value) {
	Massiv mas = *this;
	for (int i = 0; i < Size; i++) {
		data[i]++;
	}
	return mas;
}

Massiv::Massiv(Massiv&& Moved_Massiv) {
	data = Moved_Massiv.data;
	Size = Moved_Massiv.Size;
	Moved_Massiv.data = nullptr;
	Moved_Massiv.Size = 0;
	//HERE
}

Massiv& Massiv::operator = (const Massiv& Another_Massiv) {
	//memory leak
	if (this->data != Another_Massiv.data) {
		if (this->data != nullptr) {
			delete[] data;
		}
		Size = Another_Massiv.Size;
		data = new int[Size];
		for (int i = 0; i < Size; i++) {
			data[i] = Another_Massiv.data[i];
		}
		return *this;
	}
	else {
		return *this;
	}

}

Massiv& Massiv::operator = (Massiv&& Moved_Massiv) {
	if (this->data != Moved_Massiv.data) {
		if (this->data != nullptr) {
			delete[] data;
		}
		data = Moved_Massiv.data;
		Size = Moved_Massiv.Size;
		Moved_Massiv.data = nullptr;
		Moved_Massiv.Size = 0;
	}
	else {
		std::cout << "HERE 1\n";

	}
	return *this;
}

void Massiv::Print() {
	for (int i = 0; i < Size; i++) {
		std::cout << data[i] << std::endl;
	}
}

int  Massiv::operator[] (int index) {
	return data[index];
}

void Massiv::Print_To_File() {
	std::ofstream file("output.txt");
	for (int i = 0; i < Size; i++) {
		file << data[i] << '\n';
	}
}

Massiv::~Massiv() {
	if (data != nullptr) {
		delete[] data;
	}
	std::cout << "Destructor\n";
}


std::ostream& operator<<(std::ostream& Output, Massiv& Another_Massiv) {
	Output << Another_Massiv.Get_Size() << std::endl;
	for (int i = 0; i < Another_Massiv.Get_Size(); i++) {
		Output << Another_Massiv[i] << ' ';
	}
	Output << std::endl;
	return Output;
}

std::istream& operator>>(std::istream& Input, Massiv& Another_Massiv) {
	int Size_New;
	Input >> Size_New;
	int* New_Array = new int[Size_New];
	for (int i = 0; i < Size_New; i++) {
		Input >> New_Array[i];
	}
	Another_Massiv = Massiv(New_Array, Size_New);
	if (New_Array != nullptr) {
		delete[] New_Array;
	}
	return Input;
}