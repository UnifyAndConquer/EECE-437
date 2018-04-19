
#include <iostream>
#include <string>
using namespace std;
#include <var.h>

string nameOfValue(TriValue v){
  static string nameOfValueTable[]={"uu", "tt", "ff"};  //To Do: 
  return nameOfValueTable[v];
}

ostream & operator << (ostream & os, Var & v) {
  os << v.name ;//<< "has value " << nameOfValue(v.value) << endl;
  return os;
}

ostream & operator << (ostream & os, TriValue val) {
  os << nameOfValue(val);
  return os;
}

Var::Var(char n[]) : name (n), value (uu)
{
}

void Var :: setValue(TriValue v) {
  value = v;
}

TriValue Var :: evaluate() {
  return value;
}
