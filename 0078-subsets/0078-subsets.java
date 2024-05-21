class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> l = new ArrayList();
        List<Integer> sl = new ArrayList();
        helper(0,nums, l, sl);
        return l;
    }
  
  void helper(int ind, int[] nums, List<List<Integer>> l, List<Integer> sl)
  {
    if(ind==nums.length)
    {
      l.add(new ArrayList<>(sl));
      return;
    }
    
    sl.add(nums[ind]);
    helper(ind+1,nums,l,sl);
    
    sl.remove(sl.size()-1);
    helper(ind+1,nums,l,sl);
  }
}