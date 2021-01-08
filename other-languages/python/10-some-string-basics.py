s = "a quick brown fox jumped over the lazy dog";

has_fox = ("fox" in s);
print(has_fox);

without_fox = ("fox" not in s);
print(without_fox);

a = s[2:5]  # 0 based indexing, startIndex inclusive, endIndex exclusive  [2, 5) 
print(a);

b = s[2:];
c = s[:5];

print(b);
print(c);

