class Solution:
    def closeStrings(self, w1: str, w2: str) -> bool:
        return sorted(Counter(w1).values()) == sorted(Counter(w2).values()) \
               and set(w1) == set(w2)
