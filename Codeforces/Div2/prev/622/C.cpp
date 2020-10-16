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

void solve() {
  int n; cin >> n;
  vector<ll> M(n); rep(i, n) cin >> M[i];
  ll mx = 0;
  vector<ll> ans;
  rep(i, n) {
    ll cur = 0;
    vector<ll> tmp;
    cur += M[i];
    tmp.push_back(M[i]);
    {
      ll pre = M[i];
      for(int j=i-1; j>=0; j--) {
        cur += min(M[j], pre);
        pre = min(M[j], pre);
        tmp.push_back(pre);
      }
    }
    reverse(all(tmp));
    {
      ll pre = M[i];
      for(int j=i+1; j<n; j++) {
        cur += min(M[j], pre);
        pre = min(M[j], pre);
        tmp.push_back(pre);
      }
    }
    if(mx < cur) {
      mx = cur;
      ans = tmp;
    }
  }
  rep(i, n) cout << ans[i] << ' '; cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
