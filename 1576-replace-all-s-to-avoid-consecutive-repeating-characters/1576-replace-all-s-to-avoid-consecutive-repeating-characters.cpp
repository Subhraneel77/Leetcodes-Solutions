class Solution {
	public:
	string modifyString(string s) {
    int n = s.length();
    for(int i=0;i<n;i++){
        
        //checking every character, if character is '?'
        if(s[i] == '?'){
            
            //loop over every alphabet
            for(char j = 'a';j<='z';j++){
                //compare with previous char
                if(i-1>=0 && j==s[i-1]) continue;
                //compare with next char
                if(i+1<n && j==s[i+1]) continue;
                //if both the above conditions are false, fix the current alphabet in that
                //position and break the loop
                s[i] = j;
                break;
            }
        }
        
        //check next char of the string
        
    }
    return s;
}
};