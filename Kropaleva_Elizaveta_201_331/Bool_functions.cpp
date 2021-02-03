#include "Bool_functions.h"
#include <fstream> //���������� ��� ������ � fstream
#include <bitset> //���������� ��� ������ � �������� ��������������
#include <set> //���������� ��� ������ � set

struct num {
	char roman;
	int arab;
};

/* �� ��������� ������� �������� f ������� ������� ���������� ���������� ���������� n ���� �������. ����� ������� f ���� pow(2,n). */
int num_of_args(vector<bool> f) {
	int size = f.size(), n = 0; // size - ����� ������� �������, n - ���������� ���������� �������
	while (size > 1) { //����, ������������ ������� 2 �����
		size /= 2;
		n++;
	}
	return n;
}

/* �� ��������� ������������ � ����� ����� file_name ������� ������ �������� ������� ������� vector<bool>*/
vector<bool> read_from_file(std::string file_name)
{
	vector <bool> f;
	fstream fs;  //�������� ������� ��� ������ � �++
	string str;
	fs.open(file_name, std::fstream::in);  //�������� �����, �����: �� ������ 
	getline(fs, str); // ���������� ������ � ��������

	for (int i = 0; i < str.length(); i += 2) {
		if (str[i] == '1') f.push_back(1);
		else f.push_back(0);
	}

	fs.close();
	return f;
}

/*�������� �������� ������ �������� f ������� ������� � ����, ��������� ������������� � �������� ����� file_name. ������� true ��� �������� ������.*/
bool write_to_file(std::string file_name, vector<bool> f) {
	fstream fs;  //�������� ������� ��� ������ � �++
	fs.open(file_name, std::fstream::out);  //�������� �����, �����: �� ������
	if (fs.fail()) return false;

	for (int i = 0; i < f.size(); i++) fs << f[i] << " ";

	fs.close();

	return true;
}

/* �� ��������� ������� �������� f ������� ������� ������� ������, � ������� �������� ������� ���������� ���� ������� �������. */
std::string table(vector<bool> f) {
	string table = "", str, str_1;
	int num_args = num_of_args(f);
	for (int i = 0; i < num_args; i++) table = table + "x" + char(i + 49) + "\t"; // ����� �������
	table += "f \n";
	if (num_args == 2) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <2> b(i); // �������� ����������
			str_1 = b.to_string();
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // ���������� ����������� ����� ����������
			table = table + str + char(f[i] + 48) + "\n"; // ������������ ������ ������� � ������ �������� ������� �� ������ ������
		}
	} 
	else if (num_args == 3) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <3> b(i); // �������� ����������
			str_1 = b.to_string(); 
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // ���������� ����������� ����� ����������
			table = table + str + char(f[i] + 48) + "\n"; // ������������ ������ ������� � ������ �������� ������� �� ������ ������
		}
	}
	else if (num_args == 4) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <4> b(i); // �������� ����������
			str_1 = b.to_string();
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // ���������� ����������� ����� ����������
			table = table + str + char(f[i] + 48) + "\n"; // ������������ ������ ������� � ������ �������� ������� �� ������ ������
		}
	}
	else if (num_args == 5) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <5> b(i); // �������� ����������
			str_1 = b.to_string();
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // ���������� ����������� ����� ����������
			table = table + str + char(f[i] + 48) + "\n"; // ������������ ������ ������� � ������ �������� ������� �� ������ ������
		}
	}
	else if (num_args == 6) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <6> b(i); // �������� ����������
			str_1 = b.to_string();
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // ���������� ����������� ����� ����������
			table = table + str + char(f[i] + 48) + "\n"; // ������������ ������ ������� � ������ �������� ������� �� ������ ������
		}
	}
	else if (num_args == 7) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <7> b(i); // �������� ����������
			str_1 = b.to_string(); 
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // ���������� ����������� ����� ����������
			table = table + str + char(f[i] + 48) + "\n"; // ������������ ������ ������� � ������ �������� ������� �� ������ ������
		}
	}
	else if (num_args == 9) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <8> b(i); // �������� ����������
			str_1 = b.to_string();
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // ���������� ����������� ����� ����������
			table = table + str + char(f[i] + 48) + "\n"; // ������������ ������ ������� � ������ �������� ������� �� ������ ������
		}
	}
	else if (num_args == 10) {
		for (int i = 0; i < f.size(); i++) {
			str = ""; 
			bitset <9> b(i); // �������� ����������
			str_1 = b.to_string();
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // ���������� ����������� ����� ����������
			table = table + str + char(f[i] + 48) + "\n"; // ������������ ������ ������� � ������ �������� ������� �� ������ ������
		}
	}
	return table;
}

/*������ � ������� database ��� �������� ��������*/
int index_database(char roman_number) {
	vector <num> database = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
	for (int j = 0; j < 7; j++) 
		if (roman_number == database[j].roman) return j;
}

/*�� ������� ������ �������� ������� �����, �� ����������� ���� �����. ���������� ������� �������� ��� � ��������.*/
int roman_to_arab(std::string roman_number) {
	int arab_number = 0;
	vector <num> database = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} }; // ������ �� ���������� ��� �������� 
	for (int i = 0; i < roman_number.length(); i++) {
			int cur_index = index_database(roman_number[i]); // ������ � ������� database ��� �������� ��������
			if (i < roman_number.length() - 1 && database[cur_index].arab < database[index_database(roman_number[i + 1])].arab) arab_number -= database[cur_index].arab; 
			else arab_number += database[cur_index].arab;
	}

	return arab_number;
}

/*����������� �������*/
std::vector<int> func_Pascal(int k) {
	vector <int> rez(k + 1, 0); //������ ����� k, ����������� 0
	rez[0] = 1;
	for (int i = 1; i <= k; i++)
		for (int j = i; j >= 1; j--)
			rez[j] = rez[j - 1] + rez[j]; // ����� 2 ����� ��� ������� ������
	
	return rez;
};

/* �� �������� ������ input_str ������� �����, ������ ������� ����� ������� ���������, ������� �� �������� ������������� ��������.*/
int func_substr_len(std::string input_str) {
	set<char> letter; // ���������, ������� ������ ���������� �����
	int size_set = 0, max = 0; 
	for (int i = 0; i < input_str.length(); i++) {
		letter.insert(input_str[i]);
		if (letter.size() > size_set)  // �������� �������� �� ����� �������������
			size_set = letter.size();
		else { 
			if (size_set > max) max = size_set;
			size_set = 0;
			letter.clear();
		}
	}
	if (size_set > max) max = size_set; // �������������� ������, ����� ������ ��������� � �����

	return max;
}