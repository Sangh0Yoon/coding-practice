#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void input(queue<int> Q[], int &n);
int getMaxQSize(queue<int> Q[], int &n);
void detPrio(queue<int> Q[], int &n, int &max);
int findMin(queue<int> Q[], int &n);
void output(queue<int> Q[], int &idx);

int main(){
    int n; cin >> n;
    queue<int> Q[20];
    input(Q,n);
    int max;
    max = getMaxQSize(Q,n);
    detPrio(Q,n,max);
}

void input(queue<int> Q[], int &n){
    int id;
    for(int i=0;i<n;i++){
        while(cin >> id){
            Q[i].push(id);
            if(id == 0) break;
        }
    }
}
int getMaxQSize(queue<int> Q[], int &n){
    int m = -1;
    for(int i=0;i<n;i++){
        if(Q[i].size() > m){
            m = Q[i].size();
        }
    }
    return m;
}
void detPrio(queue<int> Q[], int &n, int &max){
    int j = 0;
    int min_idx;
    int cnt = 1;
    while(true){
        min_idx = findMin(Q,n);
        output(Q,min_idx);
        Q[min_idx].pop();
        cnt++;
        if(cnt == max) break;
    }
}
int findMin(queue<int> Q[], int &n){
    int idx;
    int m = 20000;
    for(int i=0;i<n;i++){
        if(Q[i].front() <= m && Q[i].front() != 0){
            if(Q[i].front() == m){
                continue;
            }
            if(Q[i].front())
            m = Q[i].front();
            idx = i;
        }
    }
    return idx;
}
void output(queue<int> Q[], int &min_idx){
    cout << Q[min_idx].front() << endl;
}