class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i = 0;
        int j = 0;
        vector<vector<int>> res;
        while(i < nums1.size() && j < nums2.size()){
            int id1 = nums1[i][0], val1 = nums1[i][1];
            int id2 = nums2[j][0], val2 = nums2[j][1];

            if(id1 < id2){
                res.push_back({id1, val1});
                i++;
            } else if(id2 < id1){
                res.push_back({id2, val2});
                j++;
            } else {
                res.push_back({id1, val1+val2});
                i++;
                j++;
            }
        }

        // add remaining elements from nums1
        while(i < nums1.size()){
            res.push_back(nums1[i]);
            i++;
        }

        // add remaining elements from nums2
        while(j < nums2.size()){
            res.push_back(nums2[j]);
            j++;
        }
        return res;
    }
};