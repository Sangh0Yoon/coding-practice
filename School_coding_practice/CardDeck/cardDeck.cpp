#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, K;
vector<int> deck;

void shuffle();
void cut(int idx1, int idx2);

int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        deck.push_back(i);
    }
    for(int i=0;i<K;i++){
        string cmd; cin >> cmd;
        if(cmd.compare("Cut") == 0){
            int idx1, idx2; cin >> idx1 >> idx2;
            cut(idx1, idx2);
        }
        else if(cmd.compare("Shuffle") == 0){
            shuffle();
        }
    }
    cout << deck[0] << " " << deck[N/2-1] << " " << deck[N-1] << endl;
}
void shuffle(){
    vector<int> temp;
    int half_sz = N/2;
    for(int i=0;i<half_sz;i++){
        temp.push_back(deck[i]);
        temp.push_back(deck[i+half_sz]);
    }
    deck.clear();
    for(auto k : temp){
        deck.push_back(k);
    }
}
void cut(int idx1, int idx2){
    vector<int> temp1;
    vector<int> temp2;
    for(int i=0;i<N;i++){
        if(i >= idx1-1 && i < idx2){
            temp1.push_back(deck[i]);
        }
        else{
            temp2.push_back(deck[i]);
        }
    }
    deck.clear();
    for(auto k : temp2){
        deck.push_back(k);
    }
    for(auto k : temp1){
        deck.push_back(k);
    }
}