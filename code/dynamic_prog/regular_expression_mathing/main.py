# https://leetcode.com/problems/regular-expression-matching/
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        mem = {}

        def dp(i, j):

            if (i, j) not in mem:
                if len(p) == j:
                    ans = len(s) == i
                else:
                    fst_match = i < len(s) and p[j] in {s[i], '.'}
                    if j + 1 < len(p) and p[j + 1] == '*':
                        ans = dp(i, j + 2) or (fst_match and dp(i + 1, j))
                    else:
                        ans = fst_match and dp(i + 1, j + 1)
                mem[i, j] = ans
            return mem[i, j]

        return dp(0, 0)


t, p = input(), input()

sol = Solution()

print(sol.isMatch(t, p))
