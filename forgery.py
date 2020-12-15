#Link: https://putka-upm.acm.si/tasks/t/ponaredki/

for i in range(int(input())):
    x,y = map(int,input().split())
    y0 = x-1
    
    if (y-y0)<0 or (x>1 and (y-y0)%2 == 1) or (x == 1 and y!=0) or x<1:
        print("NE")
        continue
    print("DA")
