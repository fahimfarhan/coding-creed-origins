function forloop(startNumber,endNumber,increment)
    i = startNumber;
    while (i < endNumber)
        println("i = ", i);
        i= i+increment;
    end;
end;

forloop(0,5,1);