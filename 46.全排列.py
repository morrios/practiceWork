#-*- coding: UTF-8 -*-
#!/usr/bin/python3
from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = []
        used = [False for _ in range(n)]
        self.process(nums, n, 0, [], used, res)
        return res

    def process(self, nums, size, depth, path, used, res):
        if depth == size:
            res.append(path[:])
        else:
            for i in range(size):
                if used[i] == False:
                    used[i] = True
                    path.append(nums[i])
                    self.process(nums, size, depth + 1, path, used, res)
                    used[i] = False
                    path.pop()


if __name__ == '__main__':
    nums = [1, 2, 3]
    solution = Solution()
    res = solution.permute(nums)
    print(res)
