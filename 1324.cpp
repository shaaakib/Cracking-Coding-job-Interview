#include <bits/stdc++.h>
using namespace std;

vector<string> printVertically(string s) {
    
    vector<string> words;
    s += ' ';
    string temp;
    for (auto it : s) {
        if (it == ' ') {
            words.push_back(temp);
            temp.clear();
        }
        else temp += it;
    }

    int maxWordLength = 0;
    for (auto it : words) {
        int currentWordLength = it.size();
        maxWordLength = max(maxWordLength, currentWordLength);
    }
    
    vector<string> ans;
    for (int j = 0; j < maxWordLength; j++) {
        string temp;
        for (int i = 0; i < words.size(); i++) {
            if (j < words[i].size())  temp += words[i][j];
            else temp += ' ';
        }
        while (temp.back() == ' ') temp.pop_back();
        ans.push_back(temp);
        temp.clear();
    }
    return ans;
}

int main() {

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

   string input;
    getline(cin, input);
    vector<string> result = printVertically(input);

    for (string line : result) {
        cout << line << endl;
    }

    return 0;
}
