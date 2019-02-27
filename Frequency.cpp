__Frequency__ : https://www.hackerrank.com/contests/codewars-3-rvce/challenges/frequency-4-2/problem

Complexity : O(n) per testcase

Prerequisites : Two pointer technique

---------------------------------------------------------------------------------

Solution : 

Each sub-array is uniquely identified by its left most and right most end points.
So if any sub-array has atleast one element with frequency >=m then all sub-array covering 
this can be included in the answer.

Maintain a map to store the frequency of elements
Maintain leftindex,rightindex.
Increment the counter when ever rightindex includes an element which satifies the condtion
and move the leftindex to come to a position where condition is the not satisfied.
Repeat this and increment accordingly.

See code for clarity .

----------------------------------------------------------------------------------

Code :

#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn];

int main()
{
  
  int t;
  cin>>t;

  while(t--)
  {
   long long i,j,n,m,ans=0;
   cin>>n>>m;
      
   for(i=0;i<n;i++)
    cin>>a[i];
   
   i=0;
   j=0;
   
  map<long long,long long> mp;
 
   while(j<n)
   {
    mp[a[j]]++;
    
    if(mp[a[j]]==m)
    {
       do
      {
        ans+=n-j;  // n-j end points are there for each ith starting point
        mp[a[i]]--;  
        ++i; 
      } while(a[i-1]!=a[j]);
    }
  
   ++j;
   }
 
  cout<<ans<<endl;
  }

  return 0;
}


