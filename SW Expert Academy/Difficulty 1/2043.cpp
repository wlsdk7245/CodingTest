#include <iostream>
using namespace std;

int main(void){
	int P, K;
	int cnt=0;
	
	cin>>P>>K;
	
	for(K; K<=P; K++){
		cnt++;
	}
	
	cout<<cnt;
	
	return 0;
}
