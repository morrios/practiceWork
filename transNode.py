# -*- coding: UTF-8 -*-
#!/usr/bin/python3

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def print_all(node):
	if node is not None:
		print(node.val)
		print_all(node.left)
		print_all(node.right)


def transNode(arr):
	def level(index):
		if index >= len(arr) or arr[index] is None:
			return None
		root = TreeNode(arr[index], None, None)
		root.left = level(2 * index + 1)
		root.right = level(2 * index + 2)
		return root
	return level(0)

if __name__ == '__main__':
	arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
	root = transNode(arr)
	print_all(root)
