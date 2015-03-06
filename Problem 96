import pycosat

f = open('test.txt')

summ = 0

for _ in range(50):
    s = f.readline()

    board = []
    for i in range(9):
        n = int(f.readline())
        row = [0]*9
        for i in range(9):
            row[8-i] = n % 10
            n = n // 10
        board.append(row)
    
    cnf = []

    for i in range(9):
        for j in range(9):
            if (board[i][j] != 0):
                cnf.append([board[i][j] + i*81 + j*9])

    def makeItsClauses(L):
        cnf.append(L)
        for i in range(9):
            for j in range(i+1,9):
                cnf.append([-L[i], -L[j]])
        return      

    for i in range(9):
        for j in range(9):
            L =[]
            for k in range(9):
                L.append(1 + k + i*81 + j*9)
            makeItsClauses(L)

    for i in range(9):
        for j in range(9):
            L = []
            for k in range(9):
                L.append(1 + j + i*81 + 9*k)
            makeItsClauses(L)
            L = []
            for k in range(9):
                L.append(1 + j + i*9 + 81*k)
            makeItsClauses(L)

    for i in range(3):
        for j in range(3):
            for k in range(9):
                L = []
                for r in range(3):
                    for c in range(3):
                        L.append(k + 1 + i*243 + j*27 + r*81 + c*9)
                makeItsClauses(L)
            
    sol = pycosat.solve(cnf)
    solvedBoard = []
    for _ in range(9):
        solvedBoard.append([0]*9)
    for i in range(9):
        #print('i is {0}'.format(i))
        for j in range(9):
        #print('    j is {0}'.format(j))
            for k in range(1,10):
            #print('        k is {0}'.format(k))
                if (sol[k + i*81 + j*9 - 1] > 0):
                #print('            sol > 0 for (i,j,k)=({0},{1},{2})'.format(i,j,k))
                    solvedBoard[i][j] = k
                    break
    #for row in solvedBoard:
     #   print(row)
    summ += solvedBoard[0][0]*100 + solvedBoard[0][1]*10 + solvedBoard[0][2]
    
print(summ)
