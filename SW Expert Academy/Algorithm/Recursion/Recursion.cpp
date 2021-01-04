#include <iostream>
using namespace std;

int Factorial(int num){
	if(num==0){
		return 1;
	}
	else{
		return num*Factorial(num-1);
	}
}

int main(void){
	int T;
	cin>>T;
	
	for(int i=1; i<=T; i++){
		int num;
		cin>>num;
		int answer=Factorial(num);
		cout<<"#"<<i<<" "<<num<<"! = "<<answer<<endl;
	}
	return 0;
}
