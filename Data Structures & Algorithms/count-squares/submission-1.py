class CountSquares:

    def __init__(self):
        self.pts = {}

    def add(self, point: List[int]) -> None:
        x, y = point
        if x not in self.pts:
            self.pts[x] = {}
        
        if y not in self.pts[x]:
            self.pts[x][y] = 1
        else:
            self.pts[x][y] += 1
        
        print(self.pts)

    def count(self, point: List[int]) -> int:
        # x, y
        # iterate over all points that share the same x coordinate (O(n))
        # for every (x+i, y), check if there are corresponding (x, y+-i) and (x+i, y+-i) O(1) if set()
        x, y = point
        if x not in self.pts:
            return 0

        res = 0
        for yi, cnt in self.pts[x].items(): # O(n)
            if yi == y:
                continue
            length = yi - y
            if (x+length) in self.pts and y in self.pts[x+length] and (y+length) in self.pts[x+length]:
                res += cnt * self.pts[x+length][y] * self.pts[x+length][y+length]
            if (x-length) in self.pts and y in self.pts[x-length] and (y+length) in self.pts[x-length]:
                res += cnt * self.pts[x-length][y] * self.pts[x-length][y+length]

        return res