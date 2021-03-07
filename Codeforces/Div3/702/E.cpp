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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> B(n); rep(i, n) B[i] = A[i];
  sort(all(B));
  vector<ll> sum(n+1);
  rep(i, n) sum[i+1] = sum[i] + B[i];
  vector<bool> canWin(n);
  canWin[n-1] = true;
  // cout << sum << endk;
  rrep(i, n-1) {
    int j = upper_bound(all(B), sum[i+1]) - begin(B) - 1;
    canWin[i] = canWin[j];
    // cout << i << ' ' << j << endk;
    // cout << canWin << endk;
  }
  set<int> st;
  rep(i, n) if(canWin[i]) st.insert(B[i]);
  vector<int> ans;
  rep(i, n) {
    if(st.count(A[i])) ans.push_back(i);
  }
  cout << ans.size() << endk;
  for(int a: ans) cout << a+1 << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
