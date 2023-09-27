#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int r,c;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int cal_min_dist(const vector<string>& maps, pair<int,int> src, pair<int,int> dest){
    bool visited[100][100] = {0, };
    int time = -1;
    
    queue<pair<pair<int,int>, int>> q;
    q.push({src, 0});
    visited[src.first][src.second] = true;
    
    while(!q.empty()){
        int cur_x = q.front().first.first;
        int cur_y = q.front().first.second;
        int cur_time = q.front().second;
        q.pop();
        
        if(cur_x == dest.first && cur_y == dest.second){
            time = cur_time;
        }
        
        for(int i=0;i<4;i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            
            if(nx < 0 || nx > r-1 || ny < 0 || ny > c-1) continue;
            if(visited[nx][ny] || maps[nx][ny] == 'X') continue; 
            
            q.push({{nx,ny}, cur_time + 1});
            visited[nx][ny] = true;
        }
    }
    
    return time == -1 ? 0 : time;
}

int solution(vector<string> maps) {
    r = maps.size();
    c = maps[0].length();
    
    pair<int, int> start, lever, dest;
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(maps[i][j] == 'S'){
                start = make_pair(i,j);
            }
            else if(maps[i][j] == 'L'){
                lever = make_pair(i,j);
            }
            else if(maps[i][j] == 'E'){
                dest = make_pair(i,j);
            }
        }
    }
    
    int start_to_lever_dist = cal_min_dist(maps, start, lever);
    int lever_to_dest_dist = start_to_lever_dist ? cal_min_dist(maps, lever, dest) : -1;
    
    return (lever_to_dest_dist == -1 || !lever_to_dest_dist) ? -1 : start_to_lever_dist + lever_to_dest_dist;
}