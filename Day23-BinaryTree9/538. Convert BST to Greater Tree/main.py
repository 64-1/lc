class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def preorder(self):
        print(self.val, end = " ")
        if(self.left):
            self.left.preorder()
        if(self.right):
            self.right.preorder()

class Solution:
    def __init__(self):
        self.prev = 0

    def convertBST(self, root: TreeNode) -> TreeNode:
        if(root == None):
            return None
        self.convertBST(root.right)
        root.val += self.prev
        self.prev = root.val
        self.convertBST(root.left)
        return root
    
def main():
    root = TreeNode(4)
    root.left = TreeNode(1)
    root.right = TreeNode(6)
    root.left.left = TreeNode(0)
    root.left.right = TreeNode(2)
    root.right.left = TreeNode(5)
    root.right.right = TreeNode(7)
    root.left.right.right = TreeNode(3)
    root.right.right.right = TreeNode(8)
    root = Solution().convertBST(root)
    root.preorder()

if __name__ == "__main__":
    main()