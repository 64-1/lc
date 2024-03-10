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
    def trimBST(self, root: TreeNode, low: int, high: int) -> TreeNode:
        if(root == None):
            return None
        if(root.val < low):
            return self.trimBST(root.right, low, high)
        elif(root.val > high):
            return self.trimBST(root.left, low, high)
        root.left = self.trimBST(root.left, low, high)
        root.right = self.trimBST(root.right, low, high)
        return root

def main():
    root = TreeNode(3)
    root.left = TreeNode(0)
    root.right = TreeNode(4)
    root.left.right = TreeNode(2)
    root.left.right.left = TreeNode(1)
    root = Solution().trimBST(root, 1, 3)
    root.preorder()


if __name__ == "__main__":
    main()