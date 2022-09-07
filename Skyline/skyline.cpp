#include <iostream>
using namespace std;

int n;
int x[10000], v[10000], h[10000]; //순서대로 시작점, 높이, 너비
int skyline[1000000];
int start = 99999, last = 0;

void Input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i] >> v[i] >> h[i];
    }
}

void FindStartEnd(){ //스카이라인의 x축 시작과 끝을 찾음.
    for(int i=0;i<n;i++){
        if(x[i]<start) start = x[i];
        if(x[i]+h[i]>last) last = x[i] + h[i];
    }
}

void MakeSkyline(){ //x축에 높이정보가 저장되어있다고 생각하면 됨.
    for(int i=0;i<n;i++){
        for(int j=x[i];j<x[i]+h[i];j++){
            if(v[i]>skyline[j]) skyline[j] = v[i];
        }
    }
}

void PrintResult(){ // 앞에것과 높이가 다르면 차이를 계산.
    cout << start << " ";
    int garo = 0;
    for(int i=start;i<=last;i++){
        if(skyline[i]!=skyline[i-1]){
            if(i==start) {cout << skyline[i] << " ";}
            else{
                cout << garo << " " << skyline[i] - skyline[i-1] << " ";
                garo = 0;
            }
        }
        garo++;
    }
}

int main(){
    Input();
    FindStartEnd();
    MakeSkyline();
    PrintResult();
}