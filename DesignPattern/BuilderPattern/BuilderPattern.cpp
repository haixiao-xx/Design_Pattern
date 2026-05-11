#include"BuilderPattern.h"

int main()
{


	//ComputerBuilder* cBuilder;   指针没有指向任何对象 ，会是野指针
	ComputerBuilder* cBuilder = new ComputerBuilder();
	Director dir(cBuilder);
	dir.Construct();
	Computer com = cBuilder->GetComputer();
	com.show();
	delete cBuilder;
	std::cout << "hello" << std::endl;
	return 0;
}