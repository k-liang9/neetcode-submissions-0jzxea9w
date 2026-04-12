class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        freqs = []
        for word in strs:
            freq = [0 for i in range(26)]
            for ch in word:
                freq[ord(ch) - ord('a')] += 1
            key = tuple(freq)
            freqs.append(key)

        freq_map = {}
        for i in range(len(strs)):
            freq = freqs[i]
            if freq not in freq_map.keys():
                freq_map[freq] = []
            freq_map[freq].append(strs[i])

        anagrams = []
        for group in freq_map.values():
            anagrams.append(group)

        return anagrams