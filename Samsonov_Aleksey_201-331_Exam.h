#pragma once
#pragma once
#include <iostream>//���������� ����� ������
#include <string>// ��� ����������� ������� �� ��������
#include <fstream>// ������ � �������
#include <vector>// ��������� ��������� ������

using namespace std;// ����� �� ������ std::
int num_of_args(std::vector<bool> f);
vector<bool> read_from_file(string file_name);
bool write_to_file(string file_name, vector<bool> f);

