#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int num_of_args(vector<bool> f);
vector<bool> read_from_file(string file_name);
bool write_to_file(std::string file_name, vector<bool> f);
std::string table(vector<bool> f);