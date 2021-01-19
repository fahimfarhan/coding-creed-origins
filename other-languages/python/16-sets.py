myset = {1,2,2,3}
print(myset)

some_set = set((1,2,3,3,4))
print(some_set)

some_set.add(7)

some_set2 = set((8,9,10))
some_set.union(some_set2)
print(some_set)

z = some_set.difference(myset)
print(z)

some_set.intersection_update(myset)
print(some_set)

