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
