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
  vector<int> P(n);
  vector<int> sum;
  int prev = 0;
  rep(i, n) {
    cin >> P[i];
    if(i) {
      if(P[i] != prev) sum.push_back(i);
    }
    prev = P[i];
  }
  sum.push_back(n);
  int m = sum.size();
  int ig = 0;
  int is = lower_bound(sum.begin()+ig, sum.end(), sum[ig]*2+1) - sum.begin();
  if(is == m) {
    cout << 0 << ' ' << 0 << ' ' << 0 << endk;
    return;
  }
  int ib = lower_bound(sum.begin()+is, sum.end(), sum[is]+sum[ig]+1) - sum.begin();
  if(ib == m) {
    cout << 0 << ' ' << 0 << ' ' << 0 << endk;
    return;
  }
  if(sum[ib] > n/2) {
    cout << 0 << ' ' << 0 << ' ' << 0 << endk;
    return;
  }
  while(ib < m-1 && sum[ib+1] <= n/2) ib++;
  int cg = sum[ig], cs = sum[is]-sum[ig], cb = sum[ib]-sum[is];
  cout << cg << ' ' << cs << ' ' << cb << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
