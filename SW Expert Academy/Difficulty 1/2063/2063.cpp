#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
	int N;
	vector<int> num;
	
	cin>>N;
	
	for(int i=0; i<N; i++)
	{
		int temp;
		cin>>temp;
		num.push_back(temp);
	}
	sort(num.begin(), num.end());

	cout<<num.at(N/2);
	
	
	
	return 0;
}
