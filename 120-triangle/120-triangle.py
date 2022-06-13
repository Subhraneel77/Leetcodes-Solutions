class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        @cache
        def dfs(i, j):
            if i == len(triangle):
                return 0

            lower_left = triangle[i][j] + dfs(i + 1, j)
            lower_right = triangle[i][j] + dfs(i + 1, j + 1)

            return min(lower_left, lower_right)

        return dfs(0, 0)