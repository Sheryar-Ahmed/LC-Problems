class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // divide 
        // sort
        // merge
        // simple technique is merge sort
        mergeSort(nums, 0, nums.size()-1); // pass the start and end
        return nums;
    }
private:
    void mergeSort(vector<int> & nums, int l, int r){
        if(l < r) {
            int mid = l+(r-l)/2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid+1, r);

            // merge the left and right arrays
            merge(nums, l, mid, r);
        }
    }
    void merge(vector<int>& nums, int l, int m, int r){
        int i = l;
        int j = m+1;
        int size = r-l+1;
        vector<int> temp; // temporary array to store the sorted results of two split arrays
        while(i <= m && j <= r){
            if(nums[i] < nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        // remining elements in the left part
        // remaining elements in the right part
        while(i <= m ) temp.push_back(nums[i++]);
        while(j <= r) temp.push_back(nums[j++]);

        // now we have sorted the elements now copy back to the original array
        for(int c=0; c < size; c++){
            nums[l+c] = temp[c];
        }
    }
};