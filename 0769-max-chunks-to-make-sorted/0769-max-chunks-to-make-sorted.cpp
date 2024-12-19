class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int value = 0; // This is the smallest value 
        int maxi = 0;
        // While searching for the smallest value what 
		//maximum value we encounter we store this in here and only 
		//increase the count if subarray size is equal to this value
		//and the smallest value is already found
        int count = 0; // The answer
        int  j = 0;// To keep track of size of subarray used to compare it with the maxi value 
        int k = 0; // Flag variable 
        // 1 0 2 3 4 5
        // 1st iteration - maxi = 1 
        // 2nd iteration - maxi = 1 and also we find min value for now which is 0 so increase count and set new min value i.e 2 cuz we already found 1 and 0
        // 3rd iteration - maxi = 2 ans also we find min value so reset values (maxi - j == i-j is used to keep track of size of subarray needed at the moment.) 
        // 4th 5th 6th iterations are same as 3rd.
        for(int i=0;i<arr.size();i++)
        {
            maxi = max(maxi,arr[i]);
            if(arr[i]==value){
                k=1;
            }
            if(k==1 && maxi-j == (i-j)){
                count++;
                value = maxi+1;
                maxi = 0;
                k=0;
                j = i;
            }
        }
        return count;
    }
}; 