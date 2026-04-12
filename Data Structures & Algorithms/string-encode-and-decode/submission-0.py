class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded = []
        for word in strs:
            encoded.append(chr(len(word)))
            encoded.append(word)

        return ''.join(encoded)

    def decode(self, s: str) -> List[str]:
        decoded = []
        idx = 0
        while idx < len(s):
            length = ord(s[idx])
            word = s[idx+1:idx+1+length]
            decoded.append(word)
            idx = idx + length + 1

        return decoded