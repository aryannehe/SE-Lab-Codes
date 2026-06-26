'''
DSL Group B: Assignment 2 
Neeti Kurulkar
SE A 21038

A) Write Python program to store roll numbers of student in array who attended training
program in random order. Write function for searching whether particular student attended
training program or not, using linear search and sentinel search.

B) Write Python program to store roll numbers of student array who attended training program
in sorted order. Write function for searching whether particular student attended training
program or not, using binary search and Fibonacci search.

'''

#**Function for bubble sort**-------------------------------
def bubble_sort(arr, n):
    temp = 0
    for i in range(n):
        for j in range(i, n):
            if (arr[i] > arr[j]):
                temp = arr[i]
                arr[i] = arr[j]
                arr[j] = temp
    return arr
#------------------------------------------------------------

#**Function for linear search**--------------------------------
def linear_search(arr, n, key):
    for i in range(n):
        if arr[i] == key:
            return i
    return -1
#--------------------------------------------------------------

#**Function for sentinel search--------------------------------
def sentinel_search(arr, n, key):
 
    last = arr[n - 1]
 
    # Element to be searched placed at the last index
    arr[n - 1] = key
    i = 0
 
    while (arr[i] != key):
        i += 1
 
    # Put the last element back
    arr[n - 1] = last
    
    #(if key present) or (f key was last element)
    if ((i < n - 1) or (arr[n - 1] == key)):
        return i
    else:
        return -1
#--------------------------------------------------------------

#**Function for binary search**--------------------------------
def binary_search(arr, n, key):
    low = 0
    high = n - 1
    mid = 0
 
    while low <= high:
 
        mid = (high + low) // 2
        
        if arr[mid] < key:
            low = mid + 1
 
        elif arr[mid] > key:
            high = mid - 1
 
        else:
            return mid
 
    return -1
#---------------------------------------------------------------

#**Function for Fibonacci search--------------------------------
def fibonacci_search(arr, n, key): 
  
    # Initialize fibonacci numbers 
    fib1 = 0
    fib2 = 1
    fib3 = fib1 + fib2
    
    #storing the fibonacci number >= n in fib3
    while (fib3 < n): 
        fib2 = fib1 
        fib1 = fib3
        fib3 = fib2 + fib1 
  
    # Marks the eliminated range from front 
    offset = -1
  
    # while there are elements to be inspected. 
    # Note that we compare arr[fib2] with key. 
    # When fib3 becomes 1, fib2 becomes 0 
    while (fib3 > 1): 
  
        # Check if fib2 is a valid location 
        i = min(offset+fib2, n-1) 
  
        # If key is greater than the value at index fib2, cut the subarray array from offset to i 
        if (arr[i] < key): 
            fib3 = fib1 
            fib1 = fib2 
            fib2 = fib3 - fib1 
            offset = i 
  
        # If x is less than the value at index fib2, cut the subarray after i+1 
        elif (arr[i] > key): 
            fib3 = fib2 
            fib1 = fib1 - fib2 
            fib2 = fib3 - fib1 
  
        # element found. return index 
        else: 
            return i 
  
    # comparing the last element with key  
    if(fib1 and arr[n-1] == key): 
        return n-1
  
    # element not found. return -1 
    return -1
#--------------------------------------------------------
    
#--------------------------Main--------------------------
student_list = []
n = int(input("Enter number of students: "))
for i in range(n):
    student_list.append(int(input("Enter Roll number of student: ")))
sorted_list = bubble_sort(student_list, n)
opt = 0
while (opt!=5):
    opt = int(input("Menu: \n1 = Linear Search \n2 = Sentinel Search \n3 = Binary search \n4 = Fibonacci Search \n5 = Stop "))
    if opt == 5:
        break
    key = int(input("Enter Roll number to search: "))
    
    if opt == 1:
        print("Searching using linear search: ")
        status = linear_search(student_list, n, key)
        if status != -1:
            print("Roll number found.")
        else:
            print("Not found.")
            
    elif opt == 2:
        print("Searching using sentinel search: ")
        status = sentinel_search(student_list, n, key)
        if status != -1:
            print("Roll number found.")
        else:
            print("Not found.")
            
    elif opt == 3:
        print("Searching using binary search: ")
        status = binary_search(sorted_list, n, key)
        if status != -1:
            print("Roll number found.")
        else:
            print("Not found.")
            
    elif opt == 4:
        print("Searching using fibonacci search: ")
        status = fibonacci_search(sorted_list, n, key)
        if status != -1:
            print("Roll number found.")
        else:
            print("Not found.")
    
    else:
        print("Invalid input.")