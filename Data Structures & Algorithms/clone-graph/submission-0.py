"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None:
            return None

        deep_copy = {}

        def dfs(cur_node):
            copy = Node(cur_node.val)
            deep_copy[cur_node.val] = copy

            for neighbor in cur_node.neighbors:
                if neighbor.val not in deep_copy.keys():
                    dfs(neighbor)
                
                copy.neighbors.append(deep_copy[neighbor.val])

        dfs(node)

        return deep_copy[1]