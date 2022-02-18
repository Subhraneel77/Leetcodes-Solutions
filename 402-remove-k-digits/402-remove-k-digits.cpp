class Solution 
{
public:
    string removeKdigits(string num, int k)
    {
        if(num.length() == k)
            return("0");
        
        stack<char> s;
        
        for(int i = 0;i<num.length();i++)
        {
            while(!s.empty() && s.top() > num[i] && k>0)
            {
                s.pop();
                k-=1;
            }
            s.push(num[i]);
        }
        
        while(k>0)
        {
            s.pop();
            k-=1;
        }
        
        string ans = "";
        
        while(!s.empty())
        {
            ans = s.top() + ans;
            s.pop();
        }
        
        while(ans.size()>1&&ans[0]=='0') //remove leading zeros
            ans.erase(0,1);
        return ans;
 
        
    }
};