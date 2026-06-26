'''
DSL Group B: Assignment 3
Neeti Kurulkar
SE A 21038

Write Python program to store first year percentage of students in array. Write function for
sorting array of floating point numbers in ascending order using quick sort and display top five
scores.

'''

#Function to find the partition position---------------------------
def partition(array, low, high):
 
    # choose the rightmost element as pivot
    pivot = array[high]
 
    # pointer for greater element
    i = low - 1
 
    for j in range(low, high):
        if array[j] <= pivot:
            i = i + 1
            (array[i], array[j]) = (array[j], array[i])
 
    (array[i + 1], array[high]) = (array[high], array[i + 1])
 
    return i + 1
#--------------------------------------------------------------------

def low_pivot(arr, low, high):
    pivot = arr[low]
    k = high
    for i in range(high-1, low-1, -1):
        if arr[i] > pivot:
            arr[i], arr[k] = arr[k], arr[i]
            k = k-1
    arr[k], arr[low] = arr[low], arr[k]
    return k            

# function for Quick sort-------------------------------------------- 
 
def quick_sort(array, low, high):
    if low < high:
 
        # Find pivot element 
        pi = partition(array, low, high)
 
        # Recursive call on the left of pivot
        quick_sort(array, low, pi - 1)
 
        # Recursive call on the right of pivot
        quick_sort(array, pi + 1, high)
#--------------------------------------------------------------------

#--------------------------------Main--------------------------------

student_list = []
n = int(input("Enter number of students: "))
for i in range(n):
    student_list.append(float(input("Enter first year percentage of student: ")))
    
print("Sorting percentages in ascending order...")
quick_sort(student_list, 0, (len(student_list)-1))
print("Sorted list: ", student_list)
print("Top five scores are: ")
print(student_list[n-1:n-6:-1])