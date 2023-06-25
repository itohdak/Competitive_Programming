#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

ll sum[10000005];
ll mn[10000005];
void Eratosthenes(int N) {
  for(int i=0; i<=N; i++) {
    sum[i] = 0;
    mn[i] = longinf;
  }
  for(int i=1; i<=N; i++) {
    for(int j=1; i*j<=N; j++) {
      sum[i*j] += i;
    }
  }
  for(int i=1; i<=N; i++) {
    if(sum[i] <= N) chmin(mn[sum[i]], i);
  }
}
void solve() {
  ll c; cin >> c;
  cout << (mn[c] == longinf ? -1 : mn[c]) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  Eratosthenes(10000000);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
