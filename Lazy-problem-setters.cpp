Lazy problem setters : https://www.hackerrank.com/contests/codewars-3-rvce/challenges/lazy-problem-setters

Complexity : O(n)

--------------------------------------------------------------------------------
Solution :

There are two types of contests - 
A : 2 hard one easy
B : 2 easy one hard

Let us fix number of A type contest as i ,then remaining easy questions are n-i 
and remaining hard questions are m-2*i .
Number of type B contest that can be conducted with the remaining questions is  min(m-2*i,(n-i)/2).

Hence Try for all possile i(0<=i<=n) and calculate the maximum possible.

-----------------------------------------------------------------------------------

Code :

#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n,m;
   cin>>n>>m;

   int i;
   int ans=0;

   for(i=0;i<=n;i++)
   {
    if(2*i <= m)
    {
     ans=max(ans,i + min((n-i)/2,m-2*i)); 
    }
   }

  cout<<ans<<endl;
  return 0;
}
