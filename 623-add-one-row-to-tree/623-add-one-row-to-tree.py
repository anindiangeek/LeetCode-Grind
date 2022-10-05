class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int, left: bool = True) -> TreeNode:
        if d == 1:
            return TreeNode(v, root if left else None, root if not left else None)
        elif root:
            root.left = self.addOneRow(root.left, v, d - 1, True)
            root.right = self.addOneRow(root.right, v, d - 1, False)
        return root