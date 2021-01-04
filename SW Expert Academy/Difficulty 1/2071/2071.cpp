#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	int t;
	int num;
	cin>>t;
	double sum[100]={0.0};
	
	for (int i=1; i<=t; i++){
		for (int j=1; j<=10; j++){
			cin>>num;
			sum[i-1]+=double(num);
		}
		sum[i-1]=round(sum[i-1]/10.0);
	}
	
	for (int k=1; k<=t; k++){
		cout<<"#"<<k<<" "<<sum[k-1]<<endl;
	}
	return 0;
}
