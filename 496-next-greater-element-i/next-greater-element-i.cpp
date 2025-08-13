/*
===============================================================
💡 Problem: LeetCode 496 - Next Greater Element I
===============================================================

📌 Problem Statement:
Given two arrays nums1 and nums2 where:
- nums1 is a subset of nums2
- Both arrays have distinct elements

The "Next Greater Element" of a number x in nums2 is the first
element to the right of x in nums2 that is greater than x.

For each element in nums1, find its next greater element in nums2.
If it does not exist, return -1.

---------------------------------------------------------------
Example:
Input:
nums1 = [4, 1, 2]
nums2 = [1, 3, 4, 2]

Output:
[-1, 3, -1]

Explanation:
- 4 → right side: [2] → No greater → -1
- 1 → right side: [3, 4, 2] → First greater = 3
- 2 → right side: [] → No greater → -1
---------------------------------------------------------------

📏 Constraints:
- 1 ≤ m ≤ 1000 (size of nums1)
- 1 ≤ n ≤ 1000 (size of nums2)
- Elements are distinct
- nums1 is a subset of nums2

===============================================================
🛠 Brute Force Approach:
---------------------------------------------------------------
1. For each element in nums1:
2. Find its index in nums2
3. Scan to the right until a greater element is found or end reached
4. Store result

⏳ Time Complexity: O(m × n)
📦 Space Complexity: O(1) (excluding output)
---------------------------------------------------------------

⚡ Optimized Approach (Monotonic Stack):
---------------------------------------------------------------
Concept:
- Traverse nums2 from right to left
- Maintain a decreasing monotonic stack
- For each element:
    - Pop all smaller/equal elements
    - If stack empty → -1, else top of stack is next greater
    - Push current element in stack
- Store results in a hashmap for O(1) lookup for nums1

⏳ Time Complexity: O(n + m)
📦 Space Complexity: O(n)
---------------------------------------------------------------

🔍 Dry Run:
nums2 = [1, 3, 4, 2]

Step | Current | Stack (Top→Bottom) | Map Entry
-----|---------|--------------------|----------
i=3  |   2     | []                 | 2 → -1
i=2  |   4     | []                 | 4 → -1
i=1  |   3     | [4]                | 3 → 4
i=0  |   1     | [3,4]              | 1 → 3

Final Map:
{ 2: -1, 4: -1, 3: 4, 1: 3 }

---------------------------------------------------------------
🧠 Revision Notes:
- Pattern: Next Greater Element → Monotonic Decreasing Stack
- Traverse from right to left
- Use hashmap for precomputed answers
- Trick: Pop until stack top is greater than current
- Time: O(n + m)
- Space: O(n)
===============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater; // Stores next greater for each num in nums2
        vector<int> st; // Monotonic decreasing stack

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int curr = nums2[i];
            // Pop all elements smaller/equal to current
            while (!st.empty() && st.back() <= curr) {
                st.pop_back();
            }
            // If stack empty → no greater element
            nextGreater[curr] = st.empty() ? -1 : st.back();
            // Push current to stack
            st.push_back(curr);
        }

        // Prepare answer for nums1
        vector<int> ans;
        ans.reserve(nums1.size());
        for (int num : nums1) {
            ans.push_back(nextGreater[num]);
        }
        return ans;
    }
};

// Driver Code (For Testing)
int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    Solution obj;
    vector<int> result = obj.nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}









class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;
        
        for(int i = 0; i < nums1.size(); i++)
        {
            int num = nums1[i];
            int idx = -1;

            for(int j =0; j < nums2.size(); j++)  // o(n)
            {
                if(nums2[j] == num)
                {
                    idx = j;
                    break;

                }
            }

            int nextgr = -1;
            for(int k = idx; k < nums2.size(); k++) // o(n)
            {
                if(nums2[k] > num)
                {
                    nextgr = nums2[k];
                    break;
                }
            }
            ans.push_back(nextgr);
        }

        return ans;
    }
};

// Complexity
// Finding index in nums2 = O(n)

// Scanning to right for next greater = O(n)

// For m elements in nums1, total worst-case = O(m × n).

// Space complexity = O(1) (not counting output).

