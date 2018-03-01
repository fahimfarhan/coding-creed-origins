#include<stdio.h>
#include<string.h>
int main()
{
    int word,len,i;
    char s[100000];
    while(scanf("%[^\n]%*c",s)==1)
    {
        word=0;
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if((s[i+1]<'A'||(s[i+1]>'Z'&&s[i+1]<'a')||s[i+1]>'z')&&((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')))
                word++;
        }
        printf("%d\n",word);
    }
}