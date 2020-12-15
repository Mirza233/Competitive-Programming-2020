#Link: https://putka-upm.acm.si/tasks/t/mesta/

for i in range(int(input())):

    d = 0

    for j in range(int(input())-1):

        d += min(list(map(int,input().split()))[1:])

    print(d)
