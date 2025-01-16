class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;

        while (low <= high) {
            int partition1 = low + (high - low) / 2;
            int partition2 = (n1 + n2 + 1) / 2 - partition1;

            // Edge values at the partition
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == n1) ? INT_MAX : nums1[partition1];
            
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n2) ? INT_MAX : nums2[partition2];

            // Check if partition is correct
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If the combined length is odd
                if ((n1 + n2) % 2 == 1) {
                    return static_cast<double>(max(maxLeft1, maxLeft2));
                }
                // If the combined length is even
                return (static_cast<double>(max(maxLeft1, maxLeft2)) + min(minRight1, minRight2)) / 2.0;
            } 
            // Adjust the partition
            else if (maxLeft1 > minRight2) {
                high = partition1 - 1;
            } else {
                low = partition1 + 1;
            }
        }

        // If no solution is found (should not happen for valid input)
        throw invalid_argument("Input arrays are not sorted.");
    }
};
