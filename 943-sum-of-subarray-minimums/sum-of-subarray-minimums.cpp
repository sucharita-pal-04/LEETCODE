

/*
Sum of Subarray Minimums
-------------------------

Problem:
Har subarray ka minimum element nikal ke unka sum return karna.

Constraints:
------------
1 ≤ arr.length ≤ 3 * 10^4
1 ≤ arr[i] ≤ 3 * 10^4
- n max 30000 hai → brute force O(n^2) borderline hai, O(n^3) bilkul nahi chalega.
- Stack based O(n) solution best hai.
- Modulo 1e9+7 use hota hai kyunki sum ka value bahut bada ho sakta hai (overflow avoid karna).

Brute Force Approach:
----------------------
Idea:
- Har subarray banake uska min find karo aur sum me add karo.
- Running min maintain karke O(n^2) tak optimize kar sakte ho.

Code:
int sumSubarrayMins_Brute(vector<int>& arr) {
    int n = arr.size();
    long long sum = 0, M = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        int mn = INT_MAX;
        for (int j = i; j < n; j++) {
            mn = min(mn, arr[j]);
            sum = (sum + mn) % M;
        }
    }
    return (int)sum;
}

Time Complexity: O(n^2)
Space Complexity: O(1)

Optimized Approach (Monotonic Stack):
--------------------------------------
Concept:
- Har element arr[i] ke liye count karo ki kitne subarrays me wo min ban raha hai.
- Ye count nikalne ke liye Next Smaller Element ka use karte hain.

Definitions:
NSL[i] = index of Next Smaller element to the Left (strictly smaller)
NSR[i] = index of Next Smaller element to the Right (smaller ya equal for duplicates)

Formula:
Left count  = i - NSL[i]
Right count = NSR[i] - i
Total subarrays with arr[i] as min = Left count × Right count
Contribution = arr[i] × total subarrays

Why NSL < aur NSR <= ?
- Taaki duplicates ka double counting na ho.

Time Complexity: O(n) using monotonic stack for NSL/NSR.
Space Complexity: O(n) for stacks and helper arrays.

Use Cases:
- Range Contribution Problems:
  - Sum of Subarray Minimums
  - Sum of Subarray Maximums
  - Largest Rectangle in Histogram, etc.

Mental Hook:
- "Left Smaller × Right Smaller → Contribution"
*/




class Solution {
public:
    // Function to find Next Smaller to Left (strictly smaller)
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> res(n);   // result array to store NSL indices
        stack<int> st;        // stack to keep indices

        for (int i = 0; i < n; i++) {
            // Jab tak stack top ka element current se bada hai, pop karo
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            // Agar stack empty hai to koi smaller left me nahi → -1
            // Warna stack top index hi NSL hai
            res[i] = st.empty() ? -1 : st.top();
            // Current index push karo
            st.push(i);
        }
        return res;
    }

    // Function to find Next Smaller to Right (smaller or equal for duplicates)
    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> res(n);   // result array to store NSR indices
        stack<int> st;        // stack to keep indices

        for (int i = n - 1; i >= 0; i--) {
            // Jab tak stack top ka element current se chhota ya equal nahi hota, pop karo
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            // Agar stack empty hai to koi smaller right me nahi → n
            // Warna stack top index hi NSR hai
            res[i] = st.empty() ? n : st.top();
            // Current index push karo
            st.push(i);
        }
        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        // Get Next Smaller to Left & Next Smaller to Right arrays
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        long long sum = 0;
        long long M = 1e9 + 7; // modulo value

        for (int i = 0; i < n; i++) {
            // Left side count (kitne elements tak ye min ban sakta hai left me)
            long long ls = i - NSL[i];
            // Right side count (kitne elements tak ye min ban sakta hai right me)
            long long rs = NSR[i] - i;
            // Total subarrays jisme arr[i] min hoga
            long long total = ls * rs;
            // Contribution of this element
            long long tosum = (arr[i] * total) % M;
            // Final sum me add karo
            sum = (sum + tosum) % M;
        }

        return (int)sum;
    }
};























