#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int row,col;
bool visited[200] = {0,};

void get_num_network(const vector<vector<int>>& computers, int cur_com, int n){
    visited[cur_com] = true;
    for(int i=0;i<n;i++){
        if(!visited[i] && computers[cur_com][i] == 1){
            get_num_network(computers, i, n);        
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            get_num_network(computers, i, n);
            
            answer++;
        }
    }
    
    return answer;
}
