class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int candidate=0,count=0,n=arr.size();
        for(int i=0;i<n;i++){
            if(count==0){
                candidate=arr[i];
            }
        if(arr[i]==candidate) count++;
        else count--;
    } 
    return candidate;
    }
};