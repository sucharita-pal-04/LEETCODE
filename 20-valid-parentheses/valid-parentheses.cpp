class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        int n = str.length();

        for (int i = 0; i < n; i++) {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                st.push(str[i]);
            } else {
                if (st.empty()) return false;
                char p = st.top();
                st.pop();
                if ((str[i] == ')' && p == '(') ||
                    (str[i] == '}' && p == '{') ||
                    (str[i] == ']' && p == '[')) {
                    continue;
                }
                return false;
            }
        }

        return st.empty();
    }
};
