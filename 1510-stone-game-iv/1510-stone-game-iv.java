class Solution {
    public boolean winnerSquareGame(int n) {
        HashSet<Integer> losingState = new HashSet<>();
        HashSet<Integer> winingState = new HashSet<>();
        losingState.add(0);
        for(int cur=1;cur<=n;cur++){
            for(int i=1;i*i<=cur;i++){
                if(losingState.contains(cur-i*i)){
                    winingState.add(cur);
                    break;
                }
            }
            if(!winingState.contains(cur)) losingState.add(cur);
        }
        return winingState.contains(n);
    }
}