#include <iostream>
using namespace std;

int main(void)
{
	const int num=12;
	const int *ptr=&num;
	const int &ref=*ptr;
	
	cout<<num<<endl;
	cout<<*ptr<<endl;
	cout<<ref<<endl;
	
	cout<<&num<<endl;
	cout<<ptr<<endl;
	cout<<&ref<<endl;
	return 0;
}
