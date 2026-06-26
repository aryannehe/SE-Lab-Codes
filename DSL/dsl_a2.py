'''
DSL Group A: Assignment 2 
Neeti Kurulkar
SE A 21038

Write python program for to compute the following computation on matrix

A. Addition of two matrices
B. Subtraction of two matrices
C. Multiplication of two
D. Transpose of matrix

'''


#Function to create a matrix---------------------------------
def matrix(m, n):   # m = r, n = c
    ma = []  
    for i in range(1, m+1):
        row = []
        for j in range(1, n+1):
            a = int(input(f"Enter element : ({i}, {j})"))
            row.append(a)
        ma.append(row)
    return ma
#------------------------------------------------------------

#Function to add two matrices--------------------------------
def addition(A, B):
    if len(A)==len(B) and len(A[0])==len(B[0]):
        add = []
        for i in range(len(A)): #iterating through rows 
            row = []
            for j in range(len(A[0])): #iterating through columns
                item = A[i][j] + B[i][j]
                row.append(item)
            add.append(row)
        return add
    else:
        return "Addition not possible"
#------------------------------------------------------------

#Function to subtract two matrices
def subtraction(A, B):
    if len(A)==len(B) and len(A[0])==len(B[0]):
        sub = []
        for i in range(len(A)):
            row = []
            for j in range(len(A[0])):
                item = A[i][j] - B[i][j]
                row.append(item)
            sub.append(row)
        return sub
    else:
        return "Subtraction not possible."
#--------------------------------------------------------------

#Function to multiply two matrices-----------------------------
def multiplication(A, B):
    if len(A[0]) != len(B):
        return "Multiplication not possible"
    else:
        mul = []
        for i in range(len(A)): #iterating through rows of first matrix
            row = []
            for j in range(len(B[0])): #iterating through colums of second matrix
                res = 0
                for k in range(len(B)): #iterating through rows of second matrix
                    res += A[i][k] * B[k][j] 
                row.append(res)
            mul.append(row)
        return mul
#--------------------------------------------------------------

#Function to find transpose of matrix--------------------------
def transpose(A):
    trans = []
    for i in range(len(A[0])):
        row = []
        for j in range(len(A)):
            item = A[j][i]
            row.append(item)
        trans.append(row)
    return trans
#-------------------------------------------------------------
    

col1 = int(input("Enter number of columns for first martrix: "))
rows1 = int(input("Enter number of rows for first martrix: "))

print("First matrix: ")
m1 = matrix(col1, rows1)
print(m1)

col2 = int(input("Enter number of columns for second martrix: "))
rows2 = int(input("Enter number of rows for second martrix: "))
print("Second matrix: ")
m2 = matrix(col2, rows2)
print(m2)

print("Addition of two matrices = ", addition(m1, m2))
print("Subtraction of two matrices = ", subtraction(m1, m2))
print("Multiplication of two matrices = ", multiplication(m1, m2))
print("Transpose of first matrix = ", transpose(m1))
print("Transpose of second matrix = ", transpose(m2))
    