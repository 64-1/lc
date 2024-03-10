from typing import List

class TreeNode:
    def __init__(self, val =0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self) -> None:
        self.prev = None
        self.maxCount = 0
        self.count = 0
        self.res = []
    def findMode(self, root: TreeNode) -> List[int]:
        self.inorder(root)
        return self.res


    def inorder(self, root: TreeNode):
        if not root:
            return
        self.inorder(root.left)
        if(self.prev == None):
            self.count = 1
        elif(self.prev.val == root.val):
            self.count += 1
        else:
            self.count = 1
        self.prev = root
        if(self.count == self.maxCount):
            self.res.append(root.val)
        elif(self.count > self.maxCount):
            self.maxCount = self.count
            self.res.clear()
            self.res.append(root.val)
        self.inorder(root.right)
# Time: O(n)
        

def main():
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(2)
    solution = Solution()
    res = solution.findMode(root)
    print(res)

if __name__ == "__main__":
    main()

