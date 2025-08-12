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

