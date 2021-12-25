class Solution(object):
    def calculate(self, s):
        stack = []
        sign = '+'
        num = 0
        for i in range(len(s)):
            c = s[i]
            if c.isdigit():
                num = num*10+int(c)
            if i + 1 == len(s) or (c == '+' or c == '-' or c == '*' or c == '/'):
                if sign == '+':
                    stack.append(num)
                elif sign == '-':
                    stack.append(-num)
                elif sign == '*':
                    stack[-1] = stack[-1]*num
                elif sign == '/':
                    stack[-1] = int(stack[-1]/float(num))
                sign = c
                num = 0
        # O(n) as we iterate the stack to sum
        return sum(stack)