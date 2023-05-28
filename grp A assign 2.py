

HashTable = [[] for i in range(10)]

def Hashing(keyvalue):
    return keyvalue%len(HashTable)

def insert(HashTable,keyvalue,value):
    Hash_key = Hashing(keyvalue)
    HashTable[Hash_key].append(value)
    
def display(HashTable):
    print("\t\tRoll No: \n")
    print("\tIndex\tNames")
    for i in range(len(HashTable)):
        print("\t",i,end="  ")
        
        for j in HashTable[i]:
            print("--->",end=" ")
            print(j,end=" ")
            
        print()

def delete(HashTable,value):
    flag = 0
    for i in range(len(HashTable)):
        for j in HashTable[i]:
            if(j==value):
                HashTable[i].remove(j)
                print("Value Deleted!")
                flag = 1
    if(flag==0):
        print("Invalid!")
        
def find(HashTable,value):
    flag = 0
    for i in range(len(HashTable)):
        for j in HashTable[i]:
            if(value==j):
                print("Value Found!")
                flag = 1
    if(flag==0):
        print("Value is not Present")

print("\t\t**MENU**\n\t1)Insert new roll number\n\t2)Display\n\t3)Delete\n\t4)Find\n\t5)Quit")
choice = int(input("\n\tEnter choice: "))
while(choice!=5):
    if(choice==1):
        tele_no = int(input("Enter roll number: "))
        name = input("Enter person's name: ")
        insert(HashTable,tele_no,name)
        print("Inserted successfully!")
    elif(choice==2):
        print("\n***************************************************\n")
        display(HashTable)
        print("\n***************************************************\n")
    elif(choice==3):
        name = input("Enter name: ")
        delete(HashTable,name)
    elif(choice==4):
        name=input("Enter name: ")
        find(HashTable,name)

    else:
        print("Invalid input!")
    print("\t\t**MENU**\n\t1)Insert new roll number\n\t2)Display\n\t3)Delete\n\t4)Find\n\t5)Quit")
    choice = int(input("\n\tEnter choice: "))




