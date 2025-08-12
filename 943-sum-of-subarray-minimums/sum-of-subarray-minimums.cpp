class Solution {
public:
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        long long sum = 0;
        long long M = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;
            long long total = ls * rs;
            long long tosum = (arr[i] * total) % M;
            sum = (sum + tosum) % M;
        }

        return (int)sum;
    }
};
