#include <iostream>
using namespace std;

int main(void){
	int N;
	int sum=0;
	
	cin>>N;

	sum+=N%10;
	N-=N%10;
	sum+=N%100/10;
	N-=N%100;
	sum+=N%1000/100;
	N-=N%1000;
	sum+=N%10000/1000;
	N-=N%10000;
	
	cout<<sum;
	
	return 0;
}
