# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def validate_subtree(root):
            if root is None:
                return True, None, None

            lvalid, lmin, lmax = validate_subtree(root.left)
            rvalid, rmin, rmax = validate_subtree(root.right)

            if not (lvalid and rvalid):
                return False, None, None

            lcompare = True if lmax is None else lmax < root.val
            rcompare = True if rmin is None else rmin > root.val
            
            if lcompare and rcompare:
                min_val = root.val if lmin is None else lmin
                max_val = root.val if rmax is None else rmax
                return True, min_val, max_val
            else:
                return False, None, None

        is_valid, _, __, = validate_subtree(root)
        return is_valid