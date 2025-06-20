class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(); // Get the total number of elements in the array
        int totalDistance = 0; // Initialize the total Hamming distance to 0
        
        // Iterate through each bit position (from 0 to 31)
        for (int i = 0; i < 32; i++) {
            int countSetBits = 0; // Count of elements with 'i'th bit set (1)
            
            // Count the number of elements that have the 'i'th bit set (1)
            for (int k = 0; k < n; k++) {
                // Right shift the k-th element by 'i' positions and check the least significant bit
                // If it's 1, increment the count of set bits
                countSetBits += (nums[k] >> i) & 1;
            }
            
            // The number of elements with 'i'th bit unset (0) is 'n - countSetBits'
            // Therefore, the Hamming distance for this bit position is 'countSetBits * (n - countSetBits)'
            totalDistance += countSetBits * (n - countSetBits);
        }
        
        return totalDistance; // Return the calculated total Hamming distance
    }
};