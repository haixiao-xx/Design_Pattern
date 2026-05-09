#include"TemplateMethodPattern.h"


/****************************************

	Make()
	这个函数：

	固定了算法流程
	子类不能修改顺序

	这就是：

	模板方法（Template Method）

	它定义了：

	算法骨架

***************************************/
int main()
{
	MakeTea tea;
	tea.Make();

	MakeCoffe coffe;
	coffe.Make();

	std::cout << "hello." << std::endl;
	return 0;
}