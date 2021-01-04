## # Recursion
**\[개요\]**

재귀는 수학이나 컴퓨터 과학 등에서 자신을 정의할 때 자기 자신을 재참조하는 방법을 뜻한다. 주로 이 방법은 함수에 적용한 재귀 함수(Recursion Function)의 형태로 많이 사용된다.

**\[예시문제\]**

주어진 수의 Factorial 값을 구해 아래와 같이 출력하시오. 주어지는 수는 1 이상 20 이하의 수이다.

**\[첫 번째 제출\]**

```
#include <iostream>
using namespace std;

int main(void){
	int T;
	cin>>T;
	int* answer=new int[T]();
	
	for(int i=1; i<=T; i++){
		int num;
		cin>>num;
		answer[i]=1;
		for(int j=1; j<=num; j++){
			answer[i]*=j;
		}
		cout<<"#"<<i<<" "<<num<<"! = "<<answer[i];
	}
	return 0;
}
```

이렇게 풀어서 정답은 나오지만, recursion 방법을 사용한 것이 아니기 때문에, 다시 풀었다.

**\[두 번째 제출\]**

```
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
```

recursion 방법은 사용해서 해결했지만, 마지막 20! 같은 경우 int 자료형의 메모리가 부족해서 맞지 않는 값이 출력되고 있었다. 이 부분은 정답을 보고 해결하였다.

**\[정답\]**

```
#include <iostream>
 
long long Factorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}
 
 
int main(void)
{
    int test_case;
    int T;
    int num;
    long long answer;
	
    cin>>T;
    
    for (test_case = 1; test_case <= T; ++test_case)
    {
    	cin>>num;
        answer = Factorial(num);
        cout<<"#"<<test_case<<" "<<num<<"! = "<<answer<<endl;
    }
}
```

long long타입을 쓰면 해결되는 문제!

**int 는 4바이트, long long은 8바이트**
