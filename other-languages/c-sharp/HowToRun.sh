sudo apt update
sudo apt install mono-complete
mcs hello.cs
mono hello.exe

OR 

sudo apt update
sudo apt install mono-complete
mcs hello.cs -out:hello.exe 
mono hello.exe
