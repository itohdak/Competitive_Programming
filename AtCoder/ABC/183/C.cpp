#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; ll k; cin >> n >> k;
  vector<vector<ll>> T(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> T[i][j];
  vector<int> id(n); rep(i, n) id[i] = i;
  int ans = 0;
  do {
    // cout << id << endk;
    ll sum = 0;
    rep(i, n-1) sum += T[id[i]][id[i+1]];
    sum += T[id[n-1]][id[0]];
    if(sum == k) {
      ans++;
    }
  } while(next_permutation(begin(id)+1, end(id)));
  cout << ans << endk;
  return 0;
}
