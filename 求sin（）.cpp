/*
      
	  ���ߣ�����
	  ʱ�䣺2020��11��12��
	  Ŀ�ģ���sin����
*/
#include<iostream>
#include<cmath>
using namespace std;
int main() {
	double t, x, y=0.0;
	double i=1;

	//����x
	cout << "������x=";
	cin >> x;
	t = x;
	//����sin��x��
	while (fabs(t) > 1.0e-5)//ȷ������
	{//����̩�չ�ʽ���㣬ѭ��
		y += t;
		i++;
		t *= -x * x / ((2 * i - 1) * (2 * i - 2));
	}
	//���y
	cout << "sin(" << x << ")" << y << endl;
	cout << "��ʵֵ�ǣ�" << sin(x) << endl;
		return 0;
}