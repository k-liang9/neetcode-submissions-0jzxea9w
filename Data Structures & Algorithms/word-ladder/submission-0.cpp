class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //convert all words into graph, where 2 words are adjacent if they can be directly connected with each other: O(V^2)
        //once graph is built, use bfs to traverse the graph starting from beginWord: O(E) time
        wordList.push_back(beginWord);

        vector<vector<int>> adj(wordList.size());
        unordered_map<string, int> words;
        vector<bool> visited(wordList.size(), false);

        bool has_end_word = false;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == endWord) {
                has_end_word = true;
            }
            words[wordList[i]] = i;
        }
        if (!has_end_word) return 0;

        for (int i = 0; i < wordList.size(); i++) {
            string word = wordList[i];
            for (int j = 0; j < word.length(); j++) {
                char orig = word[j];
                for (int k = 0; k < 26; k++) {
                    char ch = 'a' + k;
                    if (ch == orig) {
                        continue;
                    }
                    
                    word[j] = ch;

                    if (words.count(word)) {
                        adj[i].push_back(words[word]);
                    }
                }
                word[j] = orig;
            }
        }

        queue<int> q;
        q.push(wordList.size()-1);
        visited[wordList.size()-1] = true;
        int tfs = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int n = q.front();
                q.pop();
                

                string str = wordList[n];
                if (str == endWord) {
                    return tfs;
                }

                for (int id : adj[n]) {
                    if (!visited[id]) {
                        visited[id] = true;
                        q.push(id);
                    }
                }
            }
            tfs++;
        }

        return 0;
    }
};
