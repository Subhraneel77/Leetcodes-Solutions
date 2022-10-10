class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(n==1) return "";
        int i=0;
        for(auto c:palindrome){
            if(i==n/2 && n%2==1) {
                i++;
                continue;
            }
            if(c=='a') i++;
            else break;
        }
        if(i==n) palindrome[n-1]='b';
        else if(palindrome[i]==palindrome[n-i-1]) palindrome[i]='a';
        return palindrome;
    } 
};