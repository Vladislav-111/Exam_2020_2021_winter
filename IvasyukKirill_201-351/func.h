#pragma once
#include <iostream>//��� ����� ������
#include <bitset> //��������� ��� �������, ������� ������ ������������������, ��������� �� �������������� ����� �����
#include <fstream> // ��� ������ � �������
#include <vector> // ��� �������� �������
#include <cmath> // ��� ������� pow
#include <string> // ��� ������ �� ��������
#include <map> // ��������������� ������������� ���������    
#include <set> //��� �������� �������� � ����������

using namespace std;


int num_of_args(vector<bool> f);
vector<bool> read_from_file(string file_name);
bool write_to_file(string file_name, vector<bool> f);
string table(vector<bool> f);
string func_sdnf(vector<bool> f);
int roman_to_arab(std::string roman_number);
vector<int> func_Pascal(int k);
double fact(double num);
int func_substr_len(std::string input_str);