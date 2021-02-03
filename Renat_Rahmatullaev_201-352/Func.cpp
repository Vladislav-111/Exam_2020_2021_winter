#include "Func.h"
#include <bitset>//��� ����������� �������


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

std::string func_sdnf(vector<bool> f)
{
  
    return 0;
}


