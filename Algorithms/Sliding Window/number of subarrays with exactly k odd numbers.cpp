It a very generic type question where we are given to find the subarray with this k number (given on some condtition), here this approach can be best for it.

Approach Explanation:

Sliding Window Technique:

1.Use two pointers (l and r) to maintain a sliding window over the array.
2.Track the count of odd numbers (ct) within the window.
3.Adjust the window size (l and r) based on the count of odd numbers to maintain subarrays with exactly k odd numbers.

Helper Function:

1.Use a helper function (solve) to calculate the number of subarrays with at most k odd numbers.
2.This function iterates through the array once, adjusting the window size dynamically.

  
Main Function (numberOfSubarrays):

1.Calls the solve function twice:
2.Once for k to get subarrays with exactly k odd numbers.
3.Once for k-1 to get subarrays with at most k-1 odd numbers.
4.Calculates the difference between the two results to get the count of subarrays with exactly k odd numbers.

  class Solution {
public:
    // Function to count subarrays with at most k odd numbers
    int solve(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0, r = 0, ct = 0;
        int ans = 0;

        while(r < n){
            if(nums[r] % 2 != 0){
                ct++;
            }

            // Shrink the window from the left if ct > k
            while(ct > k){
                if(nums[l] % 2 != 0){
                    ct--;
                }
                l++;
            }

            // Every valid subarray ending at r is counted
            ans += (r - l + 1);
            r++;
        }

        return ans;
    }

    // Main function to count subarrays with exactly k odd numbers
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Calculate count of subarrays with exactly k odd numbers
        return solve(nums, k) - solve(nums, k - 1);
    }
};
