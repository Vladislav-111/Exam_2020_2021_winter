#include "Class1.h" //����� � ������ .h
#include <string> //���������� ����� ��� ������� ������ �����
#include <fstream> //���������� ������ � ������� ��� ������� 2-3
#include <sstream> //���������� StringStream ��� ������ �� ������� 
#include <bitset> //����������� ���������� bitset ��� ���������� ������� ���������� � ������� 4
#include <map> //����������� ���������� map ��� ������� 8 ��� ������� ����� (��� �������� ��������)
#include <set> //����������� ���������� set ��� ������� 10 ��� ��������� (��� �������� ������)

using std::cout; 
using std::cin;
using std::endl;
using std::vector;

int num_of_args(std::vector<bool> f) //������� ��� ������� 1. 
{
	int num; 
	cout << "������� ������ �������� ������� � ������ �� �����: ";
	while (cin >> num) //���� ��������� ����� �������� ������� �������
		f.push_back(num);
	int answer1; //���������� ������
	answer1 = log(f.size()) / log(2); //���������� ���������� ���������� � ������ �������
	cout << "�����: " << answer1; //�����
	return answer1;
}

vector<bool> read_from_file(std::string file_name) //������� ��� ������� 2. ������ �� �����
{
	std::vector < bool > answer2; //������ ������
	std::ifstream file(file_name); //�������� ���� �� ������
	std::copy(std::istream_iterator<bool>(file), std::istream_iterator<bool>(), std::back_inserter(answer2)); //���������� �������� � ������
	return answer2;
}

bool write_to_file(std::string file_name, vector<bool> f) //������� ��� ������� 3. ������ � ����
{
	std::ofstream file(file_name); //�������� ���� �� ������
	std::copy(f.begin(), f.end(), std::ostream_iterator<bool>(file)); //���������� �������� � ������
	return true;
}

std::string table(std::vector<bool> f) { //������� ��� ������� 4. ���������� ������� ����������
	std::string buf;
	for (int i = 0; i < f.size(); i++)
	{
		std::bitset<4> bit(i);
		buf = buf + bit.to_string() + "\t" + std::to_string(f[i]) + "\n";
	}
	return buf;
}

std::string func_sdnf(std::vector<bool> f) { //������� ��� ������� 5. ���������� ����
	std::ostringstream out;
	int y = num_of_args(f) + 1;
	int n = f.size();
	for (int i = 0; i < n; i++) {
		int r = f.back();
		f.pop_back();
		if (r == 1) {
			int* t = dec2bin(i, y);
			out << "(";
			for (int j = 0; j < y; j++) {
				if (t[j] == 0) {
					if (j + 1 == y) {
						out << "x" << j  << '\'';
					}
					else {
						out << "x" << j <<'\'' << '&';
					}
				}
				if (t[j] == 1) {
					if (j + 1 == y) {
						out << "x" << j;
					}
					else {
						out << "x" << j << '&';
					}
				}
			}
			if (i + 1 == n) {
				out << ")";
			}
			else {
				out << ")v";
			}
		}
	}
	return out.str();
}

std::string func_sknf(std::vector<bool> f) { //������� ��� ������� 6. ���������� ����
	std::ostringstream out;
	int y = num_of_args(f) + 1;
	int n = f.size();
	for (int i = 0; i < n; i++) {
		int r = f.back();// ����� �������� �������
		f.pop_back();
		if (r == 0) {
			int* t = dec2bin(i, y);// ����� � �������� ������
			out << "(";
			for (int j = 0; j < y; j++) {
				if (t[j] == 0) {
					if (j + 1 == y) {
						out << "x" << j << '\'';
					}
					else {
						out << "x" << j << '\'' << 'v';
					}
				}
				if (t[j] == 1) {
					if (j + 1 == y) {
						out << "x";
						out << j;
					}
					else {
						out << "x" << j << 'v';
					}
				}
			}
			if (i == n) {
				out << ")";
			}
			else {
				out << ")&";
			}
		}
	}
	return out.str();
}

int* dec2bin(int num, int size) { //������� �������� �� ���������� ������� � ��������
	int* bin = new int[size] {0};
	int* bin_r = new int[size];
	int j = 0;
	while (num)
	{
		bin[j] = (num % 2);
		num /= 2;
		j++;
	}
	for (int i = 0; i < size; i++) {
		bin_r[size - i - 1] = bin[i];
	}
	return bin_r;
}



//����� 2

double fact(double num) //����������� ����������
{
	if (num == 0) return 1;
	else return num * fact(num - 1);
}

std::vector<int> func_Pascal(int k) //������� ���������� ������ �� ������������ �������. ������ 9
{
	std::vector<int> answer8; //�������� �������
	for (int i = 0; i <= k; i++) //���������� ������������ � ������ � ������� ������� ���������, ���������� �� ������������� �����������
	{
		answer8.push_back(fact(k) / (fact(k - i) * fact(i)));
	}
	for (int i = 0; i <= k; i++) //����� ������
	{
		cout << answer8[i] << " ";
	}
	return answer8;
}

int func_substr_len(std::string input_str) //������� ���������� ������������ ����� ��������� � ����������� ���������. ������� 10
{
	int firstChar = 0;
	int result = 0;
	std::set<char> answer10; //���������� set ��� �������� ������
	for (int i = 0; i < input_str.size(); i++) //���� �������� �������� ������
	{
		if (answer10.find(input_str[i]) == answer10.end()) //���� ������� ���, ������ ��������� � answer10
		{
			answer10.insert(input_str[i]);
		}
		else 
		{
			if (answer10.size() > result) //���� ������ ��������� ������ ������� result
			{
				result = answer10.size(); //����������� ���������� ����� ������
			}
			answer10.clear(); //������� answer10
			firstChar++;
			i = firstChar;
		}
	}
	if (result == 0) result = answer10.size(); //�������� �� ������, ���� ��� ������ �������� ����������
	cout << result; //�����
	return result;
}

int roman_to_arab(std::string roman_number)  //������� �������� �� �������� ����� � ����������. ������� 8
{
	std::map<char, int> romanMap; //�������� ���������� map
	romanMap['I'] = 1; //������������ ������� ������ ��������������� ���������� �����
	romanMap['V'] = 5; 
	romanMap['X'] = 10;
	romanMap['L'] = 50;
	romanMap['C'] = 100;
	romanMap['D'] = 500;
	romanMap['M'] = 1000;
	int last_num = 0; //���������� �����
	int result = 0; //���������
	for (char c : roman_number) //������� ������ � ������� ������ �������������� ������
	{
		int now_num = romanMap[c]; //�������� ��� ������� ����� ����������
		if (now_num < last_num) //���� ������� ������ ������ �����������, ������ �� ��� � ������� ������� � ������ �������
		{
			result += last_num;
			last_num = now_num;
		}
		else if (now_num > last_num) //���� ������� ������ ������ �����������
		{
			if (last_num == 0) //���� ���������� ����� ����� 0, ������ ������� ������ �����
				last_num = now_num;
			else //���� ���, ������ � ��� �������� �� ��� � ������� ������� � �������� �� �������� ����� ����������
			{
				result += now_num - last_num;
				last_num = 0;
			}
		}
		else if (now_num == last_num) //���� ������� � ���������� ����� �����, ������ ������ ���������� � ����
		{
			result += last_num + now_num;
			last_num = 0;
		}
	}
	cout << result + last_num; //�����
	return result + last_num;
}
