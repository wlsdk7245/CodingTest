#include <iostream>
#include <cstring>
using namespace std;

int main(void){
	char arr[200]="";
	
	cin>>arr;
	//a=97 z=122 A=65 _95
	int size=strlen(arr);
	
	for(int i=0; i<size; i++){
		if(arr[i]>=97 && arr[i]<=122){
			cout<<char(arr[i]-32);
		}
		else{
			cout<<char(arr[i]);
		}
	}
	return 0;
}
