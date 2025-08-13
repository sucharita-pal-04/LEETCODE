/*
Samajh gaya ✅
Ab se tum mujhe koi bhi question doge to main tumhare liye:

Problem Explanation (Hinglish me)
Constraints ka meaning
Brute Force Approach (steps + complexity + code)
Optimized Approach ka Concept (formula + mental hook + reasoning)
Optimized Code with Detailed Comments
All-in-One Revision Note jo GitHub pe directly daal sako
*/

/*
Problem Explanation (Hinglish me):
Given ek string 's' jisme kuch characters hain aur kuch '*' stars hain.
Har '*' ka matlab hai ki usse pehle jo character hai, usko hata do.
Hume ek final string nikalni hai jisme saare stars ki wajah se characters remove ho chuke hain.

Constraints ka meaning:
- String length maximum 10^5 hai, matlab brute force O(n^2) ya usse upar solutions timeout ho sakte hain.
- Efficient O(n) solution chahiye.

Brute Force Approach:
1. String ko left se right traverse karo.
2. Jab '*' mile to uske pehle wale character ko find karo aur remove kar do.
3. Phir '*' ko remove karo.
4. Repeat karo jab tak string finish na ho jaye.

Complexity:
- Har erase O(n) lagta hai.
- Nested loop hone ki wajah se worst case O(n^2) ya O(n^3) ho sakta hai.
- Large input ke liye inefficient.

Brute Force Code:
*/

#include <string>
using namespace std;

class SolutionBruteForce {
public:
    string removeStars(string s) {
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '*') {
                for (int j = i - 1; j >= 0; j--) {
                    if (s[j] != '*') {
                        s.erase(j, 1);
                        i--;
                        break;
                    }
                }
                s.erase(i, 1);
                i--;
            } else {
                i++;
            }
        }
        return s;
    }
};

/*
Optimized Approach ka Concept:
- Stack data structure ka use karo.
- Traverse string from left to right.
- Agar character normal hai to stack me push karo.
- Agar character '*' hai to stack se top element pop kar do.
- Aakhir me stack me jo bacha hai, wo answer hai.
- Isse erase nahi karni padti string me, toh time O(n) ho jata hai.

Mental Hook:
“Push karo jab normal char mile, pop karo jab star mile” — simple LIFO logic.

Optimized Code with Detailed Comments:
*/

#include <string>
using namespace std;

class SolutionOptimized {
public:
    string removeStars(string s) {
        string st; // Stack ke jaise use kar rahe hain string ko

        for (char c : s) {
            if (c == '*') {
                if (!st.empty()) {
                    st.pop_back(); // Last character remove kar do
                }
            } else {
                st.push_back(c); // Normal character add karo
            }
        }

        return st; // Final string ready
    }
};

/*
All-in-One Revision Note:

Problem: String se stars remove karte hue, har star ke pehle character ko bhi remove karna hai.

Brute Force:
- Star pe previous char dhundo.
- Erase previous char and star from string.
- O(n^2) ya O(n^3), slow for large inputs.

Optimized:
- String ko stack ki tarah use karo.
- Push normal chars, pop on star.
- O(n) time, O(n) space.

Code ready hai, bas copy paste karo aur use karo!
*/

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
