class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.result = float('inf')
        self.prev = None

    def getMinimumDifference(self, root: TreeNode)-> int:
        self.traversal(root)
        return self.result
    
    def inorder(self, root):
        if root:
            self.inorder(root.left)
            self.min_diff = min(self.min_diff, root.val - self.prev)
            self.prev = root.val
            self.inorder(root.right)
            
    def traversal(self, root: TreeNode):
        if root is None:
            return
        self.traversal(root.left)
        if(self.prev is not None):
            self.result = min(self.result, root.val - self.prev.val)
        self.prev = root
        self.traversal(root.right)
    
    

def main():
    root = TreeNode(1)
    root.right = TreeNode(3)
    root.right.left = TreeNode(2)
    sol = Solution()
    result = sol.getMinimumDifference(root)
    print(result)
    
if __name__ == "__main__":
    main()