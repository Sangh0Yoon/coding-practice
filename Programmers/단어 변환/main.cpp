#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 999999;
int word_vec_sz, word_sz;
bool visited[50] = {0, };

void translate_alphabet(const vector<string>& words, bool* visited, string begin, string target, int time){
    int same_cnt;
    if(begin.compare(target) == 0){
        answer = min(time, answer);
        return ;
    }
    for(int i=0;i<word_vec_sz;i++){
        same_cnt = 0;
        
        if(visited[i]) continue;
        
        for(int j=0;j<word_sz;j++){
            if(begin[j] == words[i][j]){
                same_cnt++;
            }
        }
        if(same_cnt == word_sz - 1){
            visited[i] = true;
            translate_alphabet(words, visited, words[i], target, time+1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    word_vec_sz = words.size();
    word_sz = words[0].length();
    
    translate_alphabet(words, visited, begin, target, 0);
    return answer == 999999 ? 0 : answer;
}
