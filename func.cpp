#include <iostream> // cout cin
#include <vector> // ��� ������ � ���������
#include "func.h" // � ���������
#include <string> // ��� ������ �� ��������

using namespace std;

const string file = {"D:\\file.txt"}; // ������������ �����1
const string file2 = {"D:\\file2.txt"}; // ������������ �����2

vector<bool> f; // ������ �� ���������

int main() {
    setlocale(0, " ");
    f = read_from_file(file);
    bool tr = write_to_file(file2, f);
    int a = num_of_args(f);
    cout << "1 �������: " << a << endl;
    cout << "2 �������: ";
    for (int i = 0; i < f.size(); i++) {
        cout << f[i];
    }
    cout << endl;
    cout << "3 �������:";
    if (tr == 1) {
        cout << "True";
    } else {
        cout << "False";
    }
    cout << endl;
    cout << "4 �������: " << endl;
    string string1 = table(f);
    cout << string1;
    cout << endl;
    cout << "\n------------2 �����------------" << endl;
    cout << "1 �������: " << endl << "������� ������� �����:";
    string Roman;
    cin >> Roman;
    cout << Roman << " = " << roman_to_arab(Roman) << endl;
    cout << "2 �������: " << endl;
    cout << "������� k:";
    int k;
    cin >> k;
    cout << "Func_Pascal(" << k << ") = ";
    vector<int> vector;
    vector = func_Pascal(k);
    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i] << " ";
    }
    cout << endl;
    cout << "3 �������: ";
    string str;
    cout << "������� ������:";
    cin >> str;
    int result = func_substr_len(str);
    cout << result;

}