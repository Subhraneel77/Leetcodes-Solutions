class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        int cnt = 0;
        
        while(start < end){
            if(s[start] == s[end])
            {
				// if char matches increment start and decrement end
                start++;
                end--;
            }
            else
            {
				// keeping cnt of character that didn't match
                cnt++;
               start++;     //skip 1 from starting
            }
			// for optimising code if cnt is greater than 1 
            // we will just break the loop as only one char can skipped/deleted.
            if(cnt > 1)
                break;
        }
        
		// reinitialize pointer 
        start = 0;
        end = s.size() - 1;
        int cnt1 = 0;
        
        while(start < end){
            if(s[start] == s[end])
            {
				// if char matches increment start and decrement end
                start++;
                end--;  
            }
            else
            {
				// keeping cnt of character that didn't match
                cnt1++;
                end--;  //skip 1 from ending
            }
			// for optimising code if cnt is greater than 1 
            // we will just break the loop as only one char can skipped/deleted.
            if(cnt1 > 1)
                break;
               
        }
        
        if(cnt == 1 || cnt1 == 1)   //del atmost one char
            return true;
        if(cnt == 0 || cnt1 == 0)    //palindrome
            return true;
        
        return false;
    }
	// for github repository link go to my profile.
};