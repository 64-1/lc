from typing import List


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
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if(len(nums) == 0):
            return None
        mid = len(nums) // 2
        root = TreeNode(nums[mid])
        root.left = self.sortedArrayToBST(nums[:mid])
        root.right = self.sortedArrayToBST(nums[mid + 1:])
        return root
    
def main():
    nums = [-10, -3, 0, 5, 9]
    root = Solution().sortedArrayToBST(nums)
    root.preorder()

if __name__ == "__main__":
    main()