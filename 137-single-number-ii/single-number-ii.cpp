class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int k=0; k < 32; k++){
            //we are checking for kth bit for all numbers
            
            int temp = 1<<k; //take the left shif of kth bit
            int zeroB = 0;
            int oneB = 0;
            for(auto &num: nums){
                if((num & temp) == 0){
                    //it means our kth bit is 0
                    zeroB++;
                }else{
                    oneB++;
                } 
            }
            if((oneB % 3) == 1){
                res = (res | temp);
            }
        }
        return res;
    }
};