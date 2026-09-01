class Solution {
public:
    bool solve(vector<int>& nums, int i, int k, vector<vector<int>> &dp) {
        if (k == 0) {
            return true;
        }

        if (i < 0) {
            return false;
        }

        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        bool notTake = solve(nums, i - 1, k, dp);

        bool take = false;
        if (nums[i] <= k) {
            take = solve(nums, i - 1, k - nums[i], dp);
        }

        dp[i][k]= take || notTake;
        return dp[i][k];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (int x : nums) {
            sum += x;
        }

        if (sum % 2 != 0) {
            return false;
        }
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum/2 +1, -1));
        return solve(nums, nums.size() - 1, sum / 2, dp);
    }
};