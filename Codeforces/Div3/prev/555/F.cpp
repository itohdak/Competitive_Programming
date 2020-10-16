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
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> cnt(200001), sum(200002);
  rep(i, n) cnt[A[i]]++;
  rep(i, 200001) sum[i+1] = sum[i] + cnt[i];
  int l = 0, r = 0;
  int mx = 0;
  int mxl, mxr;
  while(l < 200001) {
    while(l < 200001 && cnt[l] == 0) l++; // 1 or >=2
    r = l+1;
    while(r < 200001 && cnt[r] >= 2) r++;
    if(sum[min(r+1, 200001)]-sum[l] > mx) {
      mx = sum[min(r+1, 200001)]-sum[l];
      mxl = l;
      mxr = r;
    }
    l = r;
  }
  vector<int> ans;
  REP(i, mxl, mxr+1) {
    if(i == mxl || i == mxr) rep(j, cnt[i]) ans.push_back(i);
    else rep(j, cnt[i]-1) ans.push_back(i);
  }
  for(int i=mxr-1; i>=mxl+1; i--) ans.push_back(i);
  assert((int)ans.size() == mx);
  cout << mx << endk;
  for(int a: ans) cout << a << ' '; cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
