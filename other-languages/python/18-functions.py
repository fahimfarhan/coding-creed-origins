def my_func():
  print("hello there")

my_func()

def my_func2(input):
  print(input + " dadada")

my_func2("A ")
my_func2("hello there")

def my_func3(input = "bd"):
  print("I am from "+input)

my_func3()
my_func3("usa")

def fib(n = 0):
  if n == 0:
    return 0
  elif n == 1:
    return 1
  else:
    return fib((n-1)) + fib((n-2))


print(fib(7))