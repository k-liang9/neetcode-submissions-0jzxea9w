# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# in preorder, the middle node is the last element
# in inorder, the middle node splits the left and right subtrees
# use prorder to find the middle node, then find the index of the middle node in inorder,
# then recursively call buildTree on left and right splices of the tree

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if len(preorder) == 0:
            return None

        mid_val = preorder[0]
        mid = inorder.index(mid_val)
        l_len = mid
        r_len = len(inorder) - mid - 1

        root = TreeNode(mid_val)
        root.left = self.buildTree(preorder[1:(1+l_len)], inorder[:l_len])
        root.right = self.buildTree(preorder[(1+l_len):(1+l_len+r_len)], inorder[(mid+1):])

        return root