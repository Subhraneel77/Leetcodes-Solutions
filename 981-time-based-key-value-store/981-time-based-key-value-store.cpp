class TimeMap {
private:
    // {key, {timestamp, value}}
    unordered_map<string, map<int, string>> mp;
public:
    TimeMap() {
        mp = unordered_map<string, map<int, string>>();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        // If (key exists) & (key has a {timestamp, value} pair) &
        // (first timestamp value is atleast <= given timestamp
        // [If the first one in map which is the min timestamp is not less than given timestamp,
        // it would mean there are none timestamp that is <= timestamp. So no need to run loop])
        if((mp.find(key) != mp.end()) && (!mp[key].empty()) && (mp[key].begin())->first<=timestamp) {
            for (auto it = mp[key].rbegin(); it != mp[key].rend(); it++) {
                if(it->first <= timestamp) {
                    ans = it->second;
                    break;
                }
            }
        }
        return ans;
    }
};