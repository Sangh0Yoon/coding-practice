#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// while(n--) 때문에 n값이 계속바뀌는걸 인지못하고 삽질했음..

vector<int> x, y, t, dist, direction;
int total;

void Input(){
    int n,xx,yy; cin >> n;
    while(n--){
        cin >> xx >> yy;
        x.push_back(xx);
        y.push_back(yy);
    }
    x.push_back(x[0]);
    y.push_back(y[0]);
    int time;
    for(int i=0;i<5;i++){
        cin >> time;
        t.push_back(time);
    }
}

void CalDist(){ //방향도 추가했음.
    for(int i=0;i<x.size()-1;i++){
        dist.push_back((x[i+1]-x[i]) + (y[i+1]-y[i])); //아직 음수값있음.
        if(dist[i]>0){direction.push_back(1);}
        else{direction.push_back(-1);}
        dist[i] = abs(dist[i]);
    }
}

void TotalDist(){ //한바퀴 돌았을 때 총 거리. 46
    for(int i=0;i<dist.size();i++){
        total += dist[i];
    }
}

void Robocap(){
    int idx = 0;
    for(int i=0;i<5;i++){
        while(t[i]>0){ //시간이 남았으면 계속, 시간전부 소요되면 중지.
            if(t[i]<total){
                t[i] -= dist[idx];
                idx++;
            } else{
                t[i] -= total;
            }
        }
        //홀수는 y축 짝수는 x축.
        //방향고려를 해야하는데,,,
        if(idx%2==0){
            if(direction[idx-1]>0)
                cout << x[idx]+t[i] << " " << y[idx] << endl;
            else
                cout << x[idx]+abs(t[i]) << " " << y[idx] << endl;
        }
        else{
            if(direction[idx-1]>0)
                cout << x[idx] << " " << y[idx] + t[i] << endl;
            else
                cout << x[idx]<< " " << y[idx] +abs(t[i]) << endl;
        }
        idx = 0;
    }
}

int main(){
    Input();
    CalDist();
    TotalDist();
    Robocap();
}