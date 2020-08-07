#!/bin/bash

# list a speccific directory 
ls /home/fahimfarhan/Codes/

# mkdir d1 d2 dn 
mkdir d1 d2 dn 

# mkdir /home/fahimfarhan/Codes/coding-creed-origins/1-other-languages/bash/d4
mkdir /home/fahimfarhan/Codes/coding-creed-origins/1-other-languages/bash/d4

# mkdir with parent dir 
# mkdir d6/d7 : error cz d6 doesnot exist 
# so use mkdir -p d6/d7
mkdir -p d6/d7

# renaming dir: mv olddir newdir
mv d6 d9

# ls -al : a = list , l=show permissions