#include <iostream>
#include "test2.h"

class Condition
{
	public:
		virtual bool checkCondition() = 0;
};

#define COND_DECLARE(ConditionName, Expression)\
 class ConditionName : public Condition {\
 	public:\
		ConditionName(Variables * vars) { V = vars; }\
		bool checkCondition() { return Expression; }\
	private:\
		Variables * V;\
 };\


 class foo
 {
 public:
	 foo(Condition * cond) {condition = cond;}
	 bool isValid() {return condition->checkCondition();}
 private:
	 Condition * condition;
 };

Variables V;

int main()
{
	V.timer = 3;
	V.yellowLed = 0;
	V.greenLed = 9;

	/////TESTING MACROS
	COND_DECLARE(timerIsReset, (V->timer == 0));				//slight inconvenience: pointer syntax should be used here
	timerIsReset TIR(&V);
	COND_DECLARE(timerEqualsThree, (V->timer == 3));				//slight inconvenience: pointer syntax should be used here
	timerEqualsThree TET(&V);

	/////TESTING RUNTIME POLYMORPHISM
	foo reset(&TIR);				//analogous to transition class
	foo three(&TET);

	std::cout<<"Reset condition: "<<reset.isValid()<<"\n";
	std::cout<<"Three condition: "<<three.isValid()<<"\n";
	std::cout<<"Reference condition check: "<<TIR.checkCondition()<<"\n";

	/////TESTING STATIC VARIABLES
	dummy dum;
	dum.printTimer();

	return 0;
}


// class Sort
// {
// public:
// 	enum Type {Selection,Merge,Insertion,Heap,Quick};
// 	Type t;
// 	Sort(Type at=Merge) :t(at){}
//
// 	void operator()(int a[],int n){
// 		switch (t) {
// 			case Selection:
//
// 			 break;
// 			 case Merge:
//
// 			 break;
// 			 //...
// 		}
// 	}
// };
//
// Sort mysort;
// int a[20];
//
// mysort(a,20);// mysort.operator()(a,20);
// mysort.type = Selection;
// mysort(a,20);


// class Fred
// {
// public:
// 	Fred(){};
// 	Fred(int * x)
// 	{
// 		pointer = x;
// 		std::cout<<*pointer<<"\n";
// 	}
//   int getX()
// 	{
// 		return *pointer;
// 	}
// 	int * pointer;
// };

// int var = 39 ;								  //resp boolean
// Fred Freddy(&var);							//resp condition class
// var = 47;												//resp function called by Action class
// std::cout<<Freddy.getX()<<"\n"; //resp debugging
