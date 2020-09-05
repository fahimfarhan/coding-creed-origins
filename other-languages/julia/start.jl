s1 = "The quick brown fox jumps over the lazy dog α,β,γ";
println(s1);
print("this is ");
print("one line\n");

c1 = 'c';
println(c1);
println("this is c1 -> ",c1); # ok
# println("this is c1 -> "+c1); # not ok

num = 7;
println(7);
println("num -> ", num);

s1_caps = uppercase(s1)
s1_lower = lowercase(s1)
println(s1_caps, "\n", s1_lower)

println(s1[11]);
println(s1[1:11]);
show(s1[end-10:end]); 
println();

s3 = string("this", " and", " that")
println(s3)