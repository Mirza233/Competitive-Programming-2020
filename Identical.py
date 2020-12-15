#Link: https://putka-upm.acm.si/tasks/t/eqstr/

from functools import lru_cache

@lru_cache(maxsize=None)

 

def identical(s1,s2):

    if len(s1)<=3:

        return sorted(s1) == sorted(s2)

    s1 = [s1[:len(s1)//3],s1[len(s1)//3:2*len(s1)//3],s1[2*len(s1)//3:]]

    s2 = [s2[:len(s2)//3],s2[len(s2)//3:2*len(s2)//3],s2[2*len(s2)//3:]]

 

    if (identical(s1[0],s2[0]) and identical(s1[1],s2[1]) and identical(s1[2],s2[2])):

        return True

    if (identical(s1[0],s2[0]) and identical(s1[1],s2[2]) and identical(s1[2],s2[1])):

        return True

    if (identical(s1[0],s2[1]) and identical(s1[1],s2[0]) and identical(s1[2],s2[2])):

        return True

    if (identical(s1[0],s2[1]) and identical(s1[1],s2[2]) and identical(s1[2],s2[0])):

        return True

    if (identical(s1[0],s2[2]) and identical(s1[1],s2[0]) and identical(s1[2],s2[1])):

        return True

    if (identical(s1[0],s2[2]) and identical(s1[1],s2[1]) and identical(s1[2],s2[0])):

        return True

    return False

 

for i in range(int(input())):

    if identical(input(),input()):

        print("enaka")

    else:

        print("razlicna")
