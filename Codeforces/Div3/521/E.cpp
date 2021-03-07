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
  vector<ll> A(n);
  map<ll, int> cnt;
  rep(i, n) {
    cin >> A[i];
    cnt[A[i]]++;
  }
  vector<int> v;
  for(auto ele: cnt) v.push_back(ele.second);
  sort(all(v));
  int mx = 0;
  REP(i, 1, n+1) {
    ll c = 0;
    ll tmp = i;
    int pos = 0;
    while(1) {
      auto itr = lower_bound(begin(v)+pos, end(v), tmp);
      if(itr == end(v)) break;
      pos = itr-begin(v)+1;
      c += tmp;
      tmp *= 2;
    }
    chmax(mx, c);
  }
  cout << mx << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
