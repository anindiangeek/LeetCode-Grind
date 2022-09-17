class Solution {
    public:
    inline bool isPalindrome(const string &s, int l, int r) {
        while(l < r && s[l] == s[r]) {
            l++;
            r--;
        }
        return l >= r;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        // groups of words sorted by size
        map<int, unordered_map<string, int>> mm;
        for(int i=0; i<words.size(); i++) {   // O(n*log(k))
            mm[words[i].size()][string(words[i].rbegin(), words[i].rend())] = i;
        }
        
        vector<vector<int>> res;
        for(int i=0; i < words.size(); i++) { // O(n*k*k)
            auto w = words[i];
            
            for(auto & [k, m] : mm) {
                if (k > w.size()) break;
                
                // same len word, add only once, for other word will add again as well
                if (k == w.size()) {
                    if (m.count(w) && m[w] != i) {
                        res.push_back({i, m[w]});
                    }
                    break;
                }
                
                // check back
                if (isPalindrome(w, k, w.size() - 1)) {
                    auto tgt = w.substr(0, k);
                    if (m.count(tgt)) {
                        res.push_back({i, m[tgt]});
                    }
                }

                // check front
                if (isPalindrome(w, 0, w.size() - k - 1)) {
                    auto tgt = w.substr(w.size() - k);
                    if (m.count(tgt)) {
                        res.push_back({m[tgt], i});
                    }
                }
            }
        }

        return res;
    }
};