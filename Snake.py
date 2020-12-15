#Link to the problem: https://putka-upm.acm.si/tasks/t/kaca/

x,y = map(int,input().split())
X = x
x1,y1 = -2,0
m = [["." for i in range(x)] for i in range(y)]
#x-=1
y+=2
dir = 1,0
 
current = [0,0]
steps = 0
 
def turn(dir):
    d = {(1,0):(0,1),(0,1):(-1,0),(-1,0):(0,-1),(0,-1):(1,0)}
    return d[dir]
 
while True:
    if current[0]+dir[0]<x and current[1] + dir[1] < y and current[0]+dir[0]>=x1 and current[1] + dir[1] >= y1:
        steps += 1
        m[current[1]][current[0]] = "#"
        current[0]+=dir[0]
        current[1]+= dir[1]
    else:
        if X > 2:
            if steps<2:
                break
        else:
            X = 3
        #print(current, x, y, x1, y1, dir)
        dir = turn(dir)
        steps = 0
        if dir == (1,0):
            x-=2
        elif dir == (0,1):
            y-=2
        elif dir == (-1,0):
            x1+=2
        else:
            y1+=2
    if x<=x1 and y<=y1:
        #print(current,x,y,x1,y1,dir)
        break
m[current[1]][current[0]] = "*"
 
 
 
 
for i in range(len(m)):
    for j in range(len(m[0])):
        print(m[i][j],end = "")
    print("")
