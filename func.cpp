#include <iostream> // cout cin
#include <vector> // ��� ������ � ���������
#include "func.h"
#include <string> // ��� ������ �� ��������

using namespace std;

const string file = {"F:\\file.txt"}; // ������������ �����1
const string file2 = {"F:\\file2.txt"}; // ������������ �����2

vector<bool> f; // ������ �� ���������

int main() {
  setlocale(0, " ");
  f = read_from_file(file);
  bool tr = write_to_file(file2, f);
  int a = num_of_args(f);
  cout << "1 �������: " << a << endl;
  cout << "2 �������: ";
  for (int i = 0; i < f.size(); i++){
    cout << f[i];
  }
  cout << endl;
  cout << "3 �������:";
  if (tr == 1){
    cout << "True";
  } else{
    cout << "False";
  }
  cout << endl;
  cout << "4 �������: ";
  string string1 = table(f);
  cout << string1;
  cout << endl;
  cout << "5 �������: ";
  string string2 = func_sdnf(f);
  cout << string2;
}