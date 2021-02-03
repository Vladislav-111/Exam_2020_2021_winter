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
	ofstream file;
	file.open(file_name, ofstream::out);
	if (file.is_open() == true) {//��������� �������� �� ����
		file << endl << "";
		for (int i = 0; i < f.size(); i++) {
			file << f[i];
		}
		//��������� ����
		file.close();
		return true;
	}
	else {
		return false;
	}

}

string table(vector<bool> f)
{

	return string();
}

