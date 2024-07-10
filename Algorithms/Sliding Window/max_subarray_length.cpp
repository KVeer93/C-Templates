int maxSubarrayLength(const vector<int>& arr, int k) {
    int n = arr.size();
    int left = 0, right = 0;
    int sum = 0, maxLen = 0;

    while (right < n) {
        sum += arr[right];

        if (sum > k) {
            sum -= arr[left];
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    return maxLen;
}
// if you are given to print the window itself then you can use 'while' loop in line 9 and update the left and right index(in Line 14) so that you can print the window
// using if loop reduces the Time complexity from O(2N) to O(N).
