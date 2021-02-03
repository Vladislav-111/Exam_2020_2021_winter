#pragma once
#include <vector> //�� �������
#include <cmath> //���������� ��� ���������
#include <string> //������
#include <fstream> //������-������ � ����
#include <bitset> //������ � ������ ��� ������� ���������
#include <map> //��� �������� ������ ���� � �� �������� � ��������
#include <set> //��� ������� �� ����� ���������

int num_of_args(std::vector<bool> f);

std::vector<bool> read_from_file(std::string file_name);

bool write_to_file(std::string file_name, std::vector<bool> f);

std::string table(std::vector<bool> f);

//������ �����

int roman_to_arab(std::string roman_number);

std::vector<int> func_Pascal(int k);
double fact(double num);

int func_substr_len(std::string input_str);