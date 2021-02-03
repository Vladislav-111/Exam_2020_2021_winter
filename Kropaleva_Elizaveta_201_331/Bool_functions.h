#pragma once
#include <vector> // ���������� ��� ������ � vector
#include <string> // ���������� ��� ������ � string


using namespace std;

int num_of_args(vector<bool> f);

vector<bool> read_from_file(std::string file_name);

bool write_to_file(std::string file_name, vector<bool> f);

std::string table(vector<bool> f);

int roman_to_arab(std::string roman_number);

std::vector<int> func_Pascal(int k);

int func_substr_len(std::string input_str);