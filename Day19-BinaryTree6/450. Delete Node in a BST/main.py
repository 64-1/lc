class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    
    def printTree(self, root):
        if root:
            print(root.val)
            self.printTree(root.left)
            self.printTree(root.right)



class Solution:
    def deleteNode(self, root: TreeNode, key: int)->TreeNode:
        if root is None:
            return root
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        else:
            if root.left == None:
                return root.right
            elif root.right == None:
                return root.left
            else:
                root.val = self.successor(root)
                root.right = self.deleteNode(root.right, root.val)
        return root

    def successor(self, root):
        root = root.right
        while root.left:
            root = root.left
        return root.val
    
def main():
    root = TreeNode(5)
    root.left = TreeNode(3)
    root.right = TreeNode(6)
    root.left.left = TreeNode(2)
    root.left.right = TreeNode(4)
    root.right.right = TreeNode(7)
    obj = Solution()
    obj.deleteNode(root, 3)
    root.printTree(root)

if __name__ == "__main__":
    main()

