#include "Func.h"


int num_of_args(std::vector<bool> f)
{
    return ceil(log2(f.size())); //���� �������� �� ���-�� �������
}

vector<bool> read_from_file(string file_name)
{
    std::vector < bool > result; // ������ ������ ��� ������ ������ � �����
    std::ifstream file(file_name);
    std::copy(std::istream_iterator<bool>(file), std::istream_iterator<bool>(), std::back_inserter(result)); //���������� copy �� �� ����� ���������� �������� � ������
    return result;
}

bool write_to_file(std::string file_name, vector<bool> f)
{
    std::ofstream file(file_name);
    if (file.is_open())
    {
        std::copy(f.begin(), f.end(), std::ostream_iterator<bool>(file)); //���������� copy �� ����� ���������� �������� � ������
        return true;
    }
    else
    {
        return false;
    }
}

std::string table(std::vector<bool> f)
{
    std::string STR; //������ ������ ��� ������ � �� ������� ���������� 

    for (int i = 0; i < f.size(); i++)
    {
        std::bitset<6> bit(i);
        STR = STR + bit.to_string() + "\t" + std::to_string(f[i]) + "\n"; // ����������� ������� 
    }

    return STR;
}




int roman_to_arab(std::string roman_number)
{
    std::map<char, int> romanMap; // ��� �������
    romanMap['I'] = 1;
    romanMap['V'] = 5;
    romanMap['X'] = 10;
    romanMap['L'] = 50;
    romanMap['C'] = 100;
    romanMap['D'] = 500;
    romanMap['M'] = 1000;

    int early = 0; // ���������� 
    int result = 0; // ���������
    for (char c : roman_number)//���������� �� ���� ������
    {
        int ReadNum = romanMap[c];
        if (ReadNum < early) //���� ������ ������ �����������, ������ �� ����������
        {
            result += early;
            early = ReadNum;
        }
        else if (ReadNum > early) // ���� ������ ������ �����������, ������ �� ��������
        {
            if (early == 0) // ���� ���������� ����� ����� ����, ������ � ����� ��� �� ��������� 
                early = ReadNum;
            else //���� ��� �� �� �������� 
            {
                result += ReadNum - early;
                early = 0;
            }
        }
        else if (ReadNum == early) // ���� ������ ����� �����������, �� ���� ����������
        {
            result += early + ReadNum;
            early = 0;
        }
    }
    return result + early;
}


std::vector<int> func_Pascal(int k)
{
    std::vector<int> result;

    for (int i = 0; i <= k; i++)
    {
        result.push_back(fact(k) / (fact(k - i) * fact(i))); //���������� � ������ ������������� ������������ 
    }
    return result;
}

double fact(double num)//���������� ���������� �����
{
    if (num == 0) 
        return 1;
    else 
        return num * fact(num - 1);
}

int func_substr_len(std::string input_str)
{

    int firstChar = 0;
    int result = 0;
    std::set<char> SetSym; // Set � ������� ����� ��������� ��� ������� ��������� 

    for (int i = 0; i < input_str.size(); i++) 
    {
        if (SetSym.find(input_str[i]) == SetSym.end()) // ���� ������ ������� � ���������� ���, �� ��� ��������� 
        {
            SetSym.insert(input_str[i]); // ��������� ������ � set
        }
        else 
        {
            if (SetSym.size() > result) // ���� ������ ��������� ������ ������� ����������
            {
                result = SetSym.size(); //�������� �������� �� ������������
            }
            SetSym.clear(); // ������� set
            firstChar++; // ��������� ������ ������� �� ��������
            i = firstChar; // �������� �����, �� ����������� �������(��) ��������
        }
    }
    if (result == 0)
        result = SetSym.size();
    return result;
}



