#include <iostream>
using namespace std;
#include <typeinfo>
#include "var.h"

string nameOfValue(TriValue v){
  static string nameOfValueTable[]={"uu", "tt", "ff"};
  return nameOfValueTable[v];
}

ostream & operator << (ostream & os, Exp & e){
  string typex = typeid(e).name();
  string type = typex.erase(0,1);

  if(type == "Var")
  {
    os << e.name;
  }
  else if(type == "LNot")
  {
    os << "( !";
    cout << *e.leftExp;
    os << " )";
  }
  else
  {
    os << "( ";
    cout << *e.leftExp;
    os << " & ";
    cout << *e.rightExp;
    os << " )";
  }
  return os;
}

ostream & operator << (ostream & os, TriValue val) {
  os << nameOfValue(val);
  return os;
}

Var::Var(string n) //: name (n), value (uu)
{
  name = n;
  value = uu;
}

void Var :: setValue(TriValue v) {
  value = v;
}

TriValue Var::evaluate() {
  return value;
}
