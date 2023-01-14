class StockPrice {
public:
    
    unordered_map<int, int> mp;
    
    // multiset will store the prices
    
    multiset<int> s;
    
    int max_time = 0;
    
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        
        // if already present then delete the price from multiset
        
        if(mp.count(timestamp))
        {
            auto it = s.find(mp[timestamp]);
            
            s.erase(it);
        }
        
        // update 
        
        max_time = max(max_time, timestamp);
        
        mp[timestamp] = price;
        
        s.insert(price);
    }
    
    int current() {
        
        return mp[max_time];
    }
    
    int maximum() {
        
        return *s.rbegin();
    }
    
    int minimum() {
        
        return *s.begin();
    }
};