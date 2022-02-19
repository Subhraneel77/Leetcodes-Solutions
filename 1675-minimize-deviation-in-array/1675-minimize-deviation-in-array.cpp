class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        set<int>maxh; //Set for calculation.
        /*Step1:-Making Every odd element even. And storing all the element in set.*/
        for(int i=0;i<n;i++)
        {
            if((nums[i]&1)!=0)
                maxh.insert(nums[i]*2);
            else
                maxh.insert(nums[i]);
        }
        
        /*Step2*/
        int mn_deviation=INT_MAX;
        while(true)
        {
           int deviation=(*(maxh.rbegin())-*(maxh.begin())); //store the deviation
            
            mn_deviation=min(mn_deviation,deviation); //Update our minimum deviation.
            
            int max_value=*(maxh.rbegin()); //Maximum value.
            if((max_value & 1)==0)
            {
                /*If maximum value is Even,Minimize it further.*/
                maxh.erase(max_value);
                maxh.insert(max_value/2);
            }
            else
                break;
        }
            return mn_deviation;
    }
};