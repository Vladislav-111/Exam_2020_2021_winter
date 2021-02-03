#include "ekz.h"      // ������������ ���� h � ��������� 
#include <fstream>    // ���������� ��� ������ � fstream
#include <iostream>   // ���� �����
#include <map>        // ���������� ��� ������ � map
#include <unordered_set>

int roman_to_arab(std::string roman_number)          //��� �������� �������
{
	int result = 0;
	for (int i = 0; i < roman_number.length(); i++)
	{
		if (roman_number[i] == 'M')                     //������ � ��������
			result += 1000;
		if (roman_number[i] == 'C' && roman_number[i + 1] == 'M')       //���� ����� � ���� �
		{
			result += 900;
			i++;
		}
		if (roman_number[i] == 'D')                                   //������ � ������� 500
			result += 500;
		if (roman_number[i] == 'C' && roman_number[i + 1] == 'D')           //������ � ������� �� 400 � �� 200
		{
			result += 400;
			i++;
		}
		if (roman_number[i] == 'C')                                     //������ � ������� 100
			result += 100;
		if (roman_number[i] == 'X' && roman_number[i + 1] == 'C')         //������ � 90 � �� 60
		{
			result += 90;
			i++;
		}
		if (roman_number[i] == 'L')                                         //������ � 50
			result += 50;
		if (roman_number[i] == 'X' && roman_number[i + 1] == 'L')         //������ � 40 �� 20
		{
			result += 40;
			i++;
		}
		if (roman_number[i] == 'X')                                       //������ � ���������
			result += 10;
		if (roman_number[i] == 'I' && roman_number[i + 1] == 'X')
		{
			result += 9;
			i++;
		}
		if (roman_number[i] == 'V')                                       //�������
			result += 5;
		if (roman_number[i] == 'I' && roman_number[i + 1] == 'V')
		{
			result += 4;
			i++;
		}
		if (roman_number[i] == 'I')                                        //��������
			result += 1;
	}
	return result;
}
int func(string input_string) {         //������� 3 
	unordered_set<int> u;
	int counter;
	int max = 0;
	for (size_t i = 0; i < input_string.length(); i++) {
		counter = 0;
		size_t j = i + 1;
		u.clear();
		while (true) {
			if (j < input_string.length() and u.find(input_string[j]) == u.end()) {
				u.insert(input_string[j]);
				counter++;
				j++;
			}
			else {
				if (counter > max) {
					max = counter;
				}
				break;
			}
		}
	}
	return max;
}
int C(int m, int n)           //����������� ������� (���� ����������� ������� n!/(k!(n-k)!) ) (�� ����� ��������)
{
	int fact_n = 1;
	int fact_m = 1;
	int fact_n_m = 1;
	for (int i = 1; i <= n; i++){
		fact_n *= i;
	}
	for (int i = 1; i <= m; i++){
		fact_m *= i;
	}
	for (int i = 1; i <= (n - m); i++){
		fact_n_m *= i;
	}
	return fact_n / (fact_m * fact_n_m);
}

std::vector <int> func_Pascal(int k)       //������� 2 ����������� �������
{
	std::vector <int> result;
	for (int i = 0; i < k + 1; i++)
	{
		result.push_back(C(i, k));         //c �����
	}
	for (int i = 0; i < result.size(); i++) 
	{
		std::cout << result[i];
	}
	return result;
}