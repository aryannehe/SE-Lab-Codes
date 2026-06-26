class Data:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.chain = -1
        
class Hashing:
    def __init__(self):
        self.size = int(input("Enter the size of the table: "))
        self.table = [Data(-1, -1)]*self.size
        
    def insert(self, k, v):
        self.index = k % self.size
        
        if self.table[self.index] == -1:
            self.table[self.index] = Data(k, v)
            return
            
        else:
            for i in range(1, self.size):
                self.index = (k + i) % self.size
                if self.table[self.index].key == -1:
                    j = 0
                    while j < self.size:
                        if self.table[j].key % self.size == k % self.size and self.table[j].chain == -1:
                            self.table[j].chain = self.index
                        j += 1
                    self.table[self.index] = Data(k, v)
                    return
            else:
                print("Error in Inserting object in table")
        
    def search(self, k):
        self.count = 1
        for i in range(self.size):
            self.index = (k + i) % self.size
            
            if self.table[self.index].key == k:
                print("Found.")
                return self.index
            
            elif self.table[self.index].chain != -1:
                while self.table[self.index].chain != -1:
                    if self.table[self.table[self.index].chain].key == k:
                        print("Found using chaining")
                        return self.table[self.index].chain
                    self.index = self.table[self.index].chain
            else:
                self.count += 1
        else:
            print("Not found")
            return -1
        
    def delete(self, k):
        self.index = self.search(k)
        if self.index != -1:
            self.table[self.index].key = -1
            self.table[self.index].value = -1
            chainVal = self.table[self.index].chain
            self.table[self.index].chain = -1
            
            j = 0
            while j < self.size:
                if self.table[j].chain == self.index:
                    self.table[j].chain = chainVal
                    print("Key deleted.")
                    return
                j += 1
        else:
            print("Key doesnt exist.")
        
                
    def display(self):
        print("Index \t Key \t\t Value \t Chain")
        for i in range(0, self.size):            
            print(i, "\t", self.table[i].key, "\t", self.table[i].value, "\t\t", self.table[i].chain)
            
hashTable = Hashing()
hashTable.insert(1, "one")
hashTable.insert(2, "two")
hashTable.insert(12, "twelve")
hashTable.insert(21, "twentyone")
hashTable.insert(3, "three")
hashTable.insert(6, "six")

hashTable.display()
                    
             
        