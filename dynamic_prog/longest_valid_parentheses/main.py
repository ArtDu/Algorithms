class Solution:
    def longestValidParentheses(self, s: str) -> int:
        mem = [0] * len(s)

        longest = 0

        for i in range(1, len(s)):

            if s[i] == ')':
                if s[i - 1] == '(':
                    mem[i] = (mem[i - 2] if i >= 2 else 0) + 2
                elif s[i - 1] == ')':
                    if (i - mem[i - 1] - 1) >= 0 and s[i - mem[i - 1] - 1] == '(':
                        mem[i] = mem[i - 1] + 2 + (mem[i - mem[i - 1] - 2] if i - mem[i - 1] - 2 >= 0 else 0)
                longest = max(longest, mem[i])
        return longest


s = input()
sol = Solution()

print(sol.longestValidParentheses(s))
