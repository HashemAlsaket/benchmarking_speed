class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        import time

        t0 = time.time()
        
        n = len(s)
        
        d = {}
        
        i, j, mx = 0, 0, 0
        
        while j < n:
            mx = max(mx, j - i)
            
            if d.get(s[j], 0) > 0:
                while d[s[j]] > 0:
                    d[s[i]] -= 1
                    i += 1
            
            d[s[j]] = d.get(s[j], 0) + 1
            j += 1
            
        mx = max(mx, j - i)
        # print('{:.20f}'.format((time.time() - t0) * 1000))
        # return mx
        return (time.time() - t0) * 1000

with open("testcase.txt", "r") as fil:
    vars = fil.readlines()
    vars = [var.rstrip() for var in vars]
    inp = vars[0]
    times = []
    iters = 100
    sample_size = 1000
    for i in range(iters):
        prop = (i/iters)
        mid = 0
        for j in range(sample_size):
            mid += (Solution().lengthOfLongestSubstring(inp[1:int(prop * len(inp))]))
        times.append(round(mid / sample_size, 2))
    print(times)
