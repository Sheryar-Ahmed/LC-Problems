class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int min_recolors = k; // Maximum possible is k (all white)
        int white_count = 0;

        // Count 'W' in the first window of size k
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W')
                white_count++;
        }

        min_recolors = white_count; // Initial minimum recolors needed

        // Slide the window across the string
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i] == 'W')
                white_count++; // Add new rightmost element
            if (blocks[i - k] == 'W')
                white_count--; // Remove leftmost element

            min_recolors = min(min_recolors, white_count);
        }

        return min_recolors;
    }
};