class Solution:
    def findMin(self, nums: List[int]) -> int:
        z = nums[0]
        l, r = 0, len(nums) - 1

        min_val = z

        while l <= r:
            m = l + (r-l)//2
            if nums[m] >= z:
                l = m+1
            else:
                min_val = min(min_val, nums[m])
                r = m-1

        return min_val