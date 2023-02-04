class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		vector<int> map_s1(26), map_s2(26);
		for(char& i1 : s1) 
			map_s1[i1 - 'a']++;
		for(int i = 0; i < s2.size(); i++) {
			map_s2[s2[i] - 'a']++;
			if(i >= s1.size() - 1) {
				if(map_s2 == map_s1)  // Time: O(26)
					return true;
				map_s2[s2[i - s1.size() + 1] - 'a']--;
			}
		}
		return false;
	}
};