#include <iostream>

class Fred
{
public:
	Fred(){};
	Fred(int * x)
	{
		pointer = x;
		std::cout<<*pointer<<"\n";
	}
  int getX()
	{
		return *pointer;
	}
	int * pointer;
};

int main()
{
	int var = 39 ;								  //resp boolean
	Fred Freddy(&var);							//resp condition class
	var = 47;												//resp function called by Action class
	std::cout<<Freddy.getX()<<"\n";

	return 0;
}
