class Solution {
public:
    string customSortString(string order, string s) 
{
   unordered_map<char,int>mp;
   for(int i=0;i<s.length();i++)
   {
      char ch = s[i];
	  mp[ch]++;	
   }        
   int idx=0;
   string ans="";
   while(idx<order.length())
   {
   	  char ch = order[idx];
   	  if(mp.find(ch)!=mp.end())
   	  {
   	  	 int freq = mp[ch];
   	  	 while(freq)
   	  	 {
   	  	    ans.push_back(ch);
		    freq--;	
	     }
	     mp.erase(ch);
      }
      idx++;
   }
   for(auto it=mp.begin();it!=mp.end();it++)
   {
   	   char ch = it->first;
   	   int freq = it->second;
   	   
   	   while(freq)
   	   {
   	   	  ans.push_back(ch);
   	      freq--;	
       }
   }
   return ans;
}
};