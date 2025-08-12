/*
Sum of Subarray Ranges
-----------------------
Leetcode 2104

Problem:
--------
Tumhe ek integer array nums diya gaya hai. Har subarray ka (max - min) nikal ke unka sum return karna hai.

Example:
nums = [1,2,3]
Subarrays:
[1] → max=1, min=1 → range=0
[1,2] → max=2, min=1 → range=1
[1,2,3] → max=3, min=1 → range=2
[2] → 0
[2,3] → 1
[3] → 0
Sum = 0+1+2+0+1+0 = 4

Constraints:
------------
1 ≤ nums.length ≤ 1000  
-10^9 ≤ nums[i] ≤ 10^9  

Meaning:
- n max 1000 → O(n^2) brute force bhi chal jayega lekin O(n) ya O(n log n) optimized bhi possible hai.
- Values kaafi large ho sakti hain (negative bhi), isliye long long ka use zaroori hai.
- n chhota hone ke bawajood optimized approach interview me impress karega.

Brute Force Approach:
----------------------
Idea:
- Har subarray ka max aur min find karo aur unka difference sum me add karo.
- Nested loops use karo.

Time Complexity:
- O(n^3) agar har subarray ka max/min linear search se karoge.
- O(n^2) agar running max/min maintain karoge.

Code:
long long subArrayRanges_Brute(vector<int>& nums) {
    int n = nums.size();
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int mn = nums[i], mx = nums[i];
        for (int j = i; j < n; j++) {
            mn = min(mn, nums[j]);
            mx = max(mx, nums[j]);
            sum += (mx - mn);
        }
    }
    return sum;
}

Optimized Approach (Monotonic Stack):
--------------------------------------
Concept:
- Har element ka contribution as maximum aur as minimum separately count karo.
- Formula:
    sum_of_ranges = (sum of subarray maximums) - (sum of subarray minimums)

How to find sum of subarray maximums?
- Next Greater to Left (NGL) & Next Greater to Right (NGR) ka use karo (similar to sum of subarray minimums logic).

How to find sum of subarray minimums?
- Next Smaller to Left (NSL) & Next Smaller to Right (NSR) ka use karo.

Mental Hook:
- "Max contribution - Min contribution = Range sum"

Time Complexity: O(n)  
Space Complexity: O(n)

*/

class Solution {
public:
    // Helper: Next Smaller to Left
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

    // Helper: Next Smaller to Right
    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }

    // Helper: Next Greater to Left
    vector<int> getNGL(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

    // Helper: Next Greater to Right
    vector<int> getNGR(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        // Sum of subarray minimums
        vector<int> NSL = getNSL(nums, n);
        vector<int> NSR = getNSR(nums, n);
        long long minSum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - NSL[i];
            long long right = NSR[i] - i;
            minSum += (long long)nums[i] * left * right;
        }

        // Sum of subarray maximums
        vector<int> NGL = getNGL(nums, n);
        vector<int> NGR = getNGR(nums, n);
        long long maxSum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - NGL[i];
            long long right = NGR[i] - i;
            maxSum += (long long)nums[i] * left * right;
        }

        // Final result = maxSum - minSum
        return maxSum - minSum;
    }
};
