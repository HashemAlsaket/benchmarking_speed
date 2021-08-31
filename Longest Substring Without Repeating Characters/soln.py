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
        print(len(s))
        print('{:.20f}'.format((time.time() - t0) * 1000))
        return mx

with open("testcase.txt", "r") as fil:
    vars = fil.readlines()
    vars = [var.rstrip() for var in vars]
    for i in range(10):
        Solution().lengthOfLongestSubstring(vars[0][1:-1])