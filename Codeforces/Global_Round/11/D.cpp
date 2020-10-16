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
  vector<int> C(n);
  rep(i, n) cin >> C[i];
  int flag = 1;
  vector<vector<int>> ans;
  vector<vector<int>> v(2, vector<int>(n));
  copy(all(C), begin(v[0]));
  while(true) {
    deque<int> next;
    v[flag] = vector<int>(n);
    int prev = 0;
    ans.push_back(vector<int>());
    rep(i, n-1) {
      if((flag ? v[1-flag][i]<v[1-flag][i+1] : v[1-flag][i]>v[1-flag][i+1])) {
        ans.back().push_back(i+1-prev);
        for(int j=i; j>=prev; j--) {
          next.push_front(v[1-flag][j]);
        }
        prev = i+1;
      }
    }
    if(n-prev) {
      ans.back().push_back(n-prev);
      for(int j=n-1; j>=prev; j--) {
        next.push_front(v[1-flag][j]);
      }
    }
    if(flag && (int)ans.back().size() == n) {
      ans.pop_back();
      break;
    }
    if((int)ans.back().size() == 1) ans.pop_back();
    rep(i, n) v[flag][i] = next[i];
    // cout << v[flag] << endk;
    flag = 1-flag;
  }
  cout << ans.size() << endk;
  for(auto a: ans) {
    cout << a.size() << ' ';
    for(auto aa: a) cout << aa << ' ';
    cout << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
