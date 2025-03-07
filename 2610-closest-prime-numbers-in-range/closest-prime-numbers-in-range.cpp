class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if (left > right) return {-1, -1};

        vector<bool> prime(right + 1, true);
        prime[0] = prime[1] = false;  // 0 and 1 are not prime

        // Sieve of Eratosthenes
        for (int i = 2; i * i <= right; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    prime[j] = false;
                }
            }
        }

        vector<int> primes;
        for (int num = left; num <= right; num++) {
            if (prime[num]) {
                primes.push_back(num);
            }
        }

        if (primes.size() < 2) return {-1, -1};  // No prime pairs found

        vector<int> result = {-1, -1};
        int min_diff = INT_MAX;

        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < min_diff) {
                min_diff = diff;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result;
    }
};
