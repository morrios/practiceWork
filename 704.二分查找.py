# -*- coding: UTF-8 -*-
#!/usr/bin/python3

# 给定一个n个元素有序的（升序）整型数组nums 和一个目标值target ，
# 写一个函数搜索nums中的 target，如果目标值存在返回下标，否则返回 -1。

# 示例 1:

# 输入: nums = [-1,0,3,5,9,12], target = 9
# 输出: 4
# 解释: 9 出现在 nums 中并且下标为 4

from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
    	print("begin")
    	begin = 0
    	middle = int(len(nums) / 2)
    	if middle > begin:
    		if List[middle] > target:
    			print("big")

    		elif middle < begin:
    			print("small")
    		else:
    			print("find")
    			return 
    	print(num1, num2)
    	return -1

    def search(self, nums: List[int], target: int, begin: int, end: int) -> int:
    	numLen = len(nums)
    	if numLen == 0:
    		return -1
    	elif numLen == 1:
    		return List[0] == 0 if List[0] == target else -1


if __name__ == '__main__':
	nums = [-1,0,3,5,9,12]
	target = 9
	Solution().search(nums, target)