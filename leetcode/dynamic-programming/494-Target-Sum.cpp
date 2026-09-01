class Solution {
public:
    int solve(vector<int>& nums, int target, int i, int calc){
        if(i==nums.size()){
            return 0;
        }
        if(i==nums.size()-1){
            if(calc+nums[i]==target){

                if(calc-nums[i]==target){
                    return 2;
                }

                return 1;
            }
            else if(calc-nums[i]==target){

                if(calc+nums[i]==target){
                    return 2;
                }
                return 1;
            }
            else{
                return 0;
            }
        }

        int positive=solve(nums, target, i+1, calc+nums[i]);
        int negative=solve(nums, target, i+1, calc-nums[i]);

        return positive + negative;


    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int calc=0;
        return solve(nums, target, 0, calc);
    }
};