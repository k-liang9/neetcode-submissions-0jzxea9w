class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        freq_map = {}
        for word in strs:
            freq = [0 for i in range(26)]
            for ch in word:
                freq[ord(ch) - ord('a')] += 1
            key = tuple(freq)
            if key not in freq_map.keys():
                freq_map[key] = []
            freq_map[key].append(word)

        return list(freq_map.values())