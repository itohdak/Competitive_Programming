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
  map<int, int> cnt;
  rep(i, n) {
    cin >> A[i];
    cnt[A[i]]++;
  }
  vector<vector<int>> ans(2);
  vector<int> stock;
  for(auto ele: cnt) {
    if(ele.second > 2) {
      cout << "NO" << endk;
      return;
    } else if(ele.second == 2) {
      ans[0].push_back(ele.first);
      ans[1].push_back(ele.first);
    } else {
      stock.push_back(ele.first);
    }
  }
  cout << "YES" << endk;
  for(int s: stock) ans[1].push_back(s);
  sort(all(ans[0]));
  sort(all(ans[1]), greater<int>());
  cout << ans[0].size() << endk;
  for(int a: ans[0]) cout << a << ' ';
  cout << endk;
  cout << ans[1].size() << endk;
  for(int a: ans[1]) cout << a << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
