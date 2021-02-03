#include "Half1.h"
#include <fstream>

int num_of_args(std::vector<bool> f)
{
	return (int) log2(f.size());
}

std::vector<bool> read_from_file(std::string file_name)
{
	std::vector<bool> vec;
	std::ifstream in;

	try 
	{
		in.open(file_name);
		if (!in.good())
			return vec;

		std::istream_iterator<bool> start(in), end;

		vec = std::vector<bool>(start, end);

		in.close();
	}
	catch (const std::exception& e)
	{
		printf_s("Error while reading file\n%s\n", e.what());
		return vec;
	}

	return vec;
}

bool write_to_file(std::string file_name, std::vector<bool> f)
{
	std::ofstream out;

	try
	{
		out.open(file_name);
		if (!out.good())
			return false;

		for (bool b : f)
		{
			out << b << " ";
		}
	}
	catch (const std::exception& e)
	{
		printf_s("Error while writing file\n%s\n", e.what());
		return false;
	}

	return true;
}

std::string table(std::vector<bool> f)
{
	std::string table;

	int argNum = num_of_args(f);

	// print table header
	for (int i = 1; i <= argNum; i++)
	{
		table += "x" + std::to_string(i) + "\t";
	}

	table += "f\n";

	for (int i = 0; i < f.size(); i++)
	{
		for (int j = 0; j <= argNum; j++)
		{
			if (j == argNum)
				table += std::to_string(f.at(i));
			else 
			{
				
				table += std::to_string((bool)(i & (int) (pow(2, (argNum - j - 1))))) + "\t";
			}
		}
		table += "\n";
	}

	return table;
}
