class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        for level in range(1, len(triangle)):
            for i in range(level+1):
                triangle[level][i] += min(triangle[level-1][min(i, level-1)], triangle[level-1][max(i-1,0)])
        return min(triangle[-1])