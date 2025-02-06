class Solution {
public:
    int nC2(int n) {
        return (n * (n - 1)) / 2;  // Compute nC2 for given n
    }

    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;  // Map to store product frequencies
        
        // Populate frequency map
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                freq[nums[i] * nums[j]]++;  // Store the product frequency
            }
        }
        
        int count = 0;
        // Calculate the number of tuples
        for (auto [product, frequency] : freq) {
            if (frequency > 1) {  // Only consider if there are multiple pairs
                count += 8 * nC2(frequency);
            }
        }

        return count;
    }
};
