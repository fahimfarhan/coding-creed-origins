class MyClass:
  x = 5

some_class = MyClass()
print(some_class.x)

class Person:
  _name = 0
  _age = 0
  
  def __init__(self, name, age):
    self._name = name
    self._age = age
    self._somethingelse = name

  def some_other_method(self):  # the first param is equivalent to this.
    # you can give it any name,,,
    print("hello there "+str(self._name))

  def try_this(this, a, b):
    this._name = a
    this._age = b
    print(this._name + this._age)

p = Person(1,2)
print(p._name)
print(p._age)
print(p._somethingelse)

p.some_other_method()
p.try_this(7,7)

del p