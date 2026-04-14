class Solution:
    def myPow(self, x: float, n: int) -> float:
        is_neg = False
        if n < 0:
            n = -n
            is_neg = True
        res = 1
        for i in range(n):
            res *= x
        
        if is_neg:
            res = 1/res

        return res