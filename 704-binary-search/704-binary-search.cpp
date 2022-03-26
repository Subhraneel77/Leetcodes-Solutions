class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0,end = nums.size() - 1;
        
		// iterate till start doesn't exceed end
        while(start <= end)
        {
			// calculating mid
            int mid = start + (end - start)/2;
			
			// if value at mid is equals to target
            if(nums[mid] == target)
                return mid;
				
			// value at mid is less than target
			// update the start by mid + 1
			// key should be in range mid + 1 to end
            else if(nums[mid] < target)
                start = mid+1;
				
			// else update the end by mid - 1
			// value should be in range 0 to mid - 1
            else
                end = mid-1;
        }
        
		// if target doesn;t found
        return -1;
        
    }
	// for github repository link go to my profile.
};