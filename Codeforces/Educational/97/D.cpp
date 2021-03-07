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
  rep(i, n) {
    cin >> A[i];
    A[i]--;
  }
  int l = 1, r = 1;
  vector<int> cnt;
  cnt.push_back(1);
  while(l < n) {
    r = l;
    while(r < n-1 && A[r] < A[r+1]) r++;
    cnt.push_back(r-l+1);
    l = r+1;
  }
  l = 0;
  int ans = -1;
  int prev = 1;
  while(l < (int)cnt.size()) {
    ans++;
    int val = 0;
    rep(i, prev) {
      val += cnt[l++];
      if(l == (int)cnt.size()) break;
    }
    prev = val;
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
