class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // in any circular queue question, we just need to append the 
        int N = colors.size()+k-1;
        for(int i=0; i < k-1; i++){
            colors.push_back(colors[i]);
        }
        // khandani template
        int i = 0;
        int j = 1; // we take 1 because we have to check the prev, is that same
        int result = 0;
        while(j < N){
            if(colors[j] == colors[j-1]){
                i=j;
                j++;
                continue;
            }

            if(j-i+1 == k){ // if we found that window
                result++;
                i++;
            }
            j++;
        }
        return result;
    }
};