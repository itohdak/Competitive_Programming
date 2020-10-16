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
  int k; cin >> k;
  map<ll, set<int>> mp;
  vector<vector<ll>> A(k);
  vector<ll> sum(k);
  rep(i, k) {
    int n; cin >> n;
    A[i] = vector<ll>(n);
    rep(j, n) {
      cin >> A[i][j];
      sum[i] += A[i][j];
    }
    rep(j, n) mp[sum[i]-A[i][j]].insert(i);
  }
  for(auto ele: mp) {
    if(ele.second.size() > 1) {
      cout << "YES" << endk;
      int f = *ele.second.begin();
      int s = *ele.second.rbegin();
      ll val = ele.first;
      // cout << val << endk;
      rep(j, A[f].size()) {
        if(sum[f]-A[f][j] == val) {
          cout << f+1 << ' ' << j+1 << endk;
          break;
        }
      }
      rep(j, A[s].size()) {
        if(sum[s]-A[s][j] == val) {
          cout << s+1 << ' ' << j+1 << endk;
          break;
        }
      }
      return;
    }
  }
  cout << "NO" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
