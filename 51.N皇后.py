#-*- coding: UTF-8 -*-
#!/usr/bin/python3
from typing import List
import time


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        board = [['.'] * n for _ in range(n)]
        res = []
        self.backtrack(board, 0, res)
        return res
    def backtrack(self, board, row, res):
        if row == len(board):
            tmp = []
            for item in board:
                tmp.append(''.join(item))
            res.append(tmp[:])
            return
        n = len(board)
        for col in range(n):
            if self.isVaild(board, row, col) == True:
                board[row][col] = 'Q'
                self.backtrack(board, row + 1, res)
                board[row][col] = '.'




    def isVaild(self, board, row, col):#col
        n = len(board)
        #之前列 有没有 Q
        for i in range(n):
            if board[i][col] == 'Q':
                return False
 
        def isRightUpVaild() -> bool:
            i = row - 1
            j = col + 1
            while i >= 0 and j < n:
                if board[i][j] == 'Q':
                    return False
                i -= 1
                j += 1
            return True
        def isLeftUpVaild() -> bool:
            i = row - 1
            j = col - 1
            while i >= 0 and j >= 0:
                if board[i][j] == 'Q':
                    return False
                i -= 1
                j -= 1
            return True
        if isRightUpVaild() == False:
            return False
        elif isLeftUpVaild() == False:
            return False

        return True

if __name__ == '__main__':
    starttime = time.time()
    res = Solution().solveNQueens(4)
    endtime = time.time()
    print(str(endtime - starttime))
    for x in res:
        print(x)
    print(len(res))