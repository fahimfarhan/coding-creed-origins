
x = "hello 1";

def my_func():
  x = "hello 2";
  print(x);

print(x);
my_func();


y = "hello y";
def my_func_1():
  global y;           # this means the y refers to the outer y
  y = "hello y 2";
  print(y);  

my_func_1();
print(y);
