#include "Samsonov_Aleksey_201-331_Exam.h"// ���������� � ����
#include <iostream>

int num_of_args(std::vector<bool> f)
{
	double fLog = log2(f.size());
	return (int)fLog;
}
vector<bool> read_from_file(string file_name)
{
	char buff[50];
	ifstream in;
	in.open("C:\\������������\\source\\repos\Exam_2020_2021_winter\File.txt");
	in.getline(buff, 50); // ������� ������ �� �����
	in.close(); // ��������� ����
	cout << buff << endl; // ���������� ��� ������
	return 0;
}

bool write_to_file(std::string file_name, vector<bool> f)
{
	ofstream file("in.txt"); // ������ ������ ������ ofstream ��� ������ � ��������� ��� � ������ in.txt
	file << "111001"; // ������ �������� � ����
	file.close(); // ��������� ����
	system("pause");
	return file;
}