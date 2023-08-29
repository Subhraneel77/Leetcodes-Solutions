class Solution:
    def bestClosingTime(self, customers: str) -> int:
        max_score = 0
        score = 0
        right_time = -1
        for i in range(len(customers)):
            score += 1 if customers[i] == 'Y' else -1
            if score > max_score:
                max_score = score
                right_time = i
        return right_time + 1