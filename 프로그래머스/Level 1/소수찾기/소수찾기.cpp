#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int *arr = new int[n+1]();
    
    for(int i=2; i<=n; i++){
        if(arr[i]==0){
            answer++;
            for(int j=1; i*j<=n; j++){
                arr[i*j]=1;
            }
        }
        
    }
    return answer;
}
