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
  vector<int> P(n), pos(n);
  rep(i, n) {
    cin >> P[i];
    P[i]--;
    pos[P[i]] = i;
  }
  int tmp = 0;
  vector<int> ans;
  rep(i, n) {
    int p = pos[i];
    if(i < tmp && P[i] != i) {
      cout << -1 << endk;
      return 0;
    }
    for(int j=p-1; j>=i; j--) {
      ans.push_back(j);
      int a = P[j], b = P[j+1];
      swap(pos[a], pos[b]);
      P[j] = b, P[j+1] = a;
    }
    tmp = p;
    // cout << P << ' ' << pos << endk;
  }
  if(ans.size() != n-1) {
    cout << -1 << endk;
    return 0;
  }
  for(int a: ans) cout << a+1 << endk;
  return 0;
}
