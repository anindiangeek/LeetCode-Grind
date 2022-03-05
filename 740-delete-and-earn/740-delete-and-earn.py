class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        a, b = 0, 0
        cnt = Counter(nums)
        for x in range(max(nums)+1):
            a, b = max(a, b), x*cnt[x] + a
        return max(a, b)