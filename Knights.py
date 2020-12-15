
#Link: https://putka-upm.acm.si/tasks/t/konjske_dirke/


d = {}

field = []

import sys

sys.setrecursionlimit(10**9)

 

N = int(input())

 

for i in range(N):

    field.append(input())

    for j in range(len(field[i])):

        if field[i][j]=="*":

            i0 = i

        if field[i][j] == "#":

            d[i,j]=[False,-1] 

        for j in range(N):

            if field[i][j] == "*":

                j0 = j

    for j in range(N):

        d[i,j]= [False,10**6]

 

 

 

def knight_move(i,j,total=0):

    if 7<abs(i-i0)+abs(j-j0)<total:

        return

 

    if total>N+1 or total>=d[i,j][1]:

        return

 

    valid_moves = [(i+1,j+2),(i+1,j-2),(i-1,j+2),(i-1,j-2),(i+2,j+1),(i+2,j-1),(i-2,j+1),(i-2,j-1)]

    

    if field[i][j] == "#":

        return

 

    d[i,j] = [True, total]

    

    for _ in valid_moves:

        move = _

        if 0<=move[0]<N and 0<=move[1]<N and d[move][1]!=-1:

            knight_move(move[0],move[1],total+1)

            

knight_move(i0,j0)

 

for i in range(int(input())):

    f = list(map(int,input().split()))

    if not d[f[0]-1,f[1]-1][0]:

        print (-1)

    else:

        print(d[f[0]-1,f[1]-1][1])

 
