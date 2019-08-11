## Cool Stuffs
Return 1st '1' from right ( 1011 0`1`00 that  highlighted one )
```
int lowestbit(int x){	return x&(-x);	}
```
```
next_permutation(v.begin(), v.end());
```

```
regex_match(s,regex("(1|14|144)*"));
```

```
std::string data = "Abc";
std::transform(data.begin(), data.end(), data.begin(), ::tolower);
```
```
for (std::string::size_type i = 0; i < str.length(); ++i)
    std::cout << std::tolower(str[i], loc);
```

### UVA style input... 
```
while(getline(cin, s[line])){
            if(s[line].length()>longest){
                longest = s[line].length();
            }
            line++;
        }    
```

### search for smallest element's index in an array in range[l,r]
```
int m=min_element(a+l,a+r+1)-a;
``` 