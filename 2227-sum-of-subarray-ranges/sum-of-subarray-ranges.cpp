
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