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
  int one = -1;
  vector<int> two;
  for(int i=0; i+1<n; i+=2) {
    cout << "? " << 2 << ' ' << i+1 << ' ' << i+2 << ' ' << 1 << endl;
    int ret;
    cin >> ret;
    if(ret == 1) {
      one = i;
      break;
    } else if(ret == 2) {
      // assert(ret == 2);
      two.push_back(i+1);
    }
  }
  if(one == -1) {
    if(two.empty()) {
      assert(n%2);
      one = n-1;
    } else {
      assert(two.size() <= 2);
      for(int i: two) {
        if(i >= 1) {
          cout << "? " << 2 << ' ' << i+1 << ' ' << i << ' ' << 1 << endl;
          int ret;
          cin >> ret;
          if(ret == 1) {
            one = i;
            break;
          }
        }
      }
      if(one == -1) {
        assert(n%2);
        one = n-1;
      }
    }
  }
  assert(one != -1);
  vector<int> ans(n);
  ans[one] = 1;
  rep(i, n) {
    if(i != one) {
      cout << "? " << 1 << ' ' << one+1 << ' ' << i+1 << ' ' << n-1 << endl;
      int ret;
      cin >> ret;
      ans[i] = ret;
    }
  }
  cout << "! ";
  rep(i, n) cout << ans[i] << ' ';
  cout << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
