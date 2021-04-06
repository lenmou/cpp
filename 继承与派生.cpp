/*
���ߣ�����
ʱ�䣺2020.3.21
Ŀ�ģ����ô��麯��������shape��״���࣬������Բ��;����࣬Ҫ����������ĺ���
*/
#include<iostream>
using namespace std;
class shape 
{
public:
	virtual double getarea()= 0;//���麯��
};
class circle:public shape
{
protected:
	double radius;
public:
	circle(double r):radius(r) {}
	circle(const circle &p):radius(p.radius) {}
	~circle() {}
	double getarea() { return radius * 3.14 * 3.14; }
};
class rectangle :public shape {
protected:
	double length;
	double width;
public:
	rectangle(double l,double w):length(l),width(w) {}
	rectangle(const rectangle&p):length(p.length),width(p.width) {}
	~rectangle() {}
	double getarea() { return length * width; }
};
int main() {
	circle c(5);
	rectangle r(3, 4);
	cout << c.getarea() << endl;
	cout << r.getarea() << endl;
	return 0;
}