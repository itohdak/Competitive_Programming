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
  int n, x; cin >> n >> x;
  vector<int> W(n); rep(i, n) cin >> W[i];
  ll sum = accumulate(all(W), 0LL);
  if(sum == x) cout << "NO" << endk;
  else {
    cout << "YES" << endk;
    ll tmp = 0;
    rep(i, n) {
      if(tmp + W[i] == x) {
        if(i+1 < n) swap(W[i], W[i+1]);
        else swap(W[i-1], W[i]);
      }
      tmp += W[i];
      assert(tmp != x);
    }
    rep(i, n) cout << W[i] << ' ';
    cout << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
