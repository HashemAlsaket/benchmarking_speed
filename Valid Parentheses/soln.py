class Solution:
    def isValid(self, s: str) -> bool:
        import time

        t0 = time.time()
        
        left = {'(', '[', '{'}
        stack = []
        
        for l in s:
            if l in left:
                stack.append(l)
                continue
            if not stack:
                return False
            p = stack.pop()
            if l == ')' and p != '(':
                return False
            if l == '}' and p != '{':
                return False
            if l == ']' and p != '[':
                return False
        
        return (time.time() - t0) * 1000
        # print('{:.20f}'.format((time.time() - t0) * 1000))
        # return len(stack) == 0


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
            mid += (Solution().isValid(inp[:int(prop * len(inp))]))
        times.append(round(mid / sample_size, 2))
    print(times)