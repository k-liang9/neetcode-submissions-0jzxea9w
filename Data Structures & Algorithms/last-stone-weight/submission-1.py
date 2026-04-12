# take negative of weights
# turn into heap
# repeatedly smash 2 stones toghether and append the result to heap
# stop when there is at most 1 stone left
# return stone weight

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-stone for stone in stones]

        heapq.heapify(stones)
        
        while len(stones) > 1:
            s1 = -heapq.heappop(stones)
            s2 = -heapq.heappop(stones)
            res = s1 - s2
            if res > 0:
                heapq.heappush(stones, -res)
        
        return -heapq.heappop(stones) if len(stones) == 1 else 0