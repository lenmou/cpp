/*
����������
ʱ�䣺2021.3.29
Ŀ�ģ����ö�̬���飬�Լ�дһ��vector
*/
#include<iostream>
using namespace std;

template<typename T>
class MyVec
{
protected:
	int m_size=0;
	T * m_p=nullptr;
public:
	~MyVec() { delete[]m_p; }//����������delete��̬����
	MyVec(){}
	MyVec(int size):m_p(new T[size]){}
	//���ƹ��캯��
	MyVec(const MyVec& p) : m_size(p.m_size)
	{
		m_p=new T[p.m_size] ;
		for (int i = 0; i < p.m_size; i++)
	    {m_p[i] = p.m_p[i];}
	}
	//�ƶ����ƹ��캯��
	MyVec(MyVec&& p) : m_size(p.m_size),m_p(p.m_p)
	{
		p.m_size = 0;
		p.m_p = nullptr;
	}
	//����=�����
	MyVec& operator=(const MyVec& a)
	{
		if(this != &a)
		{
			delete[]m_p;
			m_size = a.m_size;
			m_p = new T[a.m_size];
			for (int i = 0; i < a.m_size; i++)
			{
				m_p[i] = a.m_p[i];
			}
		}
		return *this;
	}
	//�ƶ�����=�����
	MyVec& operator=(const MyVec&& a)
	{
		if (this != &a)
		{
			delete[]m_p;
			m_size = a.m_size;
			m_p = a.m_p;
			a.m_p=nullptr;
			a.m_size = 0;
		}
		return *this;
	}
	int size() { return m_size; }
	//����[]�����
	T& operator[](int i) {
		return m_p[i];
	}
	//�ں���ѹ��
	void push_back(T val){
		T* p = new T[m_size + 1];
		for (int i = 0; i <m_size; i++)
		{
			p[i] = m_p[i];
		}
		p[m_size] = val;
		delete[]m_p;
		m_p = p;
		m_size++;
	}
	//ɾ������Ǹ�
	void pop_back() {
		if (m_size == 0)return;
		T* p = new T[m_size - 1];
		for (int i = 0; i < m_size-1; i++)
		{
			p[i] = m_p[i];
		}
		delete[]m_p;
		m_p = p;
		m_size--;
	}
	void show()
	{
		for (int i = 0; i < m_size; i++)
		{
			cout << m_p[i] << " ";
		}
		cout << endl;
	}
	//ָ��λ�ò���
	void insert(int n,T m) 
	{
		if (n <= 0) return;
		T* p = new T[m_size + 1];
		for (int i = 0; i < n ; i++)
		{
			p[i] = m_p[i];
		}
		p[n] = m;
		for (int i = n+1; i < m_size + 1; i++)
		{
			p[i] = m_p[i-1];
		}
		delete[]m_p;
		m_p = p;
		m_size++;
	}
	//ָ��λ��ɾ��
	void erase(int n)
	{
		if (n <= 0) return;
		T* p = new T[m_size - 1];
		for (int i = 0; i < n; i++)
		{
			p[i] = m_p[i];
		}
		for (int i = n ; i < m_size - 1; i++)
		{
			p[i] = m_p[i + 1];
		}
		delete[]m_p;
		m_p = p;
		m_size--;
	}
};

int main() 
{
	MyVec<int>v1;
	//����push_back
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i*i);
	}
	v1.show();
	//����pop_back
	v1.pop_back();
	v1.show();
	//����ָ��λ�ò���
	v1.insert(3, 0);
	v1.show();
	//����ָ��λ��ɾ��
	v1.erase(3);
	v1.show();
	return 0;
}