"""
DSL Group A Assignment 1
Neeti Kurulkar
SE A 21038

Write a Python program to store marks scored in subject “Fundamental of Data
Structure” by N students in the class. Write functions to compute following:
a) The average score of class
b) Highest score and lowest score of class
c) Display the list of students who were absent for the test
d) Display mark with highest frequency

"""

class SE:
    student_list, marks_list, ab_students = [], [], []
    student_count = 0
    
    def __init__(self):
        self.name = " "
        self.marks = 0
    
    def get_data(self):
        self.name = input("Enter the name of student: ")
        pr = input("Was student present for the test? Y = Yes N = No")
        if pr == "Y" or pr == "y":
            SE.student_list.append(self.name)
            SE.student_count += 1
            SE.marks_list.append(float(input("Enter marks of the Student: ")))
        else:
            SE.ab_students.append(self.name)
    #------------------------------------------------------------------
            
    def get_maximum(self):
        max_marks = 0
        for i in range(SE.student_count):
            if (max_marks < SE.marks_list[i]):
                max_marks = SE.marks_list[i]
        return max_marks
    #------------------------------------------------------------------
    
    def get_minimum(self):
        min_marks = 100
        for i in range(SE.student_count):
            if (min_marks > SE.marks_list[i]):
                min_marks = SE.marks_list[i]
        return min_marks
    #------------------------------------------------------------------
    
    def avg_score(self):
        total = 0
        for i in range(SE.student_count):
            total += SE.marks_list[i]
        avg = total/SE.student_count
        return avg
    #------------------------------------------------------------------
    
    #Function to sort marks list in ascending order
    def sort_list(self):
        temp_name = ""
        temp_marks = 0
        for i in range(SE.student_count):
            for j in range(i, SE.student_count):
                if (SE.marks_list[i]>SE.marks_list[j]):
                    temp_marks = SE.marks_list[i]
                    SE.marks_list[i] = SE.marks_list[j]
                    SE.marks_list[j] = temp_marks
                    temp_name = SE.student_list[i]
                    SE.student_list[i] = SE.student_list[j]
                    SE.student_list[j] = temp_name
    #------------------------------------------------------------------    
    
    def highest_frequency(self):
        max_count = 0
        freq_list = []
        k = 0
        for i in range(SE.student_count):
            count = 0
            for j in range(SE.student_count):
                if SE.marks_list[i]==SE.marks_list[j]:
                    count+=1
            if count>max_count:
                max_count = count
                freq_list.clear()
                freq_list.append(SE.marks_list[i])
            elif count == max_count:
                if freq_list[k] != SE.marks_list[i]:
                    freq_list.append(SE.marks_list[i])
                    k+=1
        return freq_list
    #------------------------------------------------------------------
    
    #Function to display all required information
    def display(self):
        print("Names of students and their respective marks: ", SE.student_list, SE.marks_list)
        print("Highest score:", SE.marks_list[SE.student_count - 1], "\t", "Name of student:", SE.student_list[SE.student_count - 1])
        print("Lowest score: ", SE.marks_list[0], "\t", "Name of student:", SE.student_list[0])
        print("List of absent students: ", SE.ab_students)
        print("Marks with highest count : ", SE.highest_frequency(self))
        
#------------------------end of class SE--------------------------------
#-----------------------------------------------------------------------

n = int(input("Enter total students in class: "))
for i in range(n):
    s = SE()
    s.get_data()

s.get_maximum()
s.get_minimum()
s.sort_list()
s.display()
 
 
'''
 def avg_score(arr, n):
  total = 0
  for i in range(n):
    if arr[i][1] != -1:
      total += arr[i][1]
  avg = total / n

  return avg


def get_max(arr, n):
  max = arr[0][1]
  for i in range(n):
    if arr[i][1] > max:
      max = arr[i][1]
  return max


def get_min(arr, n):
  min = arr[0][1]
  for i in range(n):
    if arr[i][1] != -1 and arr[i][1] < min:
      min = arr[i][1]
  return min


def check_freq(arr, n):
  max_count = 0
  freq_list = []
  for i in range(n):
    flag = 0
    count = 0
    for j in range(n):
      if arr[i][1] == arr[j][1] and arr[i][1] != -1:
        count += 1
    if count > max_count:
      max_count = count
      if max_count != 1:
        freq_list.clear()
        freq_list.append(arr[i][1])
    elif count == max_count and max_count != 1:
      for k in range(len(freq_list)):
        if arr[i][1] == freq_list[k]:
          flag = 1
          break
      if flag == 0:
        freq_list.append(arr[i][1])

  return freq_list


stu_li = []
num = int(input("Enter total students: "))
for i in range(num):
  name = input(f"Enter student {i+1}'s name: ")
  status = int(input("Was student present? (0/1): "))
  if status == 1:
    score = int(input("Enter student score: "))
    stu_li.append([name, score])
  else:
    stu_li.append([name, -1])

print("Present students: ")
for i in range(num):
  if stu_li[i][1] != -1:
    print(stu_li[i], end=' ')
print()

print("Absent students: ")
for i in range(num):
  if stu_li[i][1] == -1:
    print(stu_li[i], end=' ')
print()

print("Choices : 1 = avg, 2 = max, 3 = min, 4 = freq, 5 = stop")
ch = 0
while ch != 5:
  ch = int(input("Enter choice: "))
  if ch == 1:
    avg = avg_score(stu_li, num)
    print("Average score: ", avg)
  elif ch == 2:
    max = get_max(stu_li, num)
    print("Maximum score: ", max)
  elif ch == 3:
    min = get_min(stu_li, num)
    print("Minimum score: ", min)
  elif ch == 4:
    freq_list = check_freq(stu_li, num)
    print("Most frequent scores: ", freq_list)
  elif ch == 5:
    break
  else:
    print("Invalid choice")
 '''   


        
    
    
            
            
        
        