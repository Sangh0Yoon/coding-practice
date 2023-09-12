#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> board) {
    int answer = 1;
    int num_o = 0;
    int num_x = 0;
    int num_empty = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] == 'O'){
                num_o++;
            }
            else if(board[i][j] == 'X'){
                num_x++;
            }
            else{
                num_empty++;
            }
        }
    }
    
    // X가 O보다 더 많은 경우(O가 0개인 경우도 포함)(X가 5개 이상인것도 포함)
    if(num_x > num_o){
        answer = 0;
    }
    // X와 O의 개수가 2개 이상 차이날 경우
    else if(num_o - num_x >= 2){
        answer = 0;
    }
    // X와 O가 1줄이 동시에 완성되는 경우(123,456,789,147,258,369,159,357)
    else if(num_o == 3 and num_x == 3){
        answer = 0;
    }
        
    return answer;
}