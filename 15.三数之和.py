# -*- coding: UTF-8 -*-
#!/usr/bin/python3
from typing import List

# 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

# 注意：答案中不可以包含重复的三元组

# 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

# 满足要求的三元组集合为：
# [
#   [-1, 0, 1],
#   [-1, -1, 2]
# ]


class Solution:

    def threeSum1(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        count = 0
        for i in range(n):
            for j in range(i+1,n):
                for k in range(j+1,n):
                    count += 1
                    print("1: count = ", count)
                    if nums[i] + nums[j] + nums[k] == 0:
                        
                        print(nums[i], nums[j], nums[k])


    def threeSum2(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        if n == 0:
            return []
        nums.sort()
        count = 0
        for i in range(n):
            if i == 0 or nums[i] != nums[i - 1]:
                for j in range(i+1,n):
                    for k in range(j+1,n):
                        if nums[i] + nums[j] + nums[k] == 0:
                            
                            print(nums[i], nums[j], nums[k])

    def threeSum3(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        if n == 0:
            return []
        nums.sort()
        count = 0
        for i in range(n):
            if i == 0 or nums[i] != nums[i - 1]:
                for j in range(i+1,n):
                    if j == i+1 or nums[j] != nums[j - 1]:
                        for k in range(j+1,n):
                            if nums[i] + nums[j] + nums[k] == 0:
                                count += 1
                                print("3: count = ", count)
                                print(nums[i], nums[j], nums[k])                            
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        if n == 0:
            return []
        nums.sort()
        for i in range(n):
            third = n-1
            if i == 0 or nums[i] != nums[i - 1]:
                for j in range(i+1,n):
                    if j == i+1 or nums[j] != nums[j - 1]:
                        while j < third and nums[i] + nums[j] + nums[third] > 0:
                            third = third - 1
                        if j == third:
                            break
                        if nums[i] + nums[j] + nums[third] == 0:
                            res.append([nums[i], nums[j], nums[third]])        
        return res

if __name__ == "__main__":
    print("main")
    Solution().threeSum([-1, 0, 1, 2, -1, -4])
