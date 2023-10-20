class NestedIterator {
    int curr=0;
    vector<int> flattenList;
public:
    
    void helperFunc(vector<NestedInteger> &nestedList){
        
        int n=nestedList.size(),temp;        
        vector<NestedInteger> temp2;
        
        for(int i=0;i<n;i++){
            if(nestedList[i].isInteger()){
                temp=nestedList[i].getInteger();
                flattenList.push_back(temp);
            }else{
                temp2=nestedList[i].getList();
                helperFunc(temp2);
            }
        } 
        
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
          helperFunc(nestedList);             
    }
    
    int next() {
        
        int ans=flattenList[curr];
        curr++;
        return ans;
        
    }
    
    bool hasNext() {
        if(curr==flattenList.size()) return false;    
        return true;
        
    }
};
