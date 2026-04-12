class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        cur = nums[0]
        while True:
            tmp = nums[cur]
            if tmp == 0:
                return cur
            nums[cur] = 0
            cur = tmp