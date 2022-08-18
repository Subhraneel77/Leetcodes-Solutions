class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int>nums;
        int n=arr.size()/2;
        sort(arr.begin(),arr.end());
        int count=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]==arr[i-1]){
                count++;
            }
            else{
                nums.push_back(count);
                count=1;
            }
        }
        nums.push_back(count);
        sort(nums.begin(),nums.end(),greater<int>());
        int c=0,ans=0;
        for(int i=0;i<nums.size();i++){
            c+=nums[i];
            ans++;
            if(c>=n){
                break;
            }
        }
        return ans;
    }
};