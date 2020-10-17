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
  int n, k; cin >> n >> k;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> r(n), l(n);
  rep(i, n) {
    if(i < n-1) r[i] = i+1;
    else r[i] = -1;
    if(i) l[i] = i-1;
    else l[i] = -1;
  }
  vector<int> id(n); rep(i, n) id[i] = i;
  sort(all(id), [&](int i, int j) {
    return A[i] > A[j];
  });
  vector<int> col(n, -1);
  int flag = 0;
  for(int i: id) {
    if(col[i] >= 0) continue;
    col[i] = flag;
    if(l[i] != -1) r[l[i]] = r[i];
    if(r[i] != -1) l[r[i]] = l[i];
    {
      int tmp = l[i];
      rep(j, k) {
        if(tmp < 0 || tmp >= n) break;
        col[tmp] = flag;
        if(l[tmp] != -1) r[l[tmp]] = r[tmp];
        if(r[tmp] != -1) l[r[tmp]] = l[tmp];
        tmp = l[tmp];
      }
    }
    {
      int tmp = r[i];
      rep(j, k) {
        if(tmp < 0 || tmp >= n) break;
        col[tmp] = flag;
        if(l[tmp] != -1) r[l[tmp]] = r[tmp];
        if(r[tmp] != -1) l[r[tmp]] = l[tmp];
        tmp = r[tmp];
      }
    }
    flag = 1-flag;
    // rep(i, n) cout << col[i]+1;
    // cout << endk;
    // cout << l << endk;
    // cout << r << endk;
  }
  rep(i, n) cout << col[i]+1;
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
