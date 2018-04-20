REFACTORING EXERCICE

This is a refactoring exercice with three-valued boolean formulas. Commits are roughly equivalent to “refactoring stages”

Refactoring Stages:
1 - constructors: Make two pointers of type Exp in base class Exp: leftExp and rightExp, to replace the list of pointers each of a different type. Constructor now takes two arguments: left and right, of type Exp. This way you can omit giving the constructor the types of the objects that you passed, because they get cast to the appropriate derived type automatically.
2 - evaluate function: Make base class' evaluate function virtual, all gates inherit from this function. Then the appropriate evaluate() function will be called automatically.

Details:
- replaced char c[] with string in var constructor so compiler stops giving warning
