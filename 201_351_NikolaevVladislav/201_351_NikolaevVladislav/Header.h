#pragma once
#include <iostream>
#include <vector>//���������� ������� ��� ������ � ����
#include <string>//���������� ������ ��� ������ � ����
#include <fstream>//���������� ���������� ��������� ����� � ������
#include <bitset>//��������� ��� ������ � ��������� � �������� ������������� �����, ���� ����� �� ������������, �� �� � �������
//�� ����� ������ �� �����, �� ������� �� ����, ��� ��� ���� �� ��� ����� ��������� ����� ���� �� ������ ����� ������ ����� ��������
//������ ��� �������� ���������
using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::endl;
using std::ifstream;
using std::ofstream;
///part 1
int num_of_args(std::vector<bool> f);
std::vector<bool> read_from_file(std::string file_name);
bool write_to_file(std::string file_name, std::vector<bool> f);
std::string table(std::vector<bool> f);

//////part 2
std::vector<int> func_Pascal(int n);
int roman_to_arab(std::string roman_number);
int func_substr_len(std::string input_str);
void update_status(bool* mas);