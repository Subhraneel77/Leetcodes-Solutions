class Solution 
{
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        // C++ 17 has std::reduce
        return reduce(word1.cbegin(), word1.cend()) == reduce(word2.cbegin(), word2.cend());
    }
};