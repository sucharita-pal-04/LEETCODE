class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                if (!st.empty()) {
                    st.pop(); // remove last valid char
                }
                s.erase(i, 1); // remove star from string
                i--; // adjust index after erase
            } else {
                st.push(s[i]);
            }
        }

        // Build result from stack
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
