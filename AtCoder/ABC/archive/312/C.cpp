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
  int n, m; cin >> n >> m;
  vector<ll> A(n), B(m);
  rep(i, n) cin >> A[i];
  rep(i, m) cin >> B[i];
  vector<pair<ll, int>> C(n+m);
  rep(i, n) C[i] = {A[i], 0};
  rep(i, m) C[i+n] = {B[i]+1, 1};
  sort(all(C));
  int l = 0;
  vector<int> cnt(2);
  cnt[1] = m;
  while(l < n+m) {
    int r = l;
    while(r < n+m && C[r].first == C[l].first) {
      int f = C[r].second;
      if(f == 0) cnt[f]++;
      else cnt[f]--;
      r++;
    }
    if(cnt[0] >= cnt[1]) {
      cout << C[l].first << endk;
      break;
    }
    l = r;
  }
  return 0;
}
