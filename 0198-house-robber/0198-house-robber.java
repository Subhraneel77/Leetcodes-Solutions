class Solution {
    public int rob(int[] nums) {
        if(nums.length == 0)
        {return 0;}
        if(nums.length == 1)
        {return nums[0];}
        if(nums.length == 2)
        {return Math.max(nums[0],nums[1]);}
        int oddHouses = 0;
        int evenHouses = 0;
        for (int i : nums) {
            int temp = oddHouses;
            oddHouses = Math.max(oddHouses, evenHouses);
            evenHouses = i + temp;
        }
        return Math.max(oddHouses, evenHouses);
        }}