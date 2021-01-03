#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

int main(void){
	int t;
	cin>>t;
	vector<int> date;
	
	int answer[1000][100]={0,};
	
	for(int i=0; i<t; i++){
		int num;
		cin>>num;
		date.push_back(num);
	}
	
	for(int j=0; j<t; j++){
		int day=(date[j]%100);
		int month=(date[j]%10000-day)/100;
		int year=(date[j]%100000000-(month*100+day))/10000;
		
		if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
			if(day<1 || day>31){
				answer[j][0]=-1;
				continue;
			}
		}
		else if(month==4 || month==6 || month==9 || month==11){
			if(day<1 || day>30){
				answer[j][0]=-1;
				continue;
			}
		}
		else if(month==2){
			if(day<1 || day>29){
				answer[j][0]=-1;
				continue;
			}
		}
		else{
			answer[j][0]=-1;
			continue;
		}
		answer[j][0]=year;
		answer[j][1]=month;
		answer[j][2]=day;
	}
	
	for(int i=0; i<t; i++){
		if(answer[i][0]==-1){
			cout<<"#"<<i+1<<" -1"<<endl;
		}
		else{
			printf("#%d %04d/%02d/%02d\n", i+1, answer[i][0], answer[i][1], answer[i][2]);
		}
	}
	
	return 0;
}
