#include <string>
#include <vector>

using namespace std;

int det_win(const vector<string>& board, char ox){
    vector<int> row(3), col(3), dia(2);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] == ox){
                row[i]++;
                col[j]++;
                if(i == j) {dia[0]++;}
                if(i+j == 2) {dia[1]++;}
                if(row[i] == 3 || col[j] == 3 || dia[0] == 3 || dia[1] == 3) return 1;
            }
        }
    }
    return 0;
}

int solution(vector<string> board) {
    int answer = 1;
    int num_o = 0, num_x = 0;
    int win_o = 0, win_x = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] == 'O'){
                num_o++;
            }
            else if(board[i][j] == 'X'){
                num_x++;
            }
        }
    }
    
    if(num_x > num_o or num_o - num_x >= 2){
        answer = 0;
    }
    
    if(num_o >= 3){
        win_o = det_win(board, 'O');
        win_x = det_win(board, 'X');
        
        if((win_o and win_x) or (win_o and (num_o == num_x)) or (win_x and (num_o > num_x))){
            answer = 0;
        }
    }
        
    return answer;
}
