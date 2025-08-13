

/*
✅ Problem: Validate Stack Sequences (LeetCode 946)

📌 Problem Explanation (Hinglish)
Tumhare paas do arrays diye gaye hain:
- pushed[] → order in which elements stack me push kiye gaye.
- popped[] → order in which elements stack se pop hone chahiye.

Tumhe check karna hai ki kya yeh pop sequence possible hai agar tum normal stack operations (push/pop) follow karo.

⚠️ Stack ka rule: LIFO (Last In First Out)
- Sirf top element pop ho sakta hai.
- Pop ka order change nahi ho sakta, par tum push delay kar sakte ho.

---

📊 Constraints ka Meaning:
1 ≤ pushed.length = popped.length ≤ 1000  
pushed & popped ke elements distinct honge.  
Yaani constraints ka size manageable hai (O(n) ya O(n²) dono chal jayenge, lekin optimal O(n) hoga).

---

🪜 Brute Force Approach:
1. Har possible push-pop sequence generate karo.
2. Dekho kaunsa sequence popped se match karta hai.
❌ Problem: Time complexity exponential ho jayegi — not feasible for n up to 1000.

---

💡 Optimized Approach (Stack Simulation):
Mental Hook:
"Push jo aaye, pop jab match kare."

Steps:
1. Ek empty stack lo.
2. pushed array traverse karo:
   - Har element push karo stack me.
   - Jab tak stack ka top popped[j] se match kare:
     - Pop stack
     - j++ (popped pointer aage badhao)
3. End me agar stack empty hai → valid sequence.

---

⏱ Time Complexity:
O(n) — Har element at most ek baar push aur ek baar pop hota hai.

💾 Space Complexity:
O(n) — Stack ka size maximum n ho sakta hai.

---

📝 Revision Note:
- Stack = LIFO
- Push karo, pop karo jab top match kare
- Agar end me stack empty hai → valid
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;  // Simulation stack
        int j = 0;      // Pointer for popped array

        for (int x : pushed) {
            st.push(x); // Push element

            // Pop jab tak match kare popped se
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }

        // Agar stack empty hai to sequence valid hai
        return st.empty();
    }
};

// Driver code for testing
int main() {
    Solution sol;
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};

    cout << (sol.validateStackSequences(pushed, popped) ? "Valid" : "Invalid") << endl;
    return 0;
}
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;

        for(auto it : pushed)
        {
            st.push(it);
            while(!st.empty() && st.top() == popped[j] )
            {
                st.pop();
                j++;
            
            
            }

        }
        return st.empty();
    }
};
