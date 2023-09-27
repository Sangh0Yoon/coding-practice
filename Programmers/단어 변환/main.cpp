#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int row, col;

int get_min_route(const vector<vector<int>> maps){
    int dist = 99999;
    bool visited[100][100] = {0, };
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},0});
    visited[0][0] = true;
    
    while(!q.empty()){
        int cur_x = q.front().first.first;
        int cur_y = q.front().first.second;
        int cur_d = q.front().second;
        q.pop();
        
        if(cur_x == row-1 && cur_y == col-1){
            dist = min(dist, cur_d+1);
        }
        
        for(int i=0;i<4;i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            if(visited[nx][ny] || maps[nx][ny] == 0) continue;
            
            q.push({{nx,ny}, cur_d+1});
            visited[nx][ny] = true;
        }
    }
    
    return dist == 99999 ? -1 : dist;
}

int solution(vector<vector<int>> maps)
{
    row = maps.size();
    col = maps[0].size();
    int min_dist = get_min_route(maps);
    
    return min_dist;
}