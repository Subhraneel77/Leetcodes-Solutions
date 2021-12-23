class Solution:
    # @param {integer} numCourses
    # @param {integer[][]} prerequisites
    # @return {integer[]}
    def findOrder(self, numCourses, prerequisites):
        map = [[] for x in range(numCourses)]
        ind = [0 for x in range(numCourses)]
        res = [] 
        for p in prerequisites:
            if p[0] not in map[p[1]]:
                ind[p[0]] += 1
                map[p[1]].append(p[0])
        st = []
        for i in range(numCourses):
            if ind[i] == 0:
                st.append(i)
        count = 0
        while st:
            tmp = st[0]
            st.pop(0)
            res.append(tmp)
            count += 1
            for i in map[tmp]:
                ind[i] -= 1
                if ind[i] == 0:
                    st.append(i)
                         
        if count < numCourses:
            return []
        else: 
            return res
         
        
