Colors : https://www.hackerrank.com/contests/codewars-3-rvce/challenges/colors-1

Complexity : O(n)

Solution :
The problem reduces to find the value of maximum of frequency of elements in the given array.

CODE :

#include<bits/stdc++.h>
using namespace std;

int main()
{
 int n,i,a;
 cin>>n;

 int freq[101]={0},ans=0;

 for(i=0;i<n;i++)
  {
   cin>>a;
   freq[a]++;
   ans=max(ans,freq[a]);
  }

  cout<<ans<<endl;
  return 0;
}
