import math

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        r = max(piles)

        min_k = r
        while (l <= r):
            m = l + (r-l) // 2
            
            cnt = 0
            for pile in piles:
                cnt += math.ceil(pile / m)

            if cnt > h:
                l = m + 1
            else:
                min_k = m
                r = m - 1

        return min_k