#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int num;
    int bSize=board.size();
    int mSize=moves.size();
    vector<int> result;
    
    for(int i=0; i<mSize; i++){
        num=moves.at(i);
        for(int j=0; j<bSize; j++){
            if(board[j][num-1]!=0){
                result.push_back(board[j][num-1]);
                board[j][num-1]=0;
                if(result.size()>=2){
                    if(result.back()==result[result.size()-2]){
                        result.pop_back();
                        result.pop_back();
                        answer+=2;   
                    }
                }
                break;
            }
        }
    }
    return answer;
}
