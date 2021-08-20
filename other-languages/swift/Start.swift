var name = "John"
var language = "Swift"

var message1 = "Welcome to the wonderful world of "
var message2 = "\(name) Welcome to the wonderful world of \(language)!"
print(name, message1, language, "!") // this one automatically puts a space between the words
print(message2)
var message3 = name + message1 + language // the beste
print(message3)


// -------------------------
var x = 10
var y: Int = 5
var z: Int = x + y
print(z)

let SOME_CONSTANT = 5

var f: Float = 3.14
var b: Bool = true
var someChar: Character = "S"
var someString: String = "Ricardo Milos"
var d: Double = 3.14159

func test() {
  var number = 5
  if(number > 0) {
    print("numer is > 0")
  }else {
    print("number < 0")
  }

  // for i in 1...3 {
  //   print(i)
  // }

  var myarray: [Int] = [9,8,7,6]
  for i in myarray {
    print(i)
  }

  print(myarray[1])

  var mp = ["Ricardo": 1, "Milos":2]
  mp["Dota"] = 3
  print(mp)
  print(mp["Ricardo"])
  print(mp["homo"])
}

test()

func addNums(a: Int, b: Int) -> Int {
  return (a + b)
}

print(addNums(a: 1,b: 2)) // watch out