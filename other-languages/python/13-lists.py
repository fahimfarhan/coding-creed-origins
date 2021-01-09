list1 = [1,2,3,7,4]
list2 = list(list1)

print(list1)
print(list2)

print("list1[-1] is the last item "+str(list1[-1]))

list1.append(5)
list1.insert(1, 7)

print(list1)

list1.remove(7) # removes the first occurance of 7
print(list1)

list1.remove(7) # removes the 2nd (now first) occurance of 7
print(list1)
# list1.remove(7) error if item doesnot exist
# print(list1)

remove_at_index = 0  # 0 based indexing
list1.pop(remove_at_index) 
print(list1)

list1.pop()  # removes last item
print(list1)

del list1  # cpp delete[] list1; 
# print(list1) so now this gives error

list2.clear() # cpp vectorV.clear();
print(list2)  # empty list