#include <iostream>              // c���� � �����
#include <vector>               // ������ � ���������
#include <string>              // ������ � �-��������    
#include "func.h"              // �������� ����� ������� �� h �����
using namespace std;

const string file = { "D:\\file.txt" };   // ������������ �����1
const string file2 = { "D:\\file2.txt" }; // ������������ �����2
vector<bool> f;                          // ������ �� ���������
int main()
{
	setlocale(0, " ");
	f = read_from_file(file);
	bool tr = write_to_file(file2, f);
	int a = num_of_args(f);
	cout << "1 �������: " << a << endl;
	cout << "2 �������: " tr;
}
