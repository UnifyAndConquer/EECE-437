#include <iostream>
using namespace std;
#include <typeinfo>
#include "var.h"

string nameOfValue(TriValue v){
  static string nameOfValueTable[]={"uu", "tt", "ff"};
  return nameOfValueTable[v];
}

ostream & operator << (ostream & os, Exp & e){
  string type = typeid(e).name();

  if(type == "4LVAR")
  {
    os << e.name;
  }
  else if(type == "Z4mainE4LNOT")   //unary operators
  {
    os << "( !";
    cout << *e.leftExp;
    os << " )";
  }
  else        //binary operators
  {
    os << "( ";
    cout << *e.leftExp;

    if(type == "Z4mainE4LAND")
      os << " & ";
    else if(type == "Z4mainE3LOR")
      os << " || ";
    else if(type == "Z4mainE5LNAND")
      os << " !& ";
    else if(type == "Z4mainE4LNOR")
      os << " !|| ";
    else if(type == "Z4mainE4LXOR")
      os << " x|| ";
    else if(type == "Z4mainE5LXNOR")
      os << " x!|| ";
    else if(type == "Z4mainE4LIMP")
      os << " => ";

    cout << *e.rightExp;
    os << " )";
  }
  return os;
}

ostream & operator << (ostream & os, TriValue val) {
  os << nameOfValue(val);
  return os;
}

LVAR::LVAR(string n) //: name (n), value (uu)
{
  name = n;
  value = uu;
  //was_called = 0;
}

void LVAR :: setValue(TriValue v) {
  value = v;
}

TriValue LVAR::evaluate() {
  return value;
}

void LVAR::getVars()
{
  bool isDuplicate = 0;
  for(int i=0; i<varList.size(); i++)
  {
    if(varList[i] == name)
      isDuplicate = 1;
  }
  if(!isDuplicate)
  {
    varList.push_back(name);
    cout<<name<<endl;
  }
}
