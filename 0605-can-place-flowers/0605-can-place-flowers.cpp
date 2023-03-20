class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int x = flowerbed.size();
         if(n==0) return true; 
        if(x==1 && flowerbed[0]==0 && n==1){ //Edge case -> [0],n=1
            return true;
        }    
        for(int i=0;i<x;i++){
            
            if(i==0){               // check for i=0
            if( flowerbed[i]==0 && flowerbed[i+1]==0){
                flowerbed[i]=1;
                n--;
            }
            }
            else  if(i==x-1){         // check for i=flowerbed.size()-1;
                if(flowerbed[i]==0 && flowerbed[i-1]==0){
                flowerbed[i]=1;
                n--;
            }
            }
          else{ if(flowerbed[i]==0 && flowerbed[i-1]==0 &&flowerbed[i+1]==0){
                flowerbed[i]=1;
                n--;
            }
              }
         
        }
    if(n<1){
        return true;
    }
        return false;
    }
};
