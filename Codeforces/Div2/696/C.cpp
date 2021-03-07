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
  vector<int> A(2*n); rep(i, 2*n) cin >> A[i];
  sort(all(A));
  rep(i, 2*n-1) {
    vector<pair<int, int>> ans(n);
    ans[0].first = A.back();
    ans[0].second = A[i];
    // multiset<int> st; rep(j, 2*n-1) if(j != i) st.insert(A[j]);
    map<int, int> mp; rep(j, 2*n-1) if(j != i) mp[A[j]]++;
    bool ok = true;
    REP(j, 1, n) {
      ans[j].first = (--mp.end())->first;
      mp[ans[j].first]--;
      if(mp[ans[j].first] == 0) mp.erase(ans[j].first);
      if(ans[j-1].first-ans[j].first > ans[j].first) {
        ok = false;
        break;
      } else if(!mp.count(ans[j-1].first-ans[j].first)) {
        ok = false;
        break;
      } else {
        ans[j].second = ans[j-1].first-ans[j].first;
        mp[ans[j].second]--;
        if(mp[ans[j].second] == 0) mp.erase(ans[j].second);
      }
    }
    if(!ok) continue;
    cout << "YES" << endk;
    cout << ans[0].first + ans[0].second << endk;
    rep(j, n) cout << ans[j].first << ' ' << ans[j].second << endk;
    return;
  }
  cout << "NO" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
