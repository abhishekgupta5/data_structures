#!usr/bin/python3
import copy

global solns
solns=[]

def add_solution(board):
    sol = copy.deepcopy(board)
    solns.append(sol)

def isSafe(board, row, col, size):
    #print('checking for row %d and col %d' % (row, col))
    for i in range(col):
     #   print('checking is safe for col: ', col)
        if board[row][i]=='Q':
      #      print('can\'t put queen at %d%d' %(row,i))
            return False
    for i,j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j]=='Q':
       #     print('can\'t put queen at %d%d' %(i,j))
            return False
    for i,j in zip(range(row, size, 1), range(col, -1, -1)):
       # print('can\'t put queen at %d%d' %(i,j))
        if board[i][j]=='Q':
            return False
    #print('safe to put queen at row %d and col %d' % (row, col))
    return True

def solveNqueens(board, col, size):
    #print('Solving for column: ', col)
    if col>=size:
        add_solution(board)
        return True
    res = False
    for i in range(size):
        if isSafe(board, i, col, size):
            board[i][col] = 'Q'
            res = solveNqueens(board, col+1, size) or res
            board[i][col] = '.'
    return res

if __name__ == '__main__':
    n = 4
    board = []
    for i in range(n):
        board.append([])
        for j in range(n):
            board[i].append('.')
    for i in range(n):
        print(board[i])
    print()
    solveNqueens(board, 0, n)
    #print(solns)
    #print('Number of solns: ', len(solns))
    for sol in solns:
        print(list(map(''.join, sol)))
