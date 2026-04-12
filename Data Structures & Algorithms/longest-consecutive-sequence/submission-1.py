import heapq

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_cnt = len(nums)
        heapq.heapify(nums)
        best_seq = 0
        cur_seq = 0
        cur_head = None
        for i in range(num_cnt):
            cur = heapq.heappop(nums)
            if cur_head is None or cur - cur_head == 1:
                cur_seq += 1
                if cur_seq > best_seq:
                    best_seq = cur_seq
                    print(best_seq, cur_head)
            elif cur == cur_head:
                continue
            else:
                cur_seq = 1

            cur_head = cur

        return best_seq