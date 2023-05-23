#include <iostream>
#include <fstream>
#include <string>

class Address
{
private:
	std::string city_;
	std::string street_;
	int numHouse_ = 0;
	int apartNum_ = 0;
	char c;
	char s;
public:
	Address(std::string city, std::string street, int numHouse, int apartNum) : city_(city), street_(street), numHouse_(numHouse), apartNum_(apartNum) 
	{
		c = city[0];
		s = street[0];
	}
	std::string get_output_address()
	{
		return (city_ + ", " + street_ + ", " + std::to_string(numHouse_) + ", " + std::to_string(apartNum_) + "\n");
	}
	char get_c() { return c; }
	char get_s() { return s; }
};

void sort(Address** addresses, int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (addresses[i]->get_c() > addresses[j]->get_c()) {
				Address* tmp = addresses[i];
				addresses[i] = addresses[j];
				addresses[j] = tmp;
			}
			if (addresses[i]->get_c() == addresses[j]->get_c())
			if (addresses[i]->get_s() > addresses[j]->get_s()) {
				Address* tmp = addresses[i];
				addresses[i] = addresses[j];
				addresses[j] = tmp;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	std::string s;
	std::string city;
	std::string street;
	int numHouse;
	int apartNum;
	std::ifstream file("in.txt");
	file >> s;
	const int a = stoi(s);
	Address** address = new Address * [a];
	for (int i = 0; i < a; i++)
	{
		file >> city;
		file >> street;
		file >> numHouse;
		file >> apartNum;
		address[i] = new Address(city, street, numHouse, apartNum);
	}
	file.close();
	std::ofstream file_out("out.txt");
	file_out << std::to_string(a) + "\n";
	sort(address,a);
	for (int i = 0 ; i < a; i++)
	{
		file_out << address[i]->get_output_address();
	}
	file_out.close();
	delete[] address;
}