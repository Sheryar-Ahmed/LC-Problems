class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int result = 0;

        while (low <= high) {
            string no = to_string(low);
            int n = no.size();

            if (n % 2 == 0) { // Only check numbers with even length
                int half = n / 2;
                int leftSum = 0, rightSum = 0;

                for (int i = 0; i < half; ++i)
                    leftSum += no[i] - '0'; // Convert char to int

                for (int i = half; i < n; ++i)
                    rightSum += no[i] - '0';

                if (leftSum == rightSum)
                    result++;
            }

            low++;
        }

        return result;
    }
};
