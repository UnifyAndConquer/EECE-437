#pragma once
#include <string>

enum TriValue {
  uu, tt, ff,
};

struct Exp    //expression object from which all logical operations inherit, including variables
{
  string name;
  Exp * leftExp;      //pointer to left side expression
  Exp * rightExp;     //pointer to right side expression

  //Exp(Exp * left, Exp * right) {leftExp = left; rightExp = right;}
  virtual TriValue evaluate() = 0;
};