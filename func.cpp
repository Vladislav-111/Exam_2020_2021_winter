#include <iostream> // cout cin
#include <vector> // ��� ������ � ���������
#include <math.h> // ��� �������������� ��������
#include <fstream>
#include <string>

using namespace std;

const string file = {"F:\\file.txt"}; // ������������ �����1
const string file2 = {"F:\\file2.txt"}; // ������������ �����2

vector<bool> f; // ������ �� ���������

vector<bool> read_from_file(string file_name) { // ������ �������� �� �����
    vector<bool> vec; // ������ ������� ����������
    string str;
    ifstream out(file_name);
    if (!out.is_open()) {
        cout << "������ �������� �����!\n";
    } else {
        while (!out.eof()) { // ���� ���������� ��������
            str = "";
            out >> str;
            if (str == "") continue;
            vec.push_back(stoi(str)); // �������� �������� � ������
        }
    }
    out.close(); // ��������� ����
    return vec;
}

bool write_to_file(std::string file_name, vector<bool> f) {
    ofstream in;
    bool v;
    in.open(file_name, ios::app);
    int i;
    for (i = 0; i < f.size() - 1; i++) {
        in << f[i] << " ";
    }
    in << f[i];
    in.close();
    vector<bool> vec;
    vec = read_from_file(file_name);
    if (vec == f) {
        v = true;
    }

    return v;
}

int num_of_args(vector<bool> f) {
    int n = log2(f.size());
    return n;
}

int main() {
    f = read_from_file(file);
    bool tr = write_to_file(file2, f);
    cout << tr;
}
