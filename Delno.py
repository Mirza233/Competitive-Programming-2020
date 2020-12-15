#Link: https://putka-upm.acm.si/tasks/t/delno_korenjenje/

for _ in range(int(input())):

    exp = input()

    if "sqrt" not in exp:

        print(exp)

        continue

    m,n = 0,0

    for i in range(len(exp)):

        if exp[i] == "*":

            m = i

        if exp[i] == "(":

            n = i+1

    a,b = int(exp[:m]) if m!=0 else 1, int(exp[n:-1])

    #print(a,b)

    for i in range(int(b**0.5+3),1,-1):

        if b%i**2==0:

            a*=i

            b//=i**2

    a = "" if a == 1 else str(a)

    b = "" if b == 1 else "sqrt({})".format(str(b))

    if a == b == "":

        a = "1"

    if a!="" and b!="":

        b="*"+b

    print(a+b)

    

    

 

 
