#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

int input(string method[][32], int &n, int &k1, int &k2);
void call(string method[][32], string out[], int &n, int &k1, int &k2);
int getIdx1(string& target, string method[][32], int n);
void output(string out[]);

int main(){
	int n, k1, k2; cin >> n;
	string method[n][32];
	input(method, n, k1, k2);
	string out[2] = {"NONE", "NONE"};
	call(method, out, n, k1, k2);
	output(out);
}

int input(string method[][32], int &n, int &k1, int &k2){
	 cin >> k1 >> k2;
	for(int i=0;i<n;i++){
		for(int j=0;j<32;j++){
			cin >> method[i][j];
			if(method[i][j] == "$") break;
		}
	}
}

void call(string method[][32], string out[], int &n, int &k1, int &k2){
	int cnt = 1;
	int idx1 = 0;
	int idx2 = 1;
	int isCycle[n] = {1, 0, 0, 0,};
	stack<int> previous_idx1;
	stack<int> previous_idx2;
	while(true){
		if(method[idx1][idx2] == "$"){
			if(previous_idx1.empty()) break;
			isCycle[idx1] = 0;
			idx1 = previous_idx1.top();
			idx2 = previous_idx2.top() + 1;
			previous_idx1.pop();
			previous_idx2.pop();
			continue;
		}

		if(isupper(method[idx1][idx2][0])){
			previous_idx1.push(idx1);
			previous_idx2.push(idx2);
			idx1 = getIdx1(method[idx1][idx2], method, n);
			idx2 = 1;
			if(isCycle[idx1] == 1){
				out[0] = "DEADLOCK";
				out[1] = "";
				break;
			}
			isCycle[idx1] = 1;
			continue;
		}

		if(cnt == k1){
			out[0] = method[idx1][0] + "-" + method[idx1][idx2];
		}
		if(cnt == k2){
			out[1] = method[idx1][0] + "-" + method[idx1][idx2];
		}
		cnt++;
		idx2++;
	}
}

int getIdx1(string& target, string method[][32], int n){
	int i;
	for(i=0; i<n; i++){
		if(target.compare(method[i][0])==0) break;
	}
	return i;
}

void output(string out[]){
	cout << out[0] << "\n";
	cout << out[1] << "\n";
}