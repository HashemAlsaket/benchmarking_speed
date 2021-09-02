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
        
        # print(len(strs))
        # print('{:.20f}'.format((time.time() - t0) * 1000))
        # return [d[k] for k in d]
        return (time.time() - t0) * 1000
        
        
        
with open("testcase.txt", "r") as fil:
    from ast import literal_eval
    vars = fil.readlines()
    vars = literal_eval(vars[0])
    
    times = []
    iters = 100
    sample_size = 100
    for i in range(iters):
        prop = (i/iters)
        mid = 0
        for j in range(sample_size):
            mid += (Solution().groupAnagrams(vars[:int(prop * len(vars))]))
        times.append(round(mid / sample_size, 2))
    print(times)