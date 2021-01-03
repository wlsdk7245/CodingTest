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
	
	cout<<"1을 증가시킬 숫자 입력: ";
	cin>>num1;
	Add(num1);
		
	cout<<"부호를 바꿀 숫자 입력: ";
	cin>>num2;
	Change(num2);
	
	cout<<"1번 결과 : "<<num1<<endl;
	cout<<"2번 결과 : "<<num2<<endl;
	return 0;
}
