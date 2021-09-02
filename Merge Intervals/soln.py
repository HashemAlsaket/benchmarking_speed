class Solution:
    def merge(self, intervals):
        import time

        t0 = time.time()
        
        intervals = sorted(intervals, key=lambda x: x[0])
        
        res = []
        arr = intervals.pop(0)
        
        for x in intervals:
            if arr[1] >= x[0]:
                arr = [min(arr[0], x[0]), max(arr[1], x[1])]
                continue
            else:
                res.append(arr)
                arr = x
        res.append(arr)
        # print('{:.20f}'.format((time.time() - t0) * 1000))
        # return res
        return (time.time() - t0) * 1000

with open("testcase.txt", "r") as fil:
    from ast import literal_eval
    vars = fil.readlines()
    vars = literal_eval(vars[0])
    vars = [[int(x[0]), int(x[1])] for x in vars]
    times = []
    iters = 100
    sample_size = 100
    for i in range(1, iters + 1):
        prop = (i/iters)
        mid = 0
        for j in range(sample_size):
            mid += Solution().merge(vars[:int(prop * len(vars))])
        times.append(round(mid / sample_size, 2))
    print(times)