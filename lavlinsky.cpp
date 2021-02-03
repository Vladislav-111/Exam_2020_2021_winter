#include <iostream> // ��������� ����� � �������	
#include <locale.h> // ��� ���������
#include <vector> // ���������� �������� 
#include <fstream> // ��� ��������� �����/������
#include <string> // ��� �����
#include <ctime> // ��� �������
using namespace std;

// ����������� ������� ������
int get_power2(int n)
{
	int power = 0;
	while (n % 2 == 0)
	{
		n /= 2;
		power++;
	}

	return power;
}


int num_of_args(vector<bool> v)
{
	int vector_lengh = 0; // ������ �������
	bool temp = 0; // ��������� ����������

	cout << "������� ������ ������� ";
	cin >> vector_lengh;

	for (int i = 0; i < vector_lengh; i++)
	{
		cin >> temp;
		v.push_back(temp); // ������ �������� �� ������������ � ������
	}

	return pow(2, v.size()); // ���������� ������ �������
}

vector<bool> read_from_file(string file_name)
{
	ifstream read_from_file(file_name); // ��������� ���� �� ������������
	vector<bool> reading_vector;
	bool buffer;

	while (read_from_file >> buffer)
	{
		reading_vector.push_back(buffer);
	}

	return reading_vector; // ���������� ������ � �����
}

bool write_to_file(string file_name, vector<bool> f)
{
	file_name += ".txt"; // ������ �����
	ofstream write_to_file;
	write_to_file.open(file_name, ios_base::out); // ����������

	// ��������� ������ ������
	if (write_to_file.fail())
	{
		cout << "������ ��� ������ �����!" << endl;
		return false;
	}
	else
	{
		for (int i : f)
		{
			write_to_file << f[i] << " "; // ������ �� ������ ��������
		}
		return true;
	}

}

string func_sdnf(vector<bool> f)
{
	string func = "";

	int tableSize = f.size(); // ������ �������
	int numBitLength = get_power2(tableSize); // �������� ������� ������

	bool hasAnyFunc = false;

	for (int i = 0; i < tableSize; i++)
	{
		if (f[i]) // ���� 1
		{
			if (i > 0 && hasAnyFunc) func += " v ";

			hasAnyFunc = true;

			func += "(";

			int binary = i;
			string inverse = "\0"; // ����������

			for (int x = 0; x < numBitLength; x++) // ���������
			{
				if (binary % 2 == 0) inverse = "\'";
				binary /= 2;

				func += inverse + "x" + to_string(x + 1);

				if (x + 1 < numBitLength) func += " & ";
			}

			func += ")";
		}
	}

	return func;
}



int main()
{
	setlocale(LC_ALL, "RUS");

	bool k = 0;
	int switcher; // ��� ����
	int vector_lengh = 0;
	string file_path; // ��� ����
	vector<bool> my_vector;

	while (true)
	{
		cout << "�������:" << endl;
		cout << "1 �� ��������� ������� �������� f ������� ������� ���������� ���������� ���������� n ���� �������." << endl;
		cout << "2 �� ��������� ������������ � ����� ����� file_name ������� ������ �������� ������� �������." << endl;
		cout << "3 �������� �������� ������ �������� f ������� ������� � ����, ��������� ������������� � �������� ����� file_name. ������� true ��� �������� ������." << endl;
		cout << "4 �� ��������� ������� �������� f ������� ������� ������� ������, � ������� �������� ������� ���������� ���� ������� �������. " << endl;
		cout << "5 �� ��������� ������� �������� f ������� ������� ������� ������, � ������� �������� ���� ���� ������� ������." << endl;
		cout << "? �����" << endl;
		cin >> switcher;

		switch (switcher)
		{

		case 1:
			cout << "������ ������� " << num_of_args(my_vector) << endl;
			cout << endl;
			break;

		case 2:
			cout << "������� ������ ���� �� ����� ";
			cin >> file_path;
			my_vector = read_from_file(file_path);


			cout << "v = ";
			for (int i : my_vector) // ��������� ���� �� ���������� ������
			{
				cout << i << " ";
			}
			cout << endl;
			break;

		case 3:
			cout << "������� �������� ����� ";
			cin >> file_path;

			cout << "������� ������ ������� ";
			cin >> vector_lengh;

			for (int i = 0; i < vector_lengh; i++)
			{
				cin >> k; // ���� �������� �� ������
				my_vector.push_back(k);
			}
			write_to_file(file_path, my_vector);
			break;

		case 4:
			cout << "������� ������ ������� ";
			cin >> vector_lengh;

			for (int i = 0; i < vector_lengh; i++)
			{
				cin >> k; // ���� �������� �� ������
				my_vector.push_back(k);
			}
			// func_table(my_vector); �������� ����
			break;
		case 5:
			srand(time(0)); // ��� ��������� ��������

			for (int i = 0; i < 5; i++)
			{
				int n = 1 + (i / 4);// ������ ������ ���� ������ ������� 2
				for (int i = 0; i < pow(2, n); i++)
				{
					my_vector.push_back(rand() % 2); // �������� 1 ��� 0
					cout << my_vector[i];
				}
				cout << endl;

				string s = func_sdnf(my_vector);

				cout << s << "\n-------------------------------------\n";
			}
			break;

		default:
			return 0;
		}
	}
}