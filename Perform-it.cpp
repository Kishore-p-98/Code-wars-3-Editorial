Perform it : https://www.hackerrank.com/contests/codewars-3-rvce/challenges/perform-it

Complexity - O(n)

----------------------------------------------------------------------------------------

Solution : 

Let us define cost of subbarray as sum of minimum and maximum

The problem basically demands to find the minimum cost of all possible sub-arrays of length atleast two.

  Observation : Considering each element as minimum . We observe it is optimal to choose adjacent element as other element 
               because as we move away ,our max is increase or remain same but never decrease.

-------------------------------------------------------------------
      
Code :      

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        int mini = INT_MAX;
        for(int i=0; i<n-1; i++) 
            mini = min(mini, a[i] + a[i+1]);
        cout << mini << endl;
    }
    return 0;
}
