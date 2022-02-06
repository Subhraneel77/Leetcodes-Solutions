class Solution {
public:
    int removeDuplicates(vector<int>& num) {
        int prev=num[0];
        int k=1;
        int j=1;
        for(int i=1;i<num.size();i++)
        {
            if(num[i]==prev&&k<2)
            {
                num[j]=prev;
                j++;
                k++;
            }
            else if(num[i]!=prev)
            {
                num[j]=num[i];
                j++;
                k=1;
                prev=num[i];
            }
        } 
        return j;
    }
};