class TimeMap:

    def __init__(self):
        self.store = {} # key: [timestamp, value]

    def set(self, key: str, value: str, timestamp: int) -> None:
        arr = self.store.get(key, None)
        if arr is None:
            self.store[key] = []
        self.store[key].append([timestamp, value])

    def get(self, key: str, timestamp: int) -> str:
        arr = self.store.get(key, [])
        res = ""

        l, r = 0, len(arr) - 1
        while (l <= r):
            m = l + (r - l) // 2
            if arr[m][0] > timestamp:
                r = m - 1
            else:
                res = arr[m][1]
                l = m + 1
        
        return res