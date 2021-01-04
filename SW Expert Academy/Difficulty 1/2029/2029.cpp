#include <iostream>
#include <vector>
using namespace std;

int main(void){
	int t;
	cin>>t;
	
	vector<int> m;
	vector<int> n;
	
	for(int i=0; i<t; i++){
		int num1, num2;
		cin>>num1>>num2;
		
		m.push_back(num1);
		n.push_back(num2);
	}
	
	for(int j=0; j<t; j++){
		cout<<"#"<<j+1<<" "<<m[j]/n[j]<<" "<<m[j]%n[j]<<endl;
	}
	return 0;
}
