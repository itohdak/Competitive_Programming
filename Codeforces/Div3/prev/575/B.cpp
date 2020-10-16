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
  int n, k; cin >> n >> k;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> sum(n+1); rep(i, n) sum[i+1] = sum[i] + A[i];
  vector<int> ans;
  int prev = 0;
  bool ok = true;
  rep(i, n) {
    if(ans.size() == k-1) {
      ans.push_back(n);
      if((sum[n]-sum[prev])%2==0) ok = false;
      break;
    } else {
      if((sum[i+1]-sum[prev])%2) {
        ans.push_back(i+1);
        prev = i+1;
      }
    }
  }
  if(!ok || ans.size() < k) {
    cout << "NO" << endk;
  } else {
    cout << "YES" << endk;
    rep(i, k) cout << ans[i] << ' ';
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
