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
        
        print('{:.20f}'.format((time.time() - t0) * 1000))
        return len(stack) == 0


with open("testcase.txt", "r") as fil:
    vars = fil.readlines()
    vars = [var.rstrip() for var in vars]
    for i in range(10):
        Solution().isValid(vars[0])