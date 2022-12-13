class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        for r in range(1, len(matrix)):
            for c in range(len(matrix[0])):
                matrix[r][c] += min(matrix[r - 1][max(0, c - 1):c + 2])
        return min(matrix[-1])