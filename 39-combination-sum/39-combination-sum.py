class Solution(object):
    def combinationSum(self, candidates, target):
        return self.getAllSolutions(candidates, 0, target, [])
        
	# s - starting index where we will check from for candidates
	# curr - a possible solution 
    def getAllSolutions(self, candidates, s, target, curr):
        allSolutions = []
        SUM = sum(curr)
                
		# iterate through candidates starting from s to avoid duplicates
        for n in range(s, len(candidates)):
            currsum = SUM + candidates[n]
            
            if currsum < target:
				# if the sum is less than target, this makes [curr] + [candidates[n]] a possible solution
				# pass the current index n (so we can starting looking from that index)
                allSolutions.extend(self.getAllSolutions(candidates, n, target, curr + [candidates[n]]))
            elif currsum == target:
				# we found a solution so we add it to allSolutions
                allSolutions.extend([curr + [candidates[n]]])
            
        return allSolutions