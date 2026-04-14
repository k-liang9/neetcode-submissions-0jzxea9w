class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)

        # transpose
        for i in range(n):
            for j in range(i+1, n):
                temp = matrix[j][i]
                matrix[j][i] = matrix[i][j]
                matrix[i][j] = temp

        # vertical flip
        for i in range(n):
            for j in range(n//2):
                temp = matrix[i][n-1-j]
                matrix[i][n-1-j] = matrix[i][j]
                matrix[i][j] = temp

# # iterate over every element in 1 quadrant, and do rotation, displaced element would be the next rotated
# # even n: iterate to n/2-1 inclusive for both row and col
# # odd n: iterate to n/2-1 for row, n/2 for col
# # OR: transpose --> flip

# temp: 7
# a b c d e
# f g h i j
# k l m n o
# p q r s t
# u v w x y

# (0, 0) -> 

# first quad: m[i][j] = m[i][j] = m[n-j][n-i]