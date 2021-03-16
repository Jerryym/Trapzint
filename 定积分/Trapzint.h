#pragma once
#ifndef Trapzint_h
#define Trapzint_h
class Function//抽象类
{
public:
	virtual double operator()(double x)const = 0;//纯虚函数重载运算符 ()
	virtual ~Function() {}//虚析构函数
};

class MyFunction:public Function
{
public:
	virtual double operator()(double x)const;//覆盖虚函数
};

class Integration
{
public:
	virtual double operator()(double a, double b, double eps)const = 0;//纯虚函数重载运算符 ()
	virtual ~Integration() {}
};

class Trapz:public Integration
{
public:
	Trapz(const Function &f) :f(f) {
	}
	virtual double operator()(double a, double b, double eps)const;
private:
	const Function &f;//类对象的指针
};

#endif // !Trapzint_h
