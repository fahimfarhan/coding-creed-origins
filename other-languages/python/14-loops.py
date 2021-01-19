a = [1,2,3,4,5,6,7]

for n in a:  # cpp for(auto n : a) {...}
  print(n)

for i in range(len(a)):  # loop using index
  print(a[i])

k = 0
while k < len(a):
  print(a[k]) # no need for global :/
  k = k + 1

[print(x) for x in a]  # oneline, popular among python coders

"""
newlist = [expression for item in iterable if condition == True]
"""

b = [3,1,2,6,7,4,5]
b.sort(reverse=False)
print(b)

b.sort(reverse=True)
print(b)

c = b.copy()
print(c)


print("the for loop")
for i in range(0,8):
  print(i)