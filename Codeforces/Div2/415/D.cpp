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

bool query(int x, int y) {
  if(x == -1) return false;
  cout << 1 << ' ' << x << ' ' << y << endl;
  string s; cin >> s;
  return s == "TAK";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  auto bsearch = [&](int l, int r) {
    auto test = [&](int t) {
      return query(t, t+1);
    };
    if(l > r) return -1;
    while(l < r) {
      int mid = (l+r)/2;
      if(query(mid, mid+1)) r = mid;
      else l = mid+1;
    }
    return l;
  };
  int pos1 = bsearch(1, n);
  int pos2 = bsearch(1, pos1-1);
  int pos3 = bsearch(pos1+1, n);
  if(query(pos2, pos1)) {
    cout << 2 << ' ' << pos2 << ' ' << pos1 << endl;
  } else {
    cout << 2 << ' ' << pos1 << ' ' << pos3 << endl;
  }
  return 0;
}
