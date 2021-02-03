#include <iostream> // ���������� ��� �����/������
#include "func.h" // ���������� ������������ ����

using namespace std;  

template <class type> // ������ ��� ��������� �������
void print_vector(vector<type> v) 
{
    cout << "[ ";  
    for (auto i : v)  // ��������� �������� �������
        cout << i << " ";

    cout << "]" << "\n";
}



int main() { 
    vector<bool> vec = read_from_file("test.txt"); // ������� ������ � ���������� bool
    print_vector(vec); 
    cout << endl;
    cout << num_of_args(vec) << endl; // ������� ���������� ���������� ������� �������
    write_to_file("testO.txt", vec);  // ���������� � ���� ��� ������
    cout << table(vec) << endl;   
    cout << func_sdnf(vec) << endl;
    cout << func_sknf(vec) << endl;

    print_vector(func_Pascal(5));  // � �������� ������� ������� ������������ �������
    cout << endl;
    cout << func_substr_len("abcabcbb") << endl; 
    system("pause");
}