#include <iostream> //���� �����
#include <vector> //���������� ������ � ���������
#include <string> //���������� ������ �� �������� 
#include <fstream> //���������� ����� � �������
#include "Pavlov_K.h"
using namespace std;

int num_of_args(vector<bool> f)
{
	int n = 0;// ����������� ��������� 
	while (pow(2, n) != f.size())
		n++;
	return  n;
}

vector<bool> read_from_file(string file_name)
{
	ifstream inf(file_name);//��������� ���� ��� ������
	vector <bool> f;
	while (inf)
	{
		bool i;
		inf >> i;//��������� 
		f.push_back(i);//��������� � ������
	}
	inf.close();
	return f;
}

bool write_to_file(string file_name, vector<bool> f)
{
	ofstream outf(file_name);//��������� ���� ��� �����
	int i = 0;
	for (int i = 0; i < f.size(); i++)
		outf << f[i] << ' ';//������ � ����
	outf.close();
	return true;
}