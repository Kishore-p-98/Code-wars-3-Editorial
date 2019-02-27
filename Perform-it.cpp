Perform it : https://www.hackerrank.com/contests/codewars-3-rvce/challenges/perform-it

Complexity - O(n)

----------------------------------------------------------------------------------------

Solution : 

Let us define cost of subbarray as sum of minimum and maximum

The problem basically demands to find the minimum cost of all possible sub-arrays of length atleast two.

  Observation : Considering each element as minimum. Extend the subarray on either side,it is always optimal
                to choose the adjacent element because when moving on either side,maximum will never decrease
                it will increase or remain same.
      
-----------------------------------------
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
