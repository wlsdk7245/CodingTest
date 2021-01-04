#include <iostream>
using namespace std;

int main(void){
	int t;
	int num;
	cin>>t;
	int sum[100]={0};
	
	for (int i=1; i<=t; i++){
		for (int j=1; j<=10; j++){
			cin>>num;
			if(num%2==1){
				sum[i-1]=sum[i-1]+num;
			}
		}
	}
	
	for (int k=1; k<=t; k++){
		cout<<"#"<<k<<" "<<sum[k-1]<<endl;
	}
	return 0;
}
