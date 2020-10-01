//https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    int fromCenter(string s, int l, int r){
    while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--; r++;
        }
        return r - l - 1;
    }

    string longestPalindrome(string s) {
        int mx = 0, start = 0, end = 0;
        for(int i = 0; i < s.size(); ++i){
            int c1 = fromCenter(s, i, i);
            int c2 = fromCenter(s, i, i + 1);
            int l_mx = max(c1,c2);
            if(l_mx > mx){
                mx = l_mx;
                start = i - (mx - 1) / 2;
                end = i + mx / 2;
            }
        }
        string ans = s.substr(start, end - start + 1);
        return ans;
    }
};
