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
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  vector<int> B = A;
  sort(all(B));
  vector<tuple<int, int, int>> ans;
  rep(i, n) {
    int r = i;
    while(r < n && A[r] != B[i]) r++;
    assert(r < n);
    if(r == i) continue;
    ans.push_back({i, r, r-i});
    for(int j=r; j>i; j--) A[j] = A[j-1];
    A[i] = B[i];
  }
  cout << ans.size() << endk;
  for(auto [l, r, d]: ans) cout << l+1 << ' ' << r+1 << ' ' << d << endk;
  // cout << A << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
