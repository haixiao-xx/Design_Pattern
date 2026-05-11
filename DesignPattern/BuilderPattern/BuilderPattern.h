#pragma once
#include<iostream>
#include<string>

//纯虚函数   必须由派生类实现
//虚函数    可实现可不实现

//产品

class Computer
{
public:
	std::string cpu;
	std::string gpu;
	int ram;

	void show() {
		std::cout << "cpu: " << cpu << std::endl;
		std::cout << "gpu: " << gpu << std::endl;
		std::cout << "ram: " << ram << std::endl;
	}
};

//builder抽象类

class Builder
{
public:
	virtual void SetCpu() = 0;
	virtual void SetGpu() = 0;
	virtual void SetRam() = 0;
	virtual Computer GetComputer() = 0;
	virtual ~Builder(){}
};

class ComputerBuilder :public Builder
{
private:
	Computer computer;
public:
	void SetCpu() override { computer.cpu = "Intel i9"; }
	void SetGpu() override { computer.gpu = "RTX 4990"; }
	void SetRam() override { computer.ram = 64; }
	Computer GetComputer() override { return computer; }
};

class Director
{
private:
	Builder* builder;
public:
	Director(Builder* b):builder(b){}
	void Construct() {
		builder->SetCpu();
		builder->SetGpu();
		builder->SetRam();
	}
};