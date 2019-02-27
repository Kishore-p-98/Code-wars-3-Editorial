#include <bits/stdc++.h>

using namespace std;

const long int N = 1000000007;
long int dp[1001][1001];
int n, m, s;
vector<int> moves;

long rec(int move, int j) {
	if(j < 1 || j > n) return 0;
	if(dp[move][j] != -1) return dp[move][j];
	dp[move][j] = (rec(move-1, j-moves[move-1]) +
					rec(move-1, j+moves[move-1]))%N;
	return dp[move][j];
}

int main() {
	int t;
	cin >> t;
	for(int ii=0; ii<t; ii++) {
		cin >> n >> m >> s;
		moves.clear();
		for(int i=0; i<m; i++) {
			int aa;
			cin >> aa;
			moves.push_back(aa);
		}
		for(int i=0; i<=m; i++) {
			for(int j=0; j<=n; j++) {
				if(i == 0 || j == 0)
					dp[i][j] = 0;
				else
					dp[i][j] = -1;
			}
		}
		dp[0][s] = 1;
		for(int i=1; i<=n; i++) {
			cout << rec(m, i) << " ";
		}
		cout << endl;
	}
	return 0;
}
