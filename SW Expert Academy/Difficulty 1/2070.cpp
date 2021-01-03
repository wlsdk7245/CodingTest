#include<iostream>

using namespace std;

int main(void)
{
	int T;
	cin>>T;
	
	char *answer[100];
	int a, b;
	
	for(int i=0; i<T; i++){
		cin>>a>>b;
		if(a<b) answer[i]="<";
		else if(a==b) answer[i]="=";
		else answer[i]=">";
	}
	
	for(int i=0; i<T; i++){
		cout<<"#"<<i+1<<" "<<answer[i]<<endl;
	}
	
	return 0;
}
