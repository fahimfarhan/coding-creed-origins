mytuple = tuple(("a", "b", "c"))
print(mytuple)

print(mytuple[0])

print(mytuple[-1])

# we cannot change tuples, so we have to
# basically create a new tuple, maybe point
# old reference to the new one

old_tuple = tuple((1,2,3))
temp_list = list(old_tuple)
temp_list[1] = 7
old_tuple = tuple(temp_list)
print(old_tuple)


for i in old_tuple:
  print(i)

new_tuple = old_tuple + mytuple
print(new_tuple)
