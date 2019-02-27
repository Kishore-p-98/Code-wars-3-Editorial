#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while(tc--) {
		int n, m, temp;
		cin >> n >> m;
		bool isp[1000001];
		memset(isp, false, sizeof(isp));
		for(int i=0; i<n; i++) {
			cin >> temp;
			isp[temp] = true;
		}
		for(int i=0; i<m; i++) {
			cin >> temp;
			isp[temp] = false;
		}
		int c = 0;
		for(int i=1; i<=1000000; i++) if(isp[i]) c++;
		cout << (n - c) << endl;
	}
	return 0;
}
