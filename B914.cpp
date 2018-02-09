#include <bits/stdc++.h>
using namespace std;

class B914{
	private:

	int n, count;
	int *a;
public:
	B914(){
		scanf("%d", &n);
		a = new int[n];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		sort(a, a + n);

		count=0;
		bool b = true;
		int m = a[0];
		for(int i=0; i<n; i++){
			//if(a[i]==m){
			//	count++;
			//}else{
			if(a[i]!=m){
				m = a[i];
				if(count%2==1){
					b = false; break; 
				}else{
					count = 0;
				}
			}
			count++;
		}

		if(b){
			printf("Agasa\n");
		}
		else{
			printf("Conan\n");
		}
	}

  ~B914()
  {
	  if (!a)
		  delete[] a;
  }
};

int main(int argc, char const *argv[])
{
	/* code */
	B914 b914;
	return 0;
}