class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        //Compute the length for string
        int len=(n<=26)?1:ceil(log(n*25.0/26+1)/log(26));
        string ans(len, ' ');// fill with whitespace
        while (n > 0) {
            n--;
            auto x = div(n, 26);
            ans[--len]=char('A'+x.rem);
            n = x.quot;
        }
        return ans; 
    }
};