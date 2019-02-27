#include <bits/stdc++.h>

#define N 8192

using namespace std;

const long long MOD = 1000000007;

long long n;
vector<bool> isprime(N+1, true);
vector<long long> primes, a, counts, inp(100001);
long long dp[1005][N + 1];

void makeinp() {
    a.clear();
    counts.clear();
    sort(inp.begin(), inp.begin() + n);
    long long i = 0;
    while(i < n) {
        a.push_back(inp[i]);
        long long  c = 1, t = inp[i];
        i++;
        while(i < n && inp[i] == t) {
            i++;
            c++;
        }
        counts.push_back(c);
    }
    vector<long long> temp(8193, -1);
    memset(dp, -1, sizeof(dp));
    if(counts[0] % 2 == 0) dp[0][0] = (counts[0]/2 + 1);
    else dp[0][0] = (counts[0] + 1)/2;
    if(counts[0] % 2 == 0) dp[0][a[0]] = counts[0]/2;
    else dp[0][a[0]] = (counts[0] + 1)/2;
}

long long rec(long long x, long long y) {
    if(dp[x][y] != -1) return dp[x][y];
    if(x == 0) return 0;
    long long t = rec(x - 1, y);
    long long p = rec(x - 1, y ^ a[x]);
    if(counts[x] % 2 == 0) t = t * (counts[x]/2 + 1);
    else t = t * ((counts[x] + 1)/2);
    if(counts[x] % 2 == 0) p = p * counts[x]/2 ;
    else p = p * ((counts[x] + 1)/2);
    dp[x][y] = (t%MOD + p%MOD) % MOD;
    return dp[x][y];
}

void sieve() {
    for(long long i=2; i*i<N+1; i++)
        if(isprime[i] == true)
            for(long long j=2*i; j < N+1; j += i)
                isprime[j] = false;
    for(long long i=2; i<=N; i++)
        if(isprime[i])
            primes.push_back(i);
}

int main() {
    sieve();
    long long tc;
    cin >> tc;
    while(tc--) {
        inp.clear();
        cin >> n;
        for(long long i=0; i<n; i++) {
            cin >> inp[i];
        }
        makeinp();
        long long ans = 0;
        for(long long i=0; i<primes.size(); i++) {
            ans = (ans + rec(a.size() - 1, primes[i])) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
