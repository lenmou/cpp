/*
���ߣ�19c207 ������
Ŀ�ģ�ͨ�������������ȡtxt�ļ������ݣ�Ȼ��������룬ɾ���ȹ���
ʱ�䣺2021.4.11
*/

#include<iostream>
#include<string>
#include<map>
#include<utility>
#include<fstream>
#include<iomanip>

using namespace std;

int main() 
{
	multimap<string, string> zp;//��Ʒ��Ϣ����
	ifstream in("��Ʒ��Ϣ.txt");//���ļ�����
	ofstream out;
	string author, work;
	int n = 0;//������Ʒ����
	if(!in)
	{
		cout << "���ļ�ʱ��ʧ�ܡ�";
			return 0;
	}
	else {
		in >> n;
		for (int i = 0; i < n; i++) {
			in >> author >> work;
			zp.insert(make_pair(author, work));
		}
	}
	string name;
	cout << "������Ҫɾ�������ߣ�";
	cin >> name;
	int m = zp.count(name);//��¼�ҵ��ĸ���
	if (m == 0)
	{
		cout << "û���ҵ���";
	}
	else {
		auto it = zp.find(name);
		zp.erase(name);
		cout << "ɾ���ɹ���"<<endl;
		//��zp�����һ���µ�txt�ļ���
		out.open("�½��ı��ĵ�.txt");
		if (!out)
		{
			cout << "д��ʱ�ļ���ʧ�ܡ�" << endl;
			return 0;
		}
		else {
			out << n-m << endl;
			for (auto it = zp.begin(); it != zp.end(); it++)
			{
				
				out << left<<setw(20)<< it->first << "\t" <<  setw(20)<< it->second << endl;
			}
			cout << "д��ɹ�" << endl;
		}
	}
	//������������һ��zp�е�����
	for(auto it = zp.begin();it!=zp.end();it++)
	{
		cout << left << setw(20) << it->first << setw(20)<< it->second<<endl;
	}
	
	
	
	in.close();
	out.close();
	return 0;
}