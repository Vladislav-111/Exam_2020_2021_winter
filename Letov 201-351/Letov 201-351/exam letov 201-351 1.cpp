#include <C:\Users\leto1\source\repos\Exam_2020_2021_winter\Letov 201-351\Letov 201-351\header.h>s

vector<bool> read_from_file(std::string file_name)
{
	vector<bool> rtrn;
	string temp;

	ifstream orig(file_name, ifstream::in);

	if (orig.is_open())
	{
		getline(orig, temp);
		for (int i = 0; i < temp.length(); i++)
			if (temp[i] == '1')
				rtrn.push_back(1);
			else if (temp[i] == '0')
				rtrn.push_back(0);
	}
	else
	{
		cout << "error";
	}
	return rtrn;
}

bool write_to_file(std::string file_name, vector<bool> f)
{
	ofstream orig(file_name, ofstream::out | ofstream::trunc);
	if (orig.is_open())
	{
		string buf;
		for (int i = 0; i < f.size(); i++)
			if (f[i])
				buf.push_back('1');
			else if (!f[i])
				buf.push_back('0');
		orig << buf;
		orig.close();
	}
	else
		return false;
}

int num_of_args(vector<bool> f)
{
	int pow = 0;
	int size = f.size();
	do
	{
		size /= 2;
		pow++;
	} while (size / 2 != 0);
	return pow;
}

string table(vector<bool> f)
{
	int power = num_of_args(f);
	string rtrn;
	string buf;
	int counter = 0;
	for (int i = 0; i < f.size(); i++)
	{
		int j = i;
		counter = 0;
		do
		{
			buf.append(std::to_string(j % 2));
			j /= 2;
			counter++;
		} while (j != 0 || counter < power);
		reverse(buf.begin(), buf.end());
		rtrn.append(buf + ' ' + std::to_string(f[i]) + '\n');
		buf.clear();
	}
	return rtrn;
}

//std::string func_sdnf(vector<bool> f)
//{
//	string rtrn;
//	string sub = "x ";
//	for (int i = 0; i < f.size(); i++)
//	{
//		//if (f[i] = )
//	}
//	return rtrn;
//}

bool XOR(bool x, bool y)
{
	return (x + y) % 2;
}

std::string func_Zhegalkin(vector<bool> f)
{
	string rtrn;
	string buf;

	for (int i = 0; i < f.size(); i++)
		buf.append(std::to_string(f[i]));

	int counter = f.size();

	for (int i = 0; i < f.size(); i++)
	{
		int counter = f.size() - i;

		for (int j = 0; j < f.size() - i; j++);
		{
			buf.append(std::to_string(XOR(buf.size() - counter, buf.size() - counter + 1)));
		}
		
	}
	return rtrn;
}

int main()
{
	vector<bool> temp = { 0, 0, 0, 1, 0, 0, 0, 1 };
	cout << func_Zhegalkin(temp);
	//string tin = "C:/Users/leto1/source/repos/Exam_2020_2021_winter/Letov 201-351/Letov 201-351/test_in.txt";
	//write_to_file(tin, temp);
	/*vector<bool> zxc;
	string tout = "C:/Users/leto1/source/repos/Exam_2020_2021_winter/Letov 201-351/Letov 201-351/test_out.txt";
	zxc = read_from_file(tout);
	for (int i = 0; i < zxc.size(); i++)
		cout << zxc[i];*/

}