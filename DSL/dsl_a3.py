'''
DSL Group A: Assignment 3 
Neeti Kurulkar
SE A 21038

In Second year Computer Engineering class of M students, set A of students play cricket and set B
of students play badminton. Write python program to find and display-
A. Set of students who play either cricket or badminton or both
B. Set of students who play both cricket and badminton
C. Set of students who play only cricket
D. Set of students who play only badminton
E. Number of students who play neither cricket nor badminton

'''


class SE:
    students, cricket, badminton = [], [], []
    stu_no, cri_no, bad_no, count = 0, 0, 0, 0
    
    #---------------------------------------------------------------------------
    def __init__(self):
        self.name = input("Enter name of student: ")
        SE.students.append(self.name)
        SE.stu_no += 1
        
    #---------------------------------------------------------------------------
    def get_list(self):
        c = input("Does student play cricket? y/n: ")
        if c == "y" or c == "Y":
            SE.cricket.append(self.name)
            SE.cri_no += 1
        b = input("Does student play badminton? y/n: ")
        if b == "y" or b == "Y":
            SE.badminton.append(self.name)
            SE.bad_no += 1
    
    #--------------------------------------------------------------------------- 
    #Function to find students who play both cricket and badminton 
    def intersection(self):
        inter_list = []
        for i in range(SE.cri_no):
            for j in range(SE.bad_no):
                if SE.cricket[i] == SE.badminton[j]:
                    inter_list.append(SE.cricket[i])
        return inter_list
    
    #---------------------------------------------------------------------------  
    #Function to find students who play either cricket or badminton
    def union(self):
        union_list = []
        union_list.extend(SE.cricket)
        SE.count += SE.cri_no
        for i in range(SE.bad_no):
            for j in range(SE.cri_no):
                if SE.badminton[i] == union_list[j]:
                    exist = True
                    break
                else: 
                    exist = False
            if exist == False: 
                union_list.append(SE.badminton[i])
                SE.count += 1
        return union_list
    
    #---------------------------------------------------------------------------   
    #Function to find students who play only one game
    def only(self, li1, li2, n1, n2):
        only_list = []
        only_list.extend(li1)
        for i in range(n1):
            for j in range(n2):
                if li1[i] == li2[j]:
                    only_list.remove(li1[i])
        return only_list    
            

#---------------------------------End of SE class-------------------------------

n = int(input("Enter number of students:"))
for i in range(n):
    s = SE()
    s.get_list()

print("Students who play cricket:", SE.cricket)
print("Students who play badminton:", SE.badminton)
print("Students who play both: ", s.intersection())
print("Students who play either: ", s.union())
print("Cricket only: ", s.only(SE.cricket, SE.badminton, SE.cri_no, SE.bad_no))
print("Badminton only: ", s.only( SE.badminton, SE.cricket, SE.bad_no, SE.cri_no))
print("Neither:", (SE.stu_no - SE.count), "Students.") 


        
    
    
            
            
        
        