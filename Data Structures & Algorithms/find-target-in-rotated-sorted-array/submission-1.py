class Solution:
    def search(self, nums: List[int], target: int) -> int:
        z = nums[0]
        l, r = 0, len(nums) - 1

        min_index = 0
        min_element = z
        while l <= r:
            m = l + (r-l)//2
            
            if nums[m] == target:
                return m

            if nums[m] >= z:
                l = m+1
            else:
                r = m-1
                if nums[m] < min_element:
                    min_element = nums[m]
                    min_index = m

        if target >= z:
            l = 0
            r = max(0, min_index - 1)
        else:
            l = min_index
            r = len(nums) - 1

        while l <= r:
            m = l + (r-l)//2
            if nums[m] == target:
                return m
            elif nums[m] > target:
                r = m - 1
            else:
                l = m + 1

        return -1