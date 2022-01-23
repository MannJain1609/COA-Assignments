import random
import time

n=int(input())
start1=time.time()

def MatPrint(n, mat): 
    for i in range(n):
        for j in range(n):     
            print (mat[i][j],end = " ")       
        print()


def multiply(n, mat1, mat2):
 
    ans = [[0 for x in range(n)]for y in range (n)]
     
    for i in range(n):
        for j in range(n):
            ans[i][j] = 0
            for x in range(n):           
                ans[i][j] += (mat1[i][x] *mat2[x][j])
            
    MatPrint(n,ans)

if __name__ == "__main__":

    # we dont have double in python, hence using float 
    mat1 = [[random.randint(0,100) for x in range(n)]for y in range (n)]

    mat2 = [[random.randint(0,100) for x in range(n)]for y in range (n)]

    MatPrint(n, mat1)
    print()
    MatPrint(n, mat2)
    print()
    start_time=time.time()
    multiply(n,mat1,mat2)
    print("Total time for the meat program in sec = ",time.time()-start_time, "sec")
    print("Total time of the program in sec = ",time.time()-start1, "sec")