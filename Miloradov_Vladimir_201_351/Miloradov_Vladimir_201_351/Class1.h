#pragma once
#include <iostream> //���������� �����-������
#include <vector> //���������� ��������

using namespace std;
int num_of_args(std::vector<bool> f); //���������� ������� � ������� 1
vector<bool> read_from_file(std::string file_name); //���������� ������� � ������� 2
bool write_to_file(std::string file_name, vector<bool> f); //���������� ������� � ������� 3
std::string table(std::vector<bool> f); //���������� ������� � ������� 4
std::string func_sdnf(std::vector<bool> f); //���������� ������� � ������� 5
std::string func_sknf(std::vector<bool> f); //���������� ������� � ������� 6
int* dec2bin(int num, int size); //������� �������� �� ���������� ����� � �������� ��� ������� 5 � 6
std::vector<int> func_Pascal(int k); //���������� ������� � ������� 9
double fact(double num); //������� ���������� ���������� ��� ������� 9
int func_substr_len(std::string input_str); //���������� ������� � ������� 10
int roman_to_arab(std::string roman_number); //���������� ������� � ������� 8


