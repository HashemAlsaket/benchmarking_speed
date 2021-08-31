class Solution:
    def twoSum(self, nums, target):
        import time

        t0 = time.time()
        
        n = len(nums)
        
        d = {}
        
        for i in range(n):
            if target - nums[i] in d:
                print('{:.20f}'.format((time.time() - t0) * 1000))
                return [d[target - nums[i]], i]
            d[nums[i]] = i
        
with open("testcase.txt", "r") as fil:
    import ast
    vars = fil.readlines()
    vars = [var.rstrip() for var in vars]
    vars[0] = [int(x) for x in ast.literal_eval(vars[0])]
    vars[1] = int(vars[1])
    for i in range(10):
        Solution().twoSum(vars[0], vars[1])