class Solution { 
public: 
    int minOperations(vector<int>& nums, vector<int>& numsDivide) { 
         
        int gcd = numsDivide[0]; 
        for(auto it:numsDivide) 
            gcd = __gcd(gcd, it); 
         
        sort(nums.begin(), nums.end()); 
        int count = 0; 
        int n = nums.size(); 
         
        for(int i=0;i<nums.size();i++){ 
            if(nums[i]==gcd) 
                break; 
            if(gcd%nums[i]==0) 
                break; 
            if(nums[i]!=gcd)  
                count += 1; 
        } 
 
        if(count==n) 
            return -1; 
        else 
            return count; 
    } 
};