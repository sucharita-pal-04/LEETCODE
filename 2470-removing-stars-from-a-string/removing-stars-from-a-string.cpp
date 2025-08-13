class Solution {
public:
    string removeStars(string s) {
        string st; // acts like a stack

        for (char c : s) {
            if (c == '*') {
                if (!st.empty()) {
                    st.pop_back(); // remove last char
                }
            } else {
                st.push_back(c); // push into "stack"
            }
        }
        return st; // already the final string
    }
};
