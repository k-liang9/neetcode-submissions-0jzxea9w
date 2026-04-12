import heapq

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.heap = []
        for num in nums:
            heapq.heappush(self.heap, -num)

    def add(self, val: int) -> int:
        heapq.heappush(self.heap, -val)

        nums = []

        for i in range(self.k):
            nums.append(heapq.heappop(self.heap))

        for i in range(self.k):
            heapq.heappush(self.heap, nums[i])

        return -nums[-1]