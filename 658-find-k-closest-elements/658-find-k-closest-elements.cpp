class Solution {
public:
	// function that finds the index of the element closest to the target using binary search
    int find(vector<int> &arr, int x){
        int res = 0;
        int low = 0;
        int high = arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]==x) return mid;
            else if(arr[mid] < x){
                low = mid+1;
            } else {
                high = mid-1;
            }
            if(abs(arr[mid]-x) == abs(arr[res]-x)){
                res = min(res, mid);
            } else if(abs(arr[mid]-x) < abs(arr[res]-x)){
                res = mid;
            }
        }
        return res;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int index = find(arr, x);
        int low = index;
        int high = index;
        while(k>0){
            if(low==high){
                res.push_back(arr[low]);
                low--;
                high++;
                k--;
            } else if (low==-1 && high<arr.size()) {
                res.push_back(arr[high]);
                high++;
                k--;
            } else if (low>=0 && high==arr.size()) {
                res.push_back(arr[low]);
                low--;
                k--;
            } else if (abs(arr[low]-x) <= abs(arr[high]-x)) {
                res.push_back(arr[low]);
                low--;
                k--;
            } else {
                res.push_back(arr[high]);
                high++;
                k--;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};