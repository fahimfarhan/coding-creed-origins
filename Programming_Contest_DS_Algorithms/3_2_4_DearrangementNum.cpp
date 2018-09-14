#include <bits/stdc++.h>

using namespace std;

int D(int n){
	if(n == 0) return 1;
	if(n == 1) return 0;

	return (n-1)*( D(n-1) + D(n-2));	
}

int main()
{
	/*
	 * Dn = ?
	 *	n jon manush theke 1 jon k select kora jay nC1 = n vabe.
	 *	Let A 1jon manush, tar tupi a.
	 *	A a chhara baki n-1 joner tupi n-1Cn-1 = n-1 vabe nie pare.
	 *	1ta tupi x nei. 
	 *	Onno 1jon lok X. 2ta case aste pare: 1) X a nite pare
	 *	or 2) X a ney nai
	 *
	 *	Case 1: jodi X a ney, tahole oboshishto thake n-2 jon 
	 *	manush o tupi. tader Dearrangement num = Dn-2
	 *	
	 *	So, (n-1)C(n-1)Dn-2 = (n-1)Dn-2
	 *	
	 *	Case 2: jodi na ney, tahole se khono ney ni. total n-1 jon
	 *	manush o tupi. so, 
	 *		(n-1)Dn-1
	 *
	 *	:. Dn = (n-1)( Dn-1 + Dn-2 ) ...  ...  ...  ...  (1),
	 *
	 *
	 *	Base case: 
	 *	D1 = 0 , cz 1 jon manush 1ta tupi, se tupi pabe na
	 *	D0 = 1 , cz 0 jon manush k 1 vabei tupi deya somvob, kauke
	 *	kisu na diye!!! :o
	 * */
	
	int ans = D(5);

	cout<<ans<<"\n";

	return 0;
}
