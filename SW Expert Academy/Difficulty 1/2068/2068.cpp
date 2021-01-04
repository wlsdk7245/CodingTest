#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int result[1000]={0};
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int temp;
		int max=0;
		for(int i=0; i<10; i++)
		{
			cin>>temp;
			if(max<=temp){
				max=temp;
			}
		}
		result[test_case]=max;
	}
	
	for(int j=1; j<=3; j++)
	{
		cout<<"#"<<j<<" "<<result[j]<<endl;
	}
	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
