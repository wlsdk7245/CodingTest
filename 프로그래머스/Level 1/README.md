## # 크레인 인형뽑기 게임
**\[문제 설명\]**

게임개발자인 죠르디는 크레인 인형뽑기 기계를 모바일 게임으로 만들려고 합니다.
죠르디는 게임의 재미를 높이기 위해 화면 구성과 규칙을 다음과 같이 게임 로직에 반영하려고 합니다.

![](https://images.velog.io/images/wlsdk7245/post/1aa832e7-0ca4-45b1-bdfd-035b0ed76167/image.png)

게임 화면은 1 x 1 크기의 칸들로 이루어진 N x N 크기의 정사각 격자이며 위쪽에는 크레인이 있고 오른쪽에는 바구니가 있습니다. (위 그림은 5 x 5 크기의 예시입니다). 각 격자 칸에는 다양한 인형이 들어 있으며 인형이 없는 칸은 빈칸입니다. 모든 인형은 1 x 1 크기의 격자 한 칸을 차지하며 격자의 가장 아래 칸부터 차곡차곡 쌓여 있습니다. 게임 사용자는 크레인을 좌우로 움직여서 멈춘 위치에서 가장 위에 있는 인형을 집어 올릴 수 있습니다. 집어 올린 인형은 바구니에 쌓이게 되는 데, 이때 바구니의 가장 아래 칸부터 인형이 순서대로 쌓이게 됩니다. 다음 그림은 [1번, 5번, 3번] 위치에서 순서대로 인형을 집어 올려 바구니에 담은 모습입니다.

![](https://images.velog.io/images/wlsdk7245/post/007e7a16-9797-4d7a-90d4-bb8a069893c2/image.png)

만약 같은 모양의 인형 두 개가 바구니에 연속해서 쌓이게 되면 두 인형은 터뜨려지면서 바구니에서 사라지게 됩니다. 위 상태에서 이어서 [5번] 위치에서 인형을 집어 바구니에 쌓으면 같은 모양 인형 두 개가 없어집니다.

![](https://images.velog.io/images/wlsdk7245/post/63cd0fb9-f047-4a48-9f74-acfc098e063e/image.png)

크레인 작동 시 인형이 집어지지 않는 경우는 없으나 만약 인형이 없는 곳에서 크레인을 작동시키는 경우에는 아무런 일도 일어나지 않습니다. 또한 바구니는 모든 인형이 들어갈 수 있을 만큼 충분히 크다고 가정합니다. (그림에서는 화면표시 제약으로 5칸만으로 표현하였음)

게임 화면의 격자의 상태가 담긴 2차원 배열 board와 인형을 집기 위해 크레인을 작동시킨 위치가 담긴 배열 moves가 매개변수로 주어질 때, 크레인을 모두 작동시킨 후 터트려져 사라진 인형의 개수를 return 하도록 solution 함수를 완성해주세요.

**\[제한사항\]**

board 배열은 2차원 배열로 크기는 5 x 5 이상 30 x 30 이하입니다.
board의 각 칸에는 0 이상 100 이하인 정수가 담겨있습니다.
0은 빈 칸을 나타냅니다.
1 ~ 100의 각 숫자는 각기 다른 인형의 모양을 의미하며 같은 숫자는 같은 모양의 인형을 나타냅니다.
moves 배열의 크기는 1 이상 1,000 이하입니다.
moves 배열 각 원소들의 값은 1 이상이며 board 배열의 가로 크기 이하인 자연수입니다.

**\[입출력 예\]**![](https://images.velog.io/images/wlsdk7245/post/b7fb4565-dcc9-4312-8650-119b6cfb0890/image.png)

**\[입출력 예 설명\]**

입출력 예 #1

인형의 처음 상태는 문제에 주어진 예시와 같습니다. 크레인이 [1, 5, 3, 5, 1, 2, 1, 4] 번 위치에서 차례대로 인형을 집어서 바구니에 옮겨 담은 후, 상태는 아래 그림과 같으며 바구니에 담는 과정에서 터트려져 사라진 인형은 4개 입니다.

![](https://images.velog.io/images/wlsdk7245/post/a46566da-d22a-47ac-bdef-557794189fb8/image.png)


**\[첫 번째 제출\]**
```
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> stack;
    int answer = 0;
    
    for(int i=0;i<moves.size();i++) {
        for(int j=0;j<board.size();j++) {
            if(board[j][moves[i]-1]>0) {
                stack.push_back(board[j][moves[i]-1]);
                board[j][moves[i]-1] = 0;
                if(stack.size()>=2){
                    if(stack.back() == stack[stack.size()-2]) {
                        stack.pop_back();
                        stack.pop_back();
                        answer += 2;
                    }
                }
            }   
        }
    }
    return answer;
}
```
<br>

## # 완주하지 못한 선수
**\[문제 설명\]**

수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.

마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.

**\[제한사항\]**

-   마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
-   completion의 길이는 participant의 길이보다 1 작습니다.
-   참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
-   참가자 중에는 동명이인이 있을 수 있습니다.

**\[입출력 예\]**

<table style="border-collapse: collapse; width: 100%; height: 58px;" border="1" data-ke-style="style1"><tbody><tr><td style="width: 33.2558%;">participant</td><td style="width: 33.3721%;">completion</td><td style="width: 33.3721%;">return</td></tr><tr style="height: 19px;"><td style="height: 19px; width: 33.2558%;">[leo,<span>&nbsp;</span>kiki,<span>&nbsp;</span>eden]</td><td style="height: 19px; width: 33.3721%;">[eden,<span>&nbsp;</span>kiki]</td><td style="height: 19px; width: 33.3721%;">leo</td></tr><tr style="height: 10px;"><td style="height: 10px; width: 33.2558%;">[marina,<span>&nbsp;</span>josipa,<span>&nbsp;</span>nikola,<span>&nbsp;</span>vinko,<span>&nbsp;</span>filipa]</td><td style="height: 10px; width: 33.3721%;">[josipa,<span>&nbsp;</span>filipa,<span>&nbsp;</span>marina,<span>&nbsp;</span>nikola]</td><td style="height: 10px; width: 33.3721%;">vinko</td></tr><tr style="height: 19px;"><td style="height: 19px; width: 33.2558%;">[mislav,<span>&nbsp;</span>stanko,<span>&nbsp;</span>mislav,<span>&nbsp;</span>ana]</td><td style="height: 19px; width: 33.3721%;">[stanko,<span>&nbsp;</span>ana,<span>&nbsp;</span>mislav]</td><td style="height: 19px; width: 33.3721%;">mislav</td></tr></tbody></table>

**\[입출력 예 설명\]**

예제 #1  
leo는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.

예제 #2  
vinko는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.

예제 #3  
mislav는 참여자 명단에는 두 명이 있지만, 완주자 명단에는 한 명밖에 없기 때문에 한명은 완주하지 못했습니다.

**\[첫 번째 제출\]**

```
#include <string>
#include <vector>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(int i=0; i<completion.size(); i++){
        for(int j=0; j<participant.size(); j++){
            if(participant[j]==completion[i]){
                participant.erase(participant.begin()+j);
                break;
            }
        }
    }
    
    answer=participant[0];
    return answer;
}
```

위 코드는 정확도는 100%이지만 효율성이 0%로 시간 초과로 실패했다. 아마 for문을 두 번 돌리는 과정에서 배열의 크기가 커졌을 때 효율성이 떨어지는 것으로 보인다.

**\[두 번째 제출\]**

```
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i=0; i<participant.size(); i++){
        if(participant[i]!=completion[i]){
            answer=participant[i];
            break;
        }
    }
    return answer;
}
```

두 번째 방법으로, 두 벡터를 먼저 정렬하고 첫 원소부터 비교를 시작하면, 같지 않은 원소가 나올 때, participant에 있지만 completion에는 없는 원소가 존재한다는 의미이기 때문에 answer에 participant\[i\]를 넣어주었다. 또 그럴 경우 더 이상 비교를 하지 않아도 되기 때문에 break를 통해 반복문을 종료해준다. 이렇게 했더니 정확성과 효율성 테스트에서 모두 통과할 수 있었다.

검색을 해본 결과, map등의 방법을 통해 해결하는 사람들이 있는데, map에 관련된 개념은 아직 부족하기 때문에 이 부분은 보충해서 공부해야 할 것 같다. 또 애초에 이 문제의 분류가 해시이기 때문에, 해시 개념도 SW Expert Academy 사이트에서 공부를 해야한다.
<br>

## # 문자열 다루기 기본
**\[문제 설명\]**

문자열 s의 길이가 4 혹은 6이고, 숫자로만 구성돼있는지 확인해주는 함수, solution을 완성하세요. 예를 들어 s가a234이면 False를 리턴하고1234라면 True를 리턴하면 됩니다.

**\[제한 사항\]**

-   s는 길이 1 이상, 길이 8 이하인 문자열입니다.

**\[입출력 예\]**

<table style="border-collapse: collapse; width: 100%; height: 57px;" border="1" data-ke-style="style1"><tbody><tr style="height: 19px;"><td style="height: 19px;">s</td><td style="height: 19px;">return</td></tr><tr style="height: 19px;"><td style="height: 19px;">a234</td><td style="height: 19px;">false</td></tr><tr style="height: 19px;"><td style="height: 19px;">1234</td><td style="height: 19px;">true</td></tr></tbody></table>

**\[제출\]**

```
#include <string>
#include <vector>
using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.size()!=4 && s.size()!=6){
        return false;
    }
    for(int i : s){
        if(i<48 || i>57){
            return false;
        }
    }
    return answer;
}
```

제일 먼저, 문자열 s의 길이를 구해서 4나 6이 아닌 경우, false를 리턴한다. 원래 answer에 bool값을 넣으려 했는데, 그렇게 하면 사이즈가 틀린 경우에도 for문을 돌려서 비효율적인 것 같아서 바로 리턴을 했다. 그 다음 for문을 보면 먼저 0의 ASCII값이 48이고 9의 ASCII값이 57이기 때문에 0미만, 9초과인 경우 false를 리턴하게끔 했다.

for(int i: s)는 범위기반 for문으로 python에서 내가 가장 좋아했던 기능이다! c++에도 있어서 애용하는 중이다.
<br>

## # 소수 찾기
**\[문제 설명\]**

1부터 입력받은 숫자 n 사이에 있는 소수의 개수를 반환하는 함수, solution을 만들어 보세요.

소수는 1과 자기 자신으로만 나누어지는 수를 의미합니다.  
(1은 소수가 아닙니다.)

**\[제한 조건\]**

-   n은 2이상 1000000이하의 자연수입니다.

**\[입출력 예\]**

<table style="border-collapse: collapse; width: 100%;" border="1" data-ke-style="style1"><tbody><tr><td>n</td><td>result</td></tr><tr><td>10</td><td>4</td></tr><tr><td>5</td><td>3</td></tr></tbody></table>

**\[입출력 예 설명\]**

입출력 예 #1  
1부터 10 사이의 소수는 \[2,3,5,7\] 4개가 존재하므로 4를 반환

입출력 예 #2  
1부터 5 사이의 소수는 \[2,3,5\] 3개가 존재하므로 3를 반환

숫자를 계속 나눠서 나뉘는 숫자가 없을 때 마다 answer++; 를 하는 알고리즘을 짰는데, 시간 초과로 효율성 테스트에서 실패했다. 구글링 결과 에라토스테네스의 체 알고리즘으로 짜야하는 문제라는 것을 알게 되었다.

**\[첫 번째 제출\]**

```
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int arr[]={0};
    for(int i=2; i*i<n; i++){
        if(arr[i] == 0){
            for(int j = 2; j<=n;j++){
                if(j*i <= n){
                    arr[j*i] = 1;
                }
            }
        }
    }
    for(int i = 0;i<=n;i++){
        cout<<arr[i]<<endl;
        if(arr[i]==0) answer++;
    }
    
    
    return answer;
}
```

이렇게 하면 될 줄 알았는데... 에라토스테네스의 체 알고리즘이라고 나름 짠 건데 실행이 되지 않는다.....

출력을 해보니까 arr\[j\*i\]=1; 부분에서 그 부분 뿐 아니라 모든 배열 요소가 1로 초기화가 되는 것 같다. 이유가 뭔지는 모르겠지만 일단 수정을 해봤다.

**\[두 번째 제출\]**

```
#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;
    int *arr = new int[n]();
    
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
```

이번에는 중간에 signal : aborted (core dumpled) 오류가 떴다. 효율성 테스트도 통과하고 테스트도 3개를 제외하고 다 통과했는데 무슨 문제가 있는 거지...

**\[세 번째 제출\]**

```
#include <string>
#include <vector>
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
```

문제를 바로 찾았다!!! solution 안에 들어오는 n 변수의 값은 배열 index가 아니라 5일 경우 5까지 검사를 해야하는 숫자이기 때문에 초기화하는 과정에서 n+1까지 크기를 만들어야 한다. 따라서 밑에 for문에서도 2부터 비교를 하고, 두 번째 for문에서도 0이 아닌 1부터 비교를 하는 것이다. 이것도 충분하지만, 필요하지 않은 index가 0인 경우를 빼려면 밑에 for문의 index를 -1씩 다 해주면 될 것 같긴 한데, 그렇게 되면 숫자가 헷갈릴 수도 있기 때문에 고치지 않았다.
<br>

## # 두 개 뽑아서 더하기
**\[문제 설명\]**

정수 배열 numbers가 주어집니다. numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록 solution 함수를 완성해주세요.

**\[제한사항\]**

-   numbers의 길이는 2 이상 100 이하입니다.
    -   numbers의 모든 수는 0 이상 100 이하입니다.

**\[입출력 예\]**

<table style="border-collapse: collapse; width: 100%;" border="1" data-ke-style="style1"><tbody><tr><td>numbers</td><td>result</td></tr><tr><td>[2,1,3,4,1]</td><td>[2,3,4,5,6,7]</td></tr><tr><td>[5,0,2,7]</td><td>[2,5,7,9,12]</td></tr></tbody></table>

**\[입출력 예 설명\]**

입출력 예 #1

-   2 = 1 + 1 입니다. (1이 numbers에 두 개 있습니다.)
-   3 = 2 + 1 입니다.
-   4 = 1 + 3 입니다.
-   5 = 1 + 4 = 2 + 3 입니다.
-   6 = 2 + 4 입니다.
-   7 = 3 + 4 입니다.
-   따라서\[2,3,4,5,6,7\]을 return 해야 합니다.

입출력 예 #2

-   2 = 0 + 2 입니다.
-   5 = 5 + 0 입니다.
-   7 = 0 + 7 = 5 + 2 입니다.
-   9 = 2 + 7 입니다.
-   12 = 5 + 7 입니다.
-   따라서\[2,5,7,9,12\]를 return 해야 합니다.

**\[제출\]**

```
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> arr;
    
    for(int i=0; i<numbers.size(); i++){
        for(int j=0; j<numbers.size(); j++){
            if(i!=j){
                arr.push_back(numbers[i]+numbers[j]);
            }
        }
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size()-1; i++){
        cout<<arr[i]<<endl;
        if(arr[i]==arr[i+1]){
            arr[i]=-1;
        }
    }
    for(int j=0; j<arr.size(); j++){
        if(arr[j]!=-1){
            answer.push_back(arr[j]);
        }
    }
    return answer;
}
```

algorithm 헤더를 사용하면 sort함수를 사용할 수 있지만, 만약 헤더 사용에 제한이 있는 시험이라면 사용할 수 없기 때문에, insertion sort나 bubble sort 등 기본적인 sort들을 공부해야겠다.
<br>

## # 2016년
**\[문제 설명\]**

2016년 1월 1일은 금요일입니다. 2016년 a월 b일은 무슨 요일일까요? 두 수 a ,b를 입력받아 2016년 a월 b일이 무슨 요일인지 리턴하는 함수, solution을 완성하세요. 요일의 이름은 일요일부터 토요일까지 각각SUN,MON,TUE,WED,THU,FRI,SAT

입니다. 예를 들어 a=5, b=24라면 5월 24일은 화요일이므로 문자열TUE를 반환하세요.

**\[제한 조건\]**

-   2016년은 윤년입니다.
-   2016년 a월 b일은 실제로 있는 날입니다. (13월 26일이나 2월 45일같은 날짜는 주어지지 않습니다)

**\[입출력 예\]**

<table style="border-collapse: collapse; width: 100%;" border="1" data-ke-style="style1"><tbody><tr><td>a</td><td>b</td><td>result</td></tr><tr><td>5</td><td>24</td><td>TUE</td></tr></tbody></table>

**\[제출\]**

```
#include <string>
#include <vector>
using namespace std;

string DATE[7]={"FRI","SAT","SUN","MON","TUE","WED","THU"};
int Day_Of_Month[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string solution(int a, int b) {
    string answer = "TUE";
    
    int cnt=0;
    
    for(int i=0; i<a; i++){
        cnt+=Day_Of_Month[i-1];
    }
    cnt+=b;
    cnt%=7;
    
    switch (cnt){
        case 0:       
            answer=DATE[6];
            break;
        case 1:
            answer=DATE[0];
            break;
        case 2:
            answer=DATE[1];
            break;
        case 3:
            answer=DATE[2];
            break;
        case 4:
            answer=DATE[3];
            break;
        case 5:
            answer=DATE[4];
            break;
        case 6:
            answer=DATE[5];
            break;
        default:
            break;
    }
    
    
    
    return answer;
}
```

각 월의 일수를 Day\_of\_Month 안에 넣는다. for문을 통해 cnt에 a월 까지의 일수를 더한다. 또 a월의 b일이기 때문에, b일도 마저 더해준다. 이를 7로 나누면 나머지가 0부터 6의 숫자가 나오는데, 이는 2016년 1월 1일이 금요일이기 때문에, 이를 이용해 요일을 계산할 수 있는 것이다. 따라서 cnt를 7로 나눈 나머지가 0일 경우 목요일, 1일 경우 금요일... 식으로 계산된다. 이를 answer에 대입하면 된다.
<br>

