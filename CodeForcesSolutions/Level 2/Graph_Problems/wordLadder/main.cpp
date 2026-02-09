#include <bits/stdc++.h>
using namespace std;
string beginWord,endWord;
vector<string> wordList;
unordered_set<string> wordSet;
int BFS() {
    wordSet.insert(wordList.begin(),wordList.end());
    queue<pair<string,int>> q;
    q.push({beginWord,1});
    wordSet.erase(beginWord);
    while (!q.empty()) {
        auto[word,steps]=q.front();
        q.pop();
        if (word==endWord) {return steps;}
        for (int i = 0; i < word.length(); i++) {
            string temp=word;
            for (char c='a';c<='z';c++) {
                temp[i]=c;
                if (wordSet.find(temp)==wordSet.end()) {
                    q.push({temp,steps+1});
                    wordSet.erase(temp);
                }
            }
        }
        return 0;
    }
}
int main() {




}