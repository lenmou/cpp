/*
���ߣ�����
ʱ�䣺2021.4.3
Ŀ�ģ�����һ���������������������
*/
#include<iostream>
using namespace std;
//�ڵ�
template<typename T>
class Node
{
public:
	Node<T>* m_next = nullptr;
	T m_data;
	Node(T val):m_data(val){}
	~Node() {}
};
//����
template<typename T>
class List
{
public:
	Node<T> *m_head = nullptr, * m_tail = nullptr;
	List() {}
	~List() { 
		Node<T>* p = nullptr;
		while(m_head!=nullptr)
		{
			p = m_head;
			m_head = m_head->m_next;
			delete p;
		}
	}
	//��������
	void push_back(const T &val)
	{
		Node<T>* node = new Node<T> (val);
		if(m_head==nullptr)
		{
			m_head = node;
			m_tail = node;
		} else
		{
			node->m_next = m_head;
			m_head = node;
		}
	}
	//�����������
	void show()
	{
		Node<T>* p = nullptr;
		//ֻ���жϵ����һ�����������һ����û�������
		while (m_head != m_tail)
		{
			p = m_head;
			m_head = m_head->m_next;
			cout << p->m_data << " ";
		}
		//�������������һ����������
		cout << m_tail->m_data;
	}
};

int main() 
{
	List<int> l;
	while(1)
	{
		int a = 0;
		cin >> a;
		if (a == -1) { break; }
		l.push_back(a);
	}
	l.show();
	return 0;
}