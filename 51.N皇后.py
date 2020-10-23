#-*- coding: UTF-8 -*-
#!/usr/bin/python3
from typing import List
import time

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
    	board = [['.']*n for _ in range(n)]
    	res = []
    	self.backtrack(board, 0 , res, n)
    	
    	return res

    def backtrack(self, board, row, res, len):
    	if len == row:
    		temp = []
    		for item in board:
    			str = ''.join(item)
    			temp.append(str)
    		res.append(temp)
    		return
    	n = len
    	for i in range(n):
    		if self.isVaild(board, row, i) == False:
    			continue
    		board[row][i] = 'Q'
    		self.backtrack(board, row + 1, res, len)
    		board[row][i] = '.'
    	
    def isVaild(self, board, row, col) -> bool:
    	n = len(board)
    	for i in range(n):
    		if board[i][col] == 'Q':
    			return False
    	i = row - 1
    	j = col + 1
    	while i >= 0 and j < n:
    		if board[i][j] == 'Q':
    			return False
    		i -= 1
    		j += 1

    	i2 = row - 1
    	j2 = col - 1
    	while i2 >= 0 and j2 >= 0:
    		if board[i2][j2] == 'Q':
    			return False
    		i2 -= 1
    		j2 -= 1
    	return True
if __name__ == '__main__':
	starttime = time.time()
	res = Solution().solveNQueens(4)
	endtime = time.time()
	print(str(endtime - starttime))
	for x in res:
		print(x)
	print(len(res))


	
	