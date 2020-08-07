#import<ios>
long long k,l,m,n,r,p=1,s;
main()
{
    for(scanf("%lld%lld%lld",&n,&l,&r),m=n,k=r-l+1;m--;)
    p=p*k%3000000021;
    printf("%lld",k%3<1?p/3:(p/3+(k%3>1?r%3>1?n%2?0:1:n%6<2|n%6>4?1:0:r*n%3<1?1:0)+1000000007)%1000000007);
}