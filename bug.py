#Link: https://putka-upm.acm.si/tasks/t/hrosc/

N = int(input())
 
n = N-1
step = -1
 
count = 1
count1 = 0
while True:
    print(n,flush = True)
    grader = input()
    if "i" in grader:
        break
    if n==N-1 and count1==1:
        count1+=1
        continue
    elif n == N-1:
        count1+=1
    if count1>=2:
        break
    if n == 0 and count == 1:
        count+=1
        continue
    elif n == 0:
        step*=-1
    n+=step
