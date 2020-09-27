// https://leetcode.com/problems/valid-parentheses
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto &c : s){
            if(c == '(' || c == '{' || c == '[') st.push(c);
        
            else if(c == ')' || c == '}' || c == ']') {
                if(st.empty()) return false;
                
                char elem = st.top(); st.pop();
                if((elem == '(' && c == ')') ||
                   (elem == '{' && c == '}') ||
                   (elem == '[' && c == ']')
                  ) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
