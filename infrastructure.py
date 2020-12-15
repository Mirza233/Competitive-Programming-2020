#Link: https://putka-upm.acm.si/tasks/t/infrastruktura/



components = []
while True:
    try:
        line = input().split()
        
    except:
        break
    if not line:
        break
    set1,set2 = 0,0
    m,n = -1,-1
    for i in range(len(components)):
        if line[0] in components [i]:
            set1 = components[i]
            m = i
            n = i if n==-1 else n
            set2 = set(list(components[i])+[line[1]]) if set2==0 else set2
        if line[1] in components[i]:
            set2 = components[i]
            n = i
            m = i if m == -1 else m
            set1 = set(list(components[i])+[line[0]]) if set1==0 else set1
    #print(set1,set2)
    
    try:
        components.append(set1.union(set2))
        components[m],components[-1] = components[-1],components[m]
        components.pop()
        if m!=n:
            components[n],components[-1] = components[-1],components[n]
            components.pop()
        
    except:
        components.append(set(line))
    #print(set1,set2,line,components,"\n")
 
for i in range(len(components)-1):
    print(list(components[i])[0],list(components[i+1])[0])
 
 
