#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(void){
	char arr[200]="";
	int answer[]={0,};
	cin>>arr;

	for(int i=0; i<strlen(arr); i++){
		cout<<arr[i]-64<<" ";
	}
	
	return 0;
}
