/*


Ŀ�ģ������ҵ���������������Լ������С������
���ߣ�����
ʱ�䣺2020��11��12��


*/


#include<iostream>
#include<cmath>
using namespace std;
int main() {
	
	//����������
	int m, n;
	cout << "��������������m��n" << endl;
	cin >> m >> n;
	//����һ��a��Ϊm��n�ĳ˻�
	int a = m * n;
	//�ж�m,n�Ĵ�С
	if (m < n) {
		int t;
		t = m;
		m = n;
		n = t;
	}
	//��շת������������Լ������������Լ��
	//�ж�m�ǲ���n�ı���
	int x=0;
	if(m % n != 0) {
		while (m % n != 0) {
			x = m % n;
			m = n;
			n = x;
		}
		cout << "���Լ���ǣ�" << x << endl;
	}
	else {
		x = n;
		cout << "���Լ���ǣ�" << x << endl;
	}
	//��Ϊ֮ǰ�����ʱ��m��n��ֵ�Ѿ������˱任
	//������ǰ�涨��һ��a��m��n�ĳ˻�
	//������С������
	double y=0;
	y = a / x;
	//�����С������
	cout << "��С�������ǣ�" << y << endl;
		return 0;
}