#include<iostream>
using namespace std;
int geekonacci(int a,int b,int c,int n)
{
    if(n==1)return a;
    if(n==2)return b;
    if(n==3)return c;
    return(geekonacci(a,b,c,n-1)+geekonacci(a,b,c,n-2)+geekonacci(a,b,c,n-3));
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int a,b,c,n;
	    cin>>a>>b>>c>>n;
	    int ans=geekonacci(a,b,c,n);
	    cout<<ans<<endl;
	}
	return 0;
}