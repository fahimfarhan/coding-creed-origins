function myAwesomeFunction()
    println("hello there!");
    end;


myAwesomeFunction();


function sum(a::Int, b::Int)::Float16
    summation::Int = a + b;
    return summation;
end


s = sum(1,2);
println(s);