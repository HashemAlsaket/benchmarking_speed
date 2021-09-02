# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        import time

        t0 = time.time()
        
        self.v = 0
        
        def rec(root):
            if L <= root.val <= R:
                self.v += root.val
            if root.left:
                rec(root.left)
            if root.right:
                rec(root.right)
        
        rec(root)
        # print('{:.20f}'.format((time.time() - t0) * 1000))
        # print(self.v)
        return (time.time() - t0) * 1000
        return self.v

def toBST(arr):
    if not arr:
        return None
    mid = len(arr) // 2
    root = TreeNode(arr[mid])
    root.left = toBST(arr[:mid])
    root.right = toBST(arr[mid+1:])
    return root

with open("testcase.txt", "r") as fil:
    import ast
    vars = fil.readlines()
    vars = [var.rstrip() for var in vars]
    vars[0] = vars[0][1:-1].split(',')
    vars[0] = [int(x) if x != 'null' else 0 for x in vars[0]]
    vars[1], vars[2] = int(vars[1]), int(vars[2])
    times = []
    iters = 100
    sample_size = 100
    for i in range(1, iters + 1):
        prop = (i/iters)
        mid = 0
        for j in range(sample_size):
            mid += (Solution().rangeSumBST(toBST(vars[0][:int(prop * len(vars[0]))]), vars[1], vars[2]))
        times.append(round(mid / sample_size, 2))
    print(times)