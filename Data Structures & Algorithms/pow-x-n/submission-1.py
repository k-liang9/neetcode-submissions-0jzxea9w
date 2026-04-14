class Solution:
    def recursion(self, x, n):
        if n == 0:
            return 1

        if n % 2 == 0:
            return self.recursion(x*x, n//2)
        else:
            return x * self.recursion(x*x, (n-1)//2)

    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1

        is_neg = False
        if n < 0:
            n = -n
            is_neg = True
        
        res = self.recursion(x, n)

        if is_neg:
            res = 1/res

        return res