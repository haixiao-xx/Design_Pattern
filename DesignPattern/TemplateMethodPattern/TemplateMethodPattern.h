#pragma once
#include<iostream>
#include<string>

class MakeDrink
{
public:
	void Make() {
		step1();
		step2();
		step3();
		if (AddCom())
		{
			step4();
		}

	}
	void step1() { std::cout << "1.烧水" << std::endl; }
	void step3() { std::cout << "3. 倒入杯子" << std::endl; }

	//子类必须实现
	virtual void step2() = 0;
	virtual void step4() = 0;

	virtual bool AddCom() { std::cout << "不加任何东西" << std::endl; return true; }
};

class MakeTea :public MakeDrink
{
	void step2() override { std::cout << "2. 加茶叶" << std::endl; }
	void step4() override { std::cout << "4. 加柠檬" << std::endl; }
	bool AddCom() override { std::cout << "茶里不加柠檬。" << std::endl; return false; }
	
};
class MakeCoffe :public MakeDrink
{
	void step2() override { std::cout << "2. 加咖啡" << std::endl; }
	void step4() override { std::cout << "4. 加牛奶和糖" << std::endl; }
	bool AddCom() override { std::cout << "茶里加牛奶和糖。" << std::endl; return true; }
};