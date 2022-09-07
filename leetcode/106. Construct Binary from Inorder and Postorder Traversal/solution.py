# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
# Output: [3,9,20,null,null,15,7]

## postorder의 맨 마지막 값은 root를 나타낸다. 이를 기준으로 inorder의 left child tree와 right child tree를 쪼개고 이를 재귀적으로 수행한다. 

class Solution:
	def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
		def helper(in_left, in_right):
			# if there is no elements to construct subtrees
			if in_left > in_right:
				return None

			# pick up the last element as a root
			val = postorder.pop()
			root = TreeNode(val)

			# root splits inorder list
			# into left and right subtrees
			index = idx_map[val]

			# build right subtree
			root.right = helper(index + 1, in_right)
			# build left subtree
			root.left = helper(in_left, index - 1)
			return root

		idx_map = {val: idx for idx, val in enumerate(inorder)}
		return helper(0, len(inorder) - 1)


			
    