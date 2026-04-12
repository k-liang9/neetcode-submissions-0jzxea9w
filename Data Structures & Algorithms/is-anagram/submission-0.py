class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_cnt = [0 for i in range(26)]
        t_cnt = [0 for i in range(26)]

        for char in s:
            s_cnt[ord(char) - ord('a')] += 1

        for char in t:
            t_cnt[ord(char) - ord('a')] += 1

        return s_cnt == t_cnt