class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        return bool(matrix) and target in matrix[bisect.bisect(matrix, [target + 0.5]) - 1]