#include <iostream>
using namespace std;

void Add(int &a)
{
	a=a+1;
}

void Change(int &a)
{
	a=-1*a;
}

int main(void)
{
	int num1, num2;
	
	cout<<"1�� ������ų ���� �Է�: ";
	cin>>num1;
	Add(num1);
		
	cout<<"��ȣ�� �ٲ� ���� �Է�: ";
	cin>>num2;
	Change(num2);
	
	cout<<"1�� ��� : "<<num1<<endl;
	cout<<"2�� ��� : "<<num2<<endl;
	return 0;
}
