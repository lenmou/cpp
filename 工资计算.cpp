/*
���ߣ�����
Ŀ�ģ����ǲ��ż��㹤���е��鷳������д��һ��������Լ��㣬�����������������˲��Ź��ʵļ��㡣
���õ��ļ�������������
*/
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;
int n = 0;
class person
{
public:
	double time=0;
	string name=" ";
	string xuehao = " ";
	double money=0;
	person() = default;
	~person() {}
//��ʱ��
	void gettime(double a) { time = a; }
	//�㼨Ч�ͷ���
	void getmoney(double a) { money = money + a; }
	//�������ֺ�ѧ��
	void getname(string a, string b) { swap(a,name); swap(b, xuehao); n++; }
	//���ܽ��
	void count()
	{
		if (time < 16) { money = money + time * 16; }
		else if (time >= 16 && time < 20) { 
			money = money + 260 + (time - 16) * 10; }
		else if (time >= 20) {
			money = money + 300 + (time - 20) * 8;}
	}
};
int main()
{
	person a[25];
	ofstream out;
	ifstream in("����.txt");//���ļ�����
	double d;
	if (!in)
	{
		cout << "���ļ�ʱ��ʧ�ܡ�";
		return 0;
	}
	else
	{
		//��������
		for (int i = 0; !in.eof(); i++)
		{
			string l;//�����ļ���һ��
			getline(in, l);//��ȡһ���ļ�
			string b, c;//�������ֺ�ѧ��
			istringstream iss(l);//string������
			iss >> b >> c;//һ�е�ǰ������������ѧ��
			a[i].getname(b, c);//�õ�������ѧ��
			vector<string> m;//�������Ĺ���ʱ�䣬�Ա����ת��Ϊdouble
			string q;//�õ����������
			while (iss >> q) { m.push_back(q); }//��string������ַ�ѹ����������
			double p[20] = { 0 };//����õ�������
			for (int j = 0; j < m.size(); j++) {//��stringת��Ϊdouble
				p[j] = atof(m[j].c_str());
			}
			for (int k = 0; k < m.size(); k++) {//����ʱ��
				if (p[k] < 10) { a[i].time += p[k]; }
				else {
					a[i].getmoney(p[k]);
				}
			}

			//��������
			 a[i].count();
		}
		cout << "����ɹ�" << endl;
		//������ı�
		out.open("���.txt");
		if (!out)
		{
			cout << "д��ʱ�ļ���ʧ�ܡ�" << endl;
			return 0;
		}
		else {
			out << left << setw(50) << "����" << setw(50) << "ѧ��" << setw(50) << "��ʱ��" << setw(50) << "�ܹ���" << endl;
			for (int i = 0; i < n; i++)
			{
				out << left << setw(50) << a[i].name << setw(50) << a[i].xuehao << setw(50) << a[i].time << setw(50) << a[i].money << endl;
			}
			cout << "д��ɹ�" << endl;
		}
		in.close();
		out.close();
		return 0;
	}
}