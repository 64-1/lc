class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if(root == None):
            return root
        if(root.val > key):
            self.deleteNode(root.left, key)
        elif(root.val < key):
            self.deleteNode(root.right, key)
        else:
            if(root.left == None):
                return root.right
            elif(root.right == None):
                return root.left
            else:
                root.val = self.successor(root.right)
                root.right = self.deleteNode(root.right, root.val)
        return root
    
    def successor(self, root):
        while(root.left != None):
            root = root.left
        return root.val
    
def main():
    root = TreeNode(5)
    root.left = TreeNode(3)
    root.right = TreeNode(6)
    root.left.left = TreeNode(2)
    root.left.right = TreeNode(4)
    root.right.right = TreeNode(7)
    s = Solution()
    print(s.deleteNode(root, 3).val)

if __name__ == "__main__":
    main()