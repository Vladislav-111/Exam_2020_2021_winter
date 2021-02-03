#include <iostream> //ввод вывод
#include <vector> //библиотека работы с векторами
#include <string> //библиотека работы со строками 
#include <fstream> //библиотека рабоы с файлами
#include <set> //библиотека для таботы с контейнером множество
#include <map> //библиотека для таботы с контейнером map
#include "Balashova.h"
using namespace std;


//ЧАСТЬ 1
int num_of_args(vector<bool> f)
{
	int n=0;// колличество элементов 
	while (pow(2, n) != f.size())
		n++;
	return  n;
}

vector<bool> read_from_file(string file_name)
{
	ifstream inf(file_name);//открываем файл для чтения
	vector <bool> f;
	while (inf)
	{
		bool i;
		inf >> i;//считываем 
		f.push_back(i);//добавляем в вектор
	}
	inf.close();
	return f;
}

bool write_to_file(string file_name, vector<bool> f)
{
	ofstream outf(file_name);//открываем файл для ввода
	int i = 0;
	for (int i = 0; i < f.size(); i++)
		outf << f[i] << ' ';//вводим в файл
	outf.close();
	return true;
}

string table(vector<bool> f)
{
	string tabl;
	int n = num_of_args(f);//находим количкство элементов 
	for (int i = 0; i <= n; i++)
		tabl += "x" + to_string(i) + " ";
	tabl += "f" + '\n';
	
	for (int i = 0; i <= n; i++)
	{
		if (i == 0)//просмативаем когда на 0
		{
			for (int j = 0; j <= n; j++)
			{
				tabl += i;
			}
		}

		int bin;
		for (int j = 0; i > 0; j++)//первод в двоичную систему с 1 по n
		{
			bin += (i % 2) * pow(10.0, j);
			i /= 2;
		}

		int x = 1,k=0;
		while (bin / x != 0) //ищем долинну двоичного эл
		{
			x *= 10;
			k++;
		}

		if (k != n)//заносим в строку когда длинна эл меньше нужный 
		{
			while (k != n)//заносим начальные недостающие нули
			{
				tabl += "0 ";
				k++;
			}
		    tabl += to_string(bin)+" ";//заносим сам эл
		}
		else 
			tabl += to_string(bin)+" ";//если эл нужного размера то просто его заносим
		tabl += to_string(f.at(i))+'\n';
	}

	return tabl;
}

string func_sdnf(vector<bool> f)
{

}

std::string func_sknf(vector<bool> f)
{

}

std::string func_Zhegalkin(vector<bool> f)
{

}


//ЧАСТЬ 2
int roman_to_arab(string roman_number)
{
	//создаём два контейнера map 
	map<string, int> roman1 = { { "I", 1 },{ "V", 5 },{ "X", 10 },{ "L", 50 },{ "C", 100 },{ "D", 500 },{ "M", 1000 } };

	map<string, int> roman2 ={{ "IV", 4 },{ "IX", 9 },{ "XL", 40 },{ "XC", 90 },{ "CD", 400 },{ "CM", 900 } };


}

unsigned long long make_C(int k, int n)//при помощи рикурсии находим элемент 
{
	unsigned long long c;
	if (k == 0)
		c = 1;
	else
		c = make_C(k - 1, n) * (n - k + 1) / k;//рекурсия 
	return c;
}

vector<int> func_Pascal(int k)
{
	vector <int> pascal;
	for (int i = 0; i <= k; i++)//заносим каждый элемент в вектор 
	{
		pascal.push_back(make_C(i, k));
	}
	return pascal;
}

int func_substr_len(string input_str)
{
	int poisk_vxoda = 0, max = 0, len = 0, vxod;
	set <char> pod_str; //создаём множество для хранения символов до момента повтора потом он очищается и заполняется до конца цикла
	for (int i = 0; i < input_str.length(); i++)
	{
		pod_str.insert(input_str[i]);
		if (len == pod_str.size())
		{
			if (max<pod_str.size())
				max = pod_str.size();
			pod_str.clear();//очищаем пножество
			vxod = input_str.find(input_str[i], poisk_vxoda);//ищем место откуда будем просматривать
			i = vxod;
			poisk_vxoda = i + 1;
		}
		len = pod_str.size();
	}
	return max;
}