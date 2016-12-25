
struct QueueData {
    string word;
    int depth;
    QueueData(const string& word, int depth):word(word),depth(depth){}
    
};

class Solution {
public:

    bool isAdjunt(const string& s1, const string& s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        int diff = 0;
        for (auto i = 0; i != s1.length(); i++) {
            diff += s1[i] == s2[i];
        }
        return diff == 1;
    }
    
    const vector<string> candidates(const string& s){
        vector<string> ans;
        for (auto i = 0; i != s.length(); i++) {
            for (auto j = 'a'; j <= 'z'; j++) {
                if (j != s[i]) {
                    string tmp = s;
                    tmp[i] = j;
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
    
    int ladderLength(const string& beginWord, const string& endWord, unordered_set<string>& wordList) {
        int ans = 0;
        queue<QueueData> q;
        q.emplace(beginWord, 1);
        set<string> usedWords;
        usedWords.insert(beginWord);
        wordList.erase(beginWord);
        
        while (!q.empty()) {
            QueueData d = q.front(); q.pop();
            int depth = d.depth;
            auto cands = candidates(d.word);
            for (auto s: cands) {
                if (s == endWord) {
                    return depth + 1;
                }
                if (wordList.find(s) != wordList.end() && usedWords.find(s) == usedWords.end()) {
                    wordList.erase(s); usedWords.insert(s);
                    q.emplace(s, depth+1);
                }
            }
        }
        return ans;
    }
};
