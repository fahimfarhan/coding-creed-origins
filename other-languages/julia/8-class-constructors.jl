

struct MyAwesomeClass
    a::Int;
    b::Int;

    MyAwesomeClass(a::Int,b::Int) = new(a,b);

    function sum()::Int
        return (a + b);
    end;

    function subs()::Int
        return (a - b);
    end;
end;

myAwesomeClass = MyAwesomeClass(1,2);
println(myAwesomeClass.a," ",myAwesomeClass.b);
println(myAwesomeClass.subs());
println(myAwesomeClass.sum());