#include "BolleanFunc.h"

int num_of_args(std::vector<bool> f)
{
	return ceil(log2(f.size())); //���������� � ������� ��������� � ���������� 2
}

std::vector<bool> read_from_file(std::string file_name)
{
	std::string bufLine;
	std::vector<bool> resultVector;

	std::ifstream inputStream(file_name);
	if (inputStream.is_open())
	{
		while (std::getline(inputStream, bufLine))
		{
			for (int i = 0; i < bufLine.size(); i++) //���������� ���������� �� ����� ������
			{
				if (bufLine[i] == '0') resultVector.push_back(false);
				else resultVector.push_back(true);
			}
		}
	}

	return resultVector;
}

bool write_to_file(std::string file_name, std::vector<bool> f)
{
	std::ofstream outputStream(file_name, std::ios::out);
	if (outputStream.is_open())
	{
		for (auto i : f)
		{
			outputStream << i; //��������� ����� ������ ����� ������ � ����
		}
		return true;
	}
	else
	{
		return false;
	}
}

std::string table(std::vector<bool> f)
{
	std::string bufStr;
	for (int i = 0; i < f.size(); i++)
	{
		std::bitset<8> bit(i); //����������� int � ������� �������������
		bufStr = bufStr + bit.to_string() + "\t" + std::to_string(f[i]) + "\n";
	}

	return bufStr;
}

int roman_to_arab(std::string roman_number)
{
	std::map<char, int> romanMap;
	romanMap['I'] = 1;
	romanMap['V'] = 5;
	romanMap['X'] = 10;
	romanMap['L'] = 50;
	romanMap['C'] = 100;
	romanMap['D'] = 500;
	romanMap['M'] = 1000; //������� �� ������� � �������� ����

	int prevNum = 0;
	int result = 0;
	for (char c : roman_number) //���������� ��� ������� � ������� ������
	{
		int currentNum = romanMap[c]; //���������� ������� ����� �� �������
		if (currentNum < prevNum) //���� ������� ������ ������ �����������, ������ �� ��� � ������� ������� � ������ �������
		{
			result += prevNum;
			prevNum = currentNum;
		}
		else if (currentNum > prevNum) //���� �������� ������
		{
			if (prevNum == 0) //� ���� ���������� ����� 0 ������ �� ������ ������ ����������
				prevNum = currentNum;
			else //���� ���, ������ � ��� �������� �������� "IV" � ���� ��������
			{
				result += currentNum - prevNum;
				prevNum = 0;
			}
		}
		else if (currentNum == prevNum) //���� ������� � ���������� �����, ������ ����������
		{
			result += prevNum + currentNum;
			prevNum = 0;
		}
	}

	return result + prevNum;
}

std::vector<int> func_Pascal(int k)
{
	std::vector<int> result;

	for (int i = 0; i <= k; i++)
	{ //������� ��� ���������� ��������� ������ � ������������ �������:
		result.push_back(fact(k) / (fact((double)k - i) * fact(i)));
	} //n! / m! * (n-m)!

	return result;
}

double fact(double num) //������� ������������ ���������� ����������
{
	if (num == 0) return 1;
	else return num * fact(num - 1);
}

int func_substr_len(std::string input_str)
{
	int firstChar = 0;
	int result = 0;
	std::set<char> charSet; //������ set � ������� ����� ��������� ��� ������� ���������

	for (int i = 0; i < input_str.size(); i++) //���������� ������
	{
		if (charSet.find(input_str[i]) == charSet.end()) //���� ������� ���, ������ ��������� 
		{
			charSet.insert(input_str[i]);
		}
		else //���� �� ����, ��
		{
			if (charSet.size() > result) //���� ������ ��������� ������ ������� ����������
			{
				result = charSet.size(); //���������� ����� ��������
			}
			charSet.clear();
			firstChar++;
			i = firstChar; //������� set � �������� ���������� ������ �� ���������� ��������
		}
	}

	if (result == 0) result = charSet.size(); //���� set ������ �� ���������

	return result;
}