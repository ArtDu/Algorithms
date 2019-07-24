class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        mem = {}

        def dp(i, j):
            if (i, j) not in mem:
                ans = False
                if j == len(p):
                    ans = i == len(s)
                elif i < len(s) and p[j] in {s[i], '?'}:
                    ans = dp(i + 1, j + 1)
                elif p[j] == '*':
                    ans = dp(i, j + 1) or (i < len(s) and dp(i + 1, j))
                mem[i, j] = ans

            return mem[i, j]

        return dp(0, 0)


s = input()
p = input()
sol = Solution()

print(sol.isMatch(s, p))
