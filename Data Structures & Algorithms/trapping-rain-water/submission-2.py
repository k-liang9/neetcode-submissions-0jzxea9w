class Solution:
    def trap(self, height: List[int]) -> int:
        l, r = 0, len(height)-1
        maxLeft, maxRight = height[l], height[r]
        res = 0
        while l < r:
            maxLeft = max(height[l], maxLeft)
            maxRight = max(height[r], maxRight)
            if maxLeft < maxRight:
                res += min(maxLeft, maxRight) - height[l]
                l += 1
            else:
                res += min(maxLeft, maxRight) - height[r]
                r -= 1

        return res