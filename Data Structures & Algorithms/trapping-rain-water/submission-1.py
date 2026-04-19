class Solution:
    def trap(self, height: List[int]) -> int:
        stack = [[0, height[0], 0]]
        res = 0

        for r in range(1, len(height)):
            rh = height[r]

            all_between = 0
            while len(stack):
                l, lh, prev_between = stack[-1]
                if rh >= lh:
                    all_between += prev_between + lh
                    stack.pop()
                else:
                    stack[-1][2] += all_between
                    break
            
            if len(stack) == 0:
                all_between -= lh
                res += (r-l-1) * min(rh, lh) - all_between
            
            stack.append([r, rh, 0])
            # print(res, stack)

        r, rh, _ = stack.pop()
        while len(stack):
            l, lh, between = stack.pop()
            res += (r-l-1) * rh - between
            r, rh = l, lh
        
        return res

# tuple = (index, blocks_after)
# stack = []
# i = 7
# h = 3

# backtracking
# r = 3
# blocks_between = 2

# res = 2 + 7 = 9

# rainwater(l, r) = (r-l-1) * min(height[r], height[l]) - blocks_between