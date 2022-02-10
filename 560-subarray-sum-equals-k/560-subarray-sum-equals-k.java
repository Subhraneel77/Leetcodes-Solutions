 class Solution {
 	public int subarraySum(int[] nums, int k) {

 		HashMap<Integer, Integer> arr_sums = new HashMap();
 		arr_sums.put(0, 1);
 		int sum = 0, count = 0;
 		
 		for(int i = 0; i < nums.length; i++) {
 			sum += nums[i];
 			if(arr_sums.containsKey(sum - k)) {
 				count += arr_sums.get(sum - k);
 			}
 			arr_sums.put(sum, arr_sums.getOrDefault(sum, 0) + 1);
 		}
 		return count;
 	}
 }