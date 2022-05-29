class Solution:
    def maxProduct(self, words: List[str]) -> int:
	    mask, ans = [0]*len(words), 0
	    for i, word in enumerate(words):
		    for ch in word:
			    mask[i] |= 1 << (ord(ch) - ord('a'))
		    for j in range(i):
			    if not mask[i] & mask[j]:
				    ans = max(ans, len(words[i]) * len(words[j]))
	    return ans
        