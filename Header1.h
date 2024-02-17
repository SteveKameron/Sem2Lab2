#include <iostream>
#include <vector>

class Massiv {
private:
	int Size;
public:
	int* data;

	int Get_Size();
	Massiv(int n);
	Massiv(int* data_new, int n);
	Massiv();
	Massiv(const Massiv& Another_Massiv);
	Massiv operator ++(int value);
	Massiv(Massiv&& Moved_Massiv);
	Massiv& operator = (const Massiv& Another_Massiv);
	Massiv& operator = (Massiv&& Moved_Massiv);
	void Print();
	void Print_To_File();
	int operator[] (int index);
	~Massiv();
};

std::ostream& operator<<(std::ostream& Output, Massiv& Another_Massiv);

std::istream& operator>>(std::istream& Input, Massiv& Another_Massiv);
