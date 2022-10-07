class MyCalendarThree {
public:
    map<int,int> mp;
    int maxCount = 0;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int count = 0;
        mp[start]++;
        mp[end]--;
        for(auto it = mp.begin();it != mp.end();it++)
        {
            count += it->second;
            maxCount = max(count,maxCount);
        }
        return maxCount;
		}
};
