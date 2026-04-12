class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix_arr = []
        suffix_arr = []
        prefix = 1;
        suffix = 1;
        for i in range(len(nums)):
            prefix_arr.append(prefix)
            suffix_arr.append(suffix)
            prefix *= nums[i];
            suffix *= nums[len(nums) - 1 - i]

        suffix_arr.reverse()
        res = []
        for i in range(len(nums)):
            res.append(prefix_arr[i] * suffix_arr[i])

        return res