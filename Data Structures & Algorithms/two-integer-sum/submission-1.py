class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_sorted = sorted(nums)
        l_ptr = 0
        r_ptr = len(nums) - 1

        while l_ptr < r_ptr:
            sum = nums_sorted[l_ptr] + nums_sorted[r_ptr]
            if sum == target:
                break
            elif sum < target:
                l_ptr += 1
            else:
                r_ptr -= 1

        vals = [nums_sorted[l_ptr], nums_sorted[r_ptr]]
        indices = []
        for i in range(len(nums)):
            if nums[i] in vals:
                indices.append(i)
                vals.remove(nums[i])
            if len(vals) == 0:
                break

        return indices