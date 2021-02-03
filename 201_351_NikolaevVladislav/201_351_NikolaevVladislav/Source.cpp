#include "Header.h"

//������� �������� ����������, ��� ������ �������� ������� �� ��� ���������� ���� ����������
int num_of_args(vector<bool> f) {
	int num_of_args = 0;
	int size = f.size();
	while (size > 1) {
		size = size / 2;
		num_of_args = num_of_args + 1;
	}
	return num_of_args;

}
//������� ������ �� �����
vector<bool> read_from_file(std::string file_name) {
	vector<bool> f;
	ifstream file(file_name, std::ios::in);//���������� ����� ��� ����� �� �����
	if (!file.is_open()) {//�������� �� ��������
		cout << "try again\n";
	}
	else {
		while (!file.eof()) {//���� �� ������ ��������� �������� � ������� ������ �������� � ������
			bool func_val;
			file >> func_val;
			f.push_back(func_val);

		}

	}
	return f;
}
//������� ������ � ����
bool write_to_file(string file_name, vector<bool> f)
{
	//�������� ������� ������ ��������� ������
	ofstream file;
	file.open(file_name, ofstream::out);//������� � ��������� � ������� ��� ������
	if (file.is_open() == true) {//��������� �������� �� ����
		file << endl << "";
		for (int i = 0; i < f.size(); i++) {
			file << f[i]; //��������� �������� ������� � ����
		}
		//��������� ����
		file.close();
		return true;
	}
	else {
		return false;
	}

}
//������� ������ ������� � ������
string table(vector<bool> f)
{
	string buf;
	int args = num_of_args(f);
	string table;
	int k = 0;
	for (int i = 0; i < f.size(); i++)
	{
		int j = i;
		k = 0;
		do//��������� �� ���������� � �������� 
		{
			buf.append(std::to_string(j % 2));//����������� ������� �� �������
			j /= 2;
			k++;
		} while (j != 0 || k < args);
		reverse(buf.begin(), buf.end());//������������� ������ ����� ������� ��� � �������� �������
		table.append(buf + ' ' + std::to_string(f[i]) + '\n');
		buf.clear();
	}
		
	return  table;

	/*for (int i = 0; i < args; i++) {
		
		table.append(std::to_string(i+1));
	}
	table.push_back('f');
	table.push_back('\n');*/
	
	//for (int i = 0; i < f.size(); i++) {
	//	int x = i;
	//	int bin = 0, k = 1;
	//	while (x)
	//	{
	//		bin += (x % 2) * k;
	//		k *= 10;
	//		x /= 2;
	//	}
	//	if ((bin % 10 >= 0) && (bin % 100 < 10)) {
	//		for (int j = 0; j < args - 1; j++) {
	//			table.append("0");
	//		}
	//		table.append(std::to_string(bin));
	//	}
	//	if ((bin % 1000 < 100) && (bin % 100 >= 10)) {
	//		for (int j = 0; j < args - 2; j++) {
	//			table.append("0");
	//		}
	//		table.append(std::to_string(bin));
	//	}
	//	if ((bin % 10000 <= 1000) && (bin % 1000 >= 100)) {
	//		for (int j = 0; j < args - 3; j++) {
	//			table.append("0");
	//		}
	//		table.append(std::to_string(bin));
	//	}
	//	table.append(std::to_string(f[i]));
	//	table.push_back('\n');
	//}
	/*if (args == 1) {
		for (int i = 0; i < f.size(); i++) {
			std::bitset<1> bin(i);
			table.append(bin.to_string());
			table.push_back(f[i]);
			table.push_back('\n');
		}
	}
	if (args == 2) {
		for (int i = 0; i < f.size(); i++) {
			std::bitset<2> bin(i);
			table.append(bin.to_string());
			string buf = f[i];
			table.append(buf.to_string());
			table.push_back('\n');
		}
	}
	if (args == 3) {
		for (int i = 0; i < f.size(); i++) {
			std::bitset<3> bin(i);
			table.append(bin.to_string());
			table.push_back(f[i]);
			table.push_back('\n');
		}
	}
	if (args == 4) {
		for (int i = 0; i < f.size(); i++) {
			std::bitset<3> bin(i);
			table.append(bin.to_string());
			table.push_back(f[i]);
			table.push_back('\n');
		}
	}
	if (args == 5) {
		for (int i = 0; i < f.size(); i++) {
			std::bitset<5> bin(i);
			table.append(bin.to_string());
			table.push_back(f[i]);
			table.push_back('\n');
		}
	}
	*/
	
}

