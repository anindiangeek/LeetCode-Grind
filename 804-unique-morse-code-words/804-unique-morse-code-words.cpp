class Solution {
public:
        vector<string> v{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    string convert(string word)
    {
        string s = "";
        for (auto letter : word)
            s += v[letter - 'a'];
        return s;
    }
    int uniqueMorseRepresentations(vector<string> &words)
    {
        unordered_set<string> HashSet;

        for (auto word : words)
            HashSet.insert(convert(word));

        return HashSet.size();
    }
};