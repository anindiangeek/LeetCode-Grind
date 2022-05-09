class Solution {
public:
    vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;    
vector<string> letterCombinations(string digits) {
	if(digits == "") return ans;         // no combinations formed without any digits
	helper(digits, 0, "");              
	return ans;
}
// recursive helper function
void helper(string &digits, int i, string combi){	
	if(i == size(digits))   // base condition - push when we have recursed for all digits
		ans.push_back(move(combi));    
	else // add and recurse for each character (chosen from current digit-charcter mapping)
		for(auto c : mappings[digits[i] - '2']) // <= -2 bcoz digits are in range ['2','9']. We need to convert them to indices from 0 to 8 for indexing mappings.
			helper(digits, i + 1, combi + c);
}
};