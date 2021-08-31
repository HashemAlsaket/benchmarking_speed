class Solution:
    def groupAnagrams(self, strs):
        
        import time

        t0 = time.time()
        
        d = {}
        
        for s in strs:
            srt = ''.join(sorted(s))
            if srt not in d:
                d[srt] = []
            d[srt].append(s)
        
        print(len(strs))
        print('{:.20f}'.format((time.time() - t0) * 1000))
        return [d[k] for k in d]
        
        
        
with open("testcase.txt", "r") as fil:
    from ast import literal_eval
    vars = fil.readlines()
    vars = literal_eval(vars[0])
    print(vars)
    for i in range(10):
        Solution().groupAnagrams(vars)