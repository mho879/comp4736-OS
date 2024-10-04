#include<iostream>
using namespace std;

int main(int argc, char* argv[]) {

  int a = 45; int b = 22;
  int *p = &a;
  int *q = NULL;
  int *f;

  cout << *p << endl;

  p = q;
  cout << p << endl;
  *f = *q;

  p = &b;
  cout << *p << endl;

  return 0;
}