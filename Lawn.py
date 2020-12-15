#Link: https://putka-upm.acm.si/tasks/t/travca/


import math

n,m = map(int,input().split())

 

print(math.ceil(n/2)+math.ceil(m/2)-int(m%2 and n%2))
