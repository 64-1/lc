class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        #Base case: if we reach a lead node (ie. root is None) or find either p or q,
        #return the current node(or none if not found). This is because if we find either p or q,
        #or reached the end of a path without finding either, we've either found part of the answer
        #or know that the answer is not in this path.
        if (root is None) or (root == p) or (root == q):
            return root
        
        #Recursively search the left and right subtrees for p and q
        #The search goes all the way to the leaves and then starts bubbling up
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        #if both left and right are not None, then we've found the LCA
        if left and right:
            return root
        
        #If one of left or right is None,
        #it means both p and q are located in that subtree. Thus, the LCA
        #is further up that path. We return the non-None node.
        #if both left and right are None, this returns None,
        #propagating the search up the tree.
        else:
            return left if left else right
        
def main():
    root = TreeNode(6)
    root.left = TreeNode(2)
    root.right = TreeNode(8)
    root.left.left = TreeNode(0)
    root.left.right = TreeNode(4)
    root.right.left = TreeNode(7)
    root.right.right = TreeNode(9)
    root.left.right.left = TreeNode(3)
    root.left.right.right = TreeNode(5)

    p = root.left
    q = root.right
    lca = Solution().lowestCommonAncestor(root, p, q)
    if lca is not None:
        print(lca.val)
    else:
        print("LCA not found")

if __name__ == '__main__':
    main()


