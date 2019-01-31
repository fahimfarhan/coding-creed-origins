    #include<bits/stdc++.h>
    using namespace std;
    int digit(int n)
    {
    	int m,r,arr[4]={0};
    	m=n;
    	int p=0;
     
    	int i=0;
     
    	while(m!=0)
    	  {
    	  	r=m%10;
    	  	m=m/10;
    	  	arr[i]=r;
    	  	i++;
    	  }

          for(int i=0; i<4; i++){
              cout<<arr[i];
          }
          cout<<endl;
          cout<<i<<endl;
     
    	arr[i]='\0';  
    	int j,k;
     
    	for(j=0;j<4;j++)
    	  {
    	  	for(k=j+1;k<4;k++)
    	    if(arr[j]==arr[k])
    	      {
    	        p=1;
    	        break;	
    		  }
     
    	  }
    	return p;    
    }
     
    int main()
    {
    	int n,i;
    	scanf("%d",&n);
     
    	for(i=n+1;i<=9000;i++)
    	  {
     
    	  	int c=digit(i);
     
    	  	if(c==0)
    	  	  {
    	  	    printf("%d",i);
    	  	    break;
    		  }
    	  }	
    }