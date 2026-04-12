class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if len(intervals) == 0:
            return [newInterval]
        n = len(intervals)
        start, end = n, -1
        for i in range(n):
            if intervals[i][1] >= newInterval[0]:
                start = i
                break
        for i in range(n-1, -1, -1):
            if intervals[i][0] <= newInterval[1]:
                end = i
                break

        if start < n:
            newInterval[0] = min(newInterval[0], intervals[start][0])
        if end > -1:
            newInterval[1] = max(newInterval[1], intervals[end][1])
        res = intervals[:start]
        res.append(newInterval)
        res.extend(intervals[end+1:])
        return res

# [[1, 3], [4, 6]]
# newInterval = [2, 5]
# start = 0
# end = 1
# newInterval = [1, 6]
# res = [[1, 6]]