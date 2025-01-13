class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = -1;
        for(int i=0; i < matrix.size();i++){
            if(matrix[i][0] <= target && matrix[i].back() >= target){
                row = i;
                break;
            }
        }
        if(row == -1) return false;
      int L = 0;
      int R = matrix[row].size()-1;
      while(L <= R){
        int mid = L + (R-L) / 2;
        if(matrix[row][mid] == target){
            return true;
        }else if(matrix[row][mid] > target){
            R = mid-1;
        }else{
            L = mid+1;
        }
      }
      return false;
    }
};