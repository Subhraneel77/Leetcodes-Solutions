class Solution:
       def maximumBags(self, capacity, rocks, x):
        count = sorted(c - r for c,r in zip(capacity, rocks))[::-1]
        while count and x and count[-1] <= x:
            x -= count.pop()
        return len(rocks) - len(count)
        