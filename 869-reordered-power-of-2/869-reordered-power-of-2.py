class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        res = sorted([int(x) for x in str(n)])
        for i in range(30):
            if sorted([int(x) for x in str(1 << i)]) == res: return True
        return False
        