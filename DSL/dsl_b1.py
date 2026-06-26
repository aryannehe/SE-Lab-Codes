'''
DSL Group B: Assignment 1 
Neeti Kurulkar
SE A 21038

Write Python program to store first year percentage of students in array. Write function for
sorting array of floating point numbers in ascending order using
A. Selection Sort
B. Bubble sort and display top five scores.

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

#**Function for selection sort-------------------------------
def selection_sort(arr, n):
    for i in range(n):
        min_index = i
        for j in range(i, n):
            if arr[j]< arr[min_index]:
                min_index = j    #Selecting the minimum element in every iteration
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr
#------------------------------------------------------------

#**Main**----------------------------------------------------
per = []
num = int(input("Enter number of students in class: "))
for i in range(num):
    marks = float(input("Enter percentage of student: "))
    per.append(marks)
bubble = bubble_sort(per, num)
select = selection_sort(per, num)

opt = 0
while opt !=4:
    opt = int(input("Menu = \n1 = Selection sort \n2 = Bubble sort \n3 = Display top 5 scores \n4 = Stop"))
    if opt == 1:
        print("Sorted list using selection sort: ", select)
    elif opt == 2:
        print("Sorted list using bubble sort: ", bubble)
    elif opt == 3:
        print("Top five scores are: ")
        print(bubble[num-1:num-6:-1])
    elif opt == 4:
        break
    else:
        print("Invalid input.")