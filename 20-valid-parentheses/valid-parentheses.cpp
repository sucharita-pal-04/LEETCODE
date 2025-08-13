/*
------------------------------------------------------------
LeetCode 20 - Valid Parentheses
------------------------------------------------------------
Problem Explanation (Hinglish):
--------------------------------
Hume ek string di gayi hai jo sirf '(', ')', '{', '}', '[' aur ']' characters rakhti hai.
Hume check karna hai ki string "valid" hai ya nahi.

Valid ka matlab:
1. Har opening bracket ka ek matching closing bracket hona chahiye.
2. Brackets properly nested hone chahiye.
   Example:
   - "()"  -> valid
   - "()[]{}" -> valid
   - "(]"  -> invalid
   - "([)]" -> invalid
   - "{[]}" -> valid

Real life analogy:
-------------------
Socho tum ek cupboard kholte ho aur phir band karte ho.  
Pehle jo cupboard open hua, wahi sabse pehle close hona chahiye (LIFO order).  
Yahi stack ka concept hai.

Constraints ka meaning:
------------------------
- 1 <= string.length <= 10^4  (Means max 10,000 characters)
- String sirf 6 types ke characters rakhegi: '(', ')', '{', '}', '[', ']'

------------------------------------------------------------
Brute Force Approach:
------------------------------------------------------------
Idea:
- Har closing bracket ke liye pichle opening bracket ko check karo
- Agar galat matching mili → invalid
- Agar end me koi opening bracket bacha hua hai → invalid

Steps:
1. Har character ko traverse karo.
2. Agar opening bracket mila → kisi array/list me daalo.
3. Agar closing bracket mila → uske matching opening bracket ko array ke end se check karo.
4. Agar mismatch hua → invalid.
5. End me agar array empty hai → valid, else invalid.

Complexity:
- Time Complexity: O(n^2) (Kyuki agar hum manually har baar matching search kare to worst case me nested loop ho sakta hai)
- Space Complexity: O(n)

Brute Force Code:
------------------------------------------------------------
bool isValidBrute(string s) {
    string temp = "";
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            temp.push_back(c);
        } else {
            if (temp.empty()) return false;
            char last = temp.back();
            if ((c == ')' && last != '(') ||
                (c == '}' && last != '{') ||
                (c == ']' && last != '[')) {
                return false;
            }
            temp.pop_back();
        }
    }
    return temp.empty();
}

------------------------------------------------------------
Optimized Approach:
------------------------------------------------------------
Concept (Mental Hook):
- Stack ka use karo (LIFO structure)
- Jab opening bracket mile → stack me push karo
- Jab closing bracket mile → stack ka top check karo:
   → Agar matching opening bracket mila → pop
   → Agar mismatch → invalid
- End me stack empty hona chahiye

Formula ya reasoning:
- Matching pairs:
   '(' ↔ ')'
   '{' ↔ '}'
   '[' ↔ ']'
- Stack ensure karta hai ki sabse latest open hua bracket sabse pehle close ho.

Time Complexity: O(n) (Har character ek hi baar process hota hai)
Space Complexity: O(n) (Worst case sab opening brackets ho)

------------------------------------------------------------
Optimized Code with Detailed Comments:
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
        stack<char> st;  // Stack to store opening brackets
        int n = str.length();

        for (int i = 0; i < n; i++) {
            char ch = str[i];

            // If current char is an opening bracket → push to stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            else {
                // If stack empty but closing bracket found → invalid
                if (st.empty()) return false;

                // Check top of stack
                char topChar = st.top();
                st.pop();

                // Matching check
                if ((ch == ')' && topChar != '(') ||
                    (ch == '}' && topChar != '{') ||
                    (ch == ']' && topChar != '[')) {
                    return false;
                }
            }
        }

        // If stack empty → valid, else invalid
        return st.empty();
    }
};

/*
------------------------------------------------------------
All-in-One Revision Notes:
------------------------------------------------------------
✅ Stack ka use karo kyuki LIFO pattern hai.
✅ Opening brackets push hote hain, closing brackets par match check hota hai.
✅ Mismatch → directly return false.
✅ End me stack empty hona chahiye → valid.

Time: O(n)
Space: O(n)
------------------------------------------------------------
Dry Run Example:
Input: "{[]}"
Stack: 
  '{' push → stack = { '{' }
  '[' push → stack = { '{', '[' }
  ']' pop '[' → match
  '}' pop '{' → match
Stack empty → VALID
------------------------------------------------------------
*/


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
