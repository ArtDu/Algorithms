class Solution:

    def longestPalindrome(self, s: str) -> str:
        mem = [
            [
                False for _ in range(len(s))
            ] for _ in range(len(s))
        ]

        ans = [0, 0]

        for i in range(len(s)):
            mem[i][i] = True
            if i != len(s) - 1 and s[i] == s[i+1]:
                mem[i][i + 1] = True
                ans = [i, i + 1]

        for l in range(2, len(s)):
            for i in range(0, len(s) - l):
                if (s[i] == s[i + l]) and (mem[i + 1][i + l - 1]):
                    mem[i][i + l] = True
                    ans = [i, i + l]

        return s[ans[0]:ans[1]+1]


string = input()
sol = Solution()

print(sol.longestPalindrome(string))
