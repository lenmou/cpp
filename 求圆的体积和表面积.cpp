/*

Ŀ��:�����ҵ�������������ͱ����
����������
��Ȩ���У���Ȩ�ؾ�

*/
#include<iostream>
#include<cmath>
using namespace std;
const double PI = 3.1415926535;

int main() {
	double radius, volume, s;
    cout << "please input the radius of the ball ";
	cin >> radius;
	int zxy = 1;
	while (zxy) {
		if (radius <= 0) {
			cout << "��İ뾶Ӧ����0,���������룡";
			cin >> radius;
		}
		else {
			zxy = 0;
		}
	}
	s = 4 * PI * radius * radius;
	volume = 4.0 / 3.0 * PI * radius * radius * radius;
	cout << "the volume is :" << volume << endl;
	cout << "the s is :" << s << endl;
	system("pause");
		return 0;
}