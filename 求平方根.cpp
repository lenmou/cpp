/*
���ߣ�����
ʱ�䣺2020.12.21
Ŀ�ģ���һ������ƽ����
*/
#include<iostream>
using namespace std;
int main() {
	double a, x1 = 1, x2 = 2,t=1;
	cout << "please input a figure";
	cin >> a;
	while (a < 0) {
		cout << "aӦ�ô���0,����������";
		cin >> a;
	}
	while (fabs(t) > 1e-5)//��������ȷ������
	 {//ѭ��
			x2 = (x1 + a / x1) / 2;
			t = x1 - x2;
			x1 = x2;
		}
	cout << x1;
	return 0;
}