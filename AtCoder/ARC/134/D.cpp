#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> A(2*n); rep(i, 2*n) cin >> A[i];
  map<int, vector<int>> mp;
  rep(i, n) mp[A[i]].push_back(i);
  auto [a, v] = *mp.begin();
  int mn = inf;
  for(int i: v) chmin(mn, A[i+n]);
  if(mn <= a) {
    cout << a << ' ' << mn << endk;
    return 0;
  }
  vector<int> select;
  for(int i: v) select.push_back(i);
  int top = A[select[0]+n];
  bool add = false;
  rep(i, select.size()-1) {
    auto fi = A[select[i]+n], se = A[select[i+1]+n];
    if(fi > se) break;
    else if(fi == se) continue;
    else {
      add = true;
      break;
    }
  }
  for(auto itr=++mp.begin(); itr!=mp.end(); itr++) {
    auto [a, v] = *itr;
    for(int i: v) {
      if(i > select.back() && (A[i] < top || (A[i] == top && add))) {
        select.push_back(i);
      }
    }
  }
  vector<int> ans;
  for(int i: select) ans.push_back(A[i]);
  for(int i: select) ans.push_back(A[i+n]);
  for(int a: ans) cout << a << ' '; cout << endk;
  return 0;
}
