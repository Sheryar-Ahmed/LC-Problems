class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            int n = matrix[i].size();
            if (target >= matrix[i][0] && target <= matrix[i][n - 1]) {
                // Binary search on this row
                int L = 0;
                int R = n - 1;
                while (L <= R) {
                    int mid = L + (R - L) / 2;
                    if (matrix[i][mid] == target) {
                        return true;
                    } else if (matrix[i][mid] < target) {
                        L = mid + 1;
                    } else {
                        R = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};
