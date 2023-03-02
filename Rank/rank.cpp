#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Student{
    string name;
    vector<int> score;

    bool operator<(Student s){
        if(score.size() != s.score.size()){
            return score.size() > s.score.size();
        }
        else{
            for(int i=0;i<score.size();i++){
                if(score[i] != s.score[i]){return score[i] > s.score[i];}
            }
            return name < s.name;
        }
    }
};

vector<Student> report;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n; cin >> n;
    for(int i=0;i<n;i++){
        string temp_n; cin >> temp_n;
        vector<int> s; int temp_s;
        while(cin >> temp_s){
            if(temp_s == 0) break;
            s.push_back(temp_s);
        }
        sort(s.begin(), s.end());
        report.push_back({temp_n, s});
    }

    sort(report.begin(), report.end());

    for(auto& ss : report){
        cout << ss.name << endl;
    }
}