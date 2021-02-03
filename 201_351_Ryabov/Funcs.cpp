#include "Funcs.h"

int num_of_args(std::vector<bool> f) //������� �������� ���������� ���������� �������
{
	return std::log(f.size()) / std::log(2);
}

std::vector<bool> read_from_file(std::string file_name) //������� ��� ������ ������� �������� �� �����
{
		std::vector<bool> result;
		std::ifstream file(file_name);
		if (file.is_open()) {
			while (!file.eof()) 
			{
				bool buf;
				file >> buf;
				result.push_back(buf);
			}
		}
		return result;
}

bool write_to_file(std::string file_name, std::vector<bool> f) //������� ������ ������� �������� ������� � ����
{
	std::ofstream output;
	output.open(file_name, std::ofstream::out);
	if (output.is_open()) {
		for (int i = 0; i < f.size(); i++)
		{
			output << f[i];
			if (i != f.size() - 1)
			{
				output << ' ';
			}
		}
		
		return true;
	}
	else 
	{
		return false;
	}
}

std::string table(std::vector<bool> f)		//������� ������ ������� ����������
{
	int cols = num_of_args(f);
	std::string result, buf;
	int counter = 0;
	for (int i = 0; i < f.size(); i++)
	{
		int j = i;
		counter = 0;
		while (j != 0 || counter < cols)
		{
			buf.append(std::to_string(j % 2));
			j /= 2;
			counter++;
		} 
		std::reverse(buf.begin(), buf.end());
		result.append(buf + ' ' + std::to_string(f[i]) + '\n');
		buf.clear();
	}
	return result;
}

std::string func_sdnf(std::vector<bool> f);

std::string func_sknf(std::vector<bool> f);

std::string func_Zhegalkin(std::vector<bool> f);

std::vector<int> func_Pascal(int k) //���������� ��������� ������ � ������������ �������
{
	std::vector<int> result;
	unsigned long benom = 1;
	for (int j = 0; j <= k; j++)
	{
		result.push_back(benom);
		benom *= (k - j);
		benom /= (j + 1);
	}
	return result;
}

int func_substr_len(std::string input_str)		//����������  ����� ������� ��������� �� ���������� ������
{
	int max = 0;
	int counter = 0;
	bool data[26] = { false };

	for (int i = 0; i < input_str.size(); i++)
	{

		if (data[input_str[i] - 97] == false)	//���� ������ ������� ��� �� �����������
		{
			counter++;							//����������� �������
			data[input_str[i] - 97] = true;
		}
		else
		{
			counter = 1;
			std::for_each(data, data + 26, [](bool& b) {b = false; });	//����� �������
			data[input_str[i] - 97] = true;
		}
		if (counter > max)
			max = counter;
	}

	return max;
}

std::string roman_to_arab(std::string roman_number) //������� �������� �� ������� � �������� �����
{
	std::map<char, int> roman_arab =		//�������� ������� ��� �������� �� ������� � ��������
	{
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}
	};
	int result = 0;

	for (int i = 0; i < roman_number.size() - 1; i++)		//�� size-1, ����� �� ����� �� �������
	{
		if (roman_arab[roman_number[i]] < roman_arab[roman_number[i + 1]])
		{
			result -= roman_arab[roman_number[i]];
		}
		else
		{
			result += roman_arab[roman_number[i]];
		}
	}

	result += roman_arab[roman_number[roman_number.size() - 1]]; //���������� ���������, ��� ��� ���� �� size-1
	return std::to_string(result);
}