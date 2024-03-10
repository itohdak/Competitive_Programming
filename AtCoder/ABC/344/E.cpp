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
  vector<int> A(n); rep(i, n) cin >> A[i];
  map<int, int> chi, par;
  rep(i, n) {
    chi[A[i]] = (i == n-1 ? inf : A[i+1]);
    par[A[i]] = (i == 0 ? 0 : A[i-1]);
  }
  chi[0] = A[0];
  par[inf] = A[n-1];
  int cnt = n;
  int q; cin >> q;
  rep(i, q) {
    int t; cin >> t;
    if(t == 1) {
      int x, y; cin >> x >> y;
      assert(par.count(x) && chi.count(x));
      int next = chi[x];
      chi[x] = y;
      chi[y] = next;
      par[next] = y;
      par[y] = x;
      cnt++;
    } else {
      int x; cin >> x;
      assert(par.count(x) && chi.count(x));
      int prev = par[x];
      int next = chi[x];
      chi[prev] = next;
      par[next] = prev;
      chi.erase(x);
      par.erase(x);
      cnt--;
    }
    assert(par.size() == cnt+1);
    assert(chi.size() == cnt+1);
  }
  int tmp = 0;
  rep(i, cnt) {
    assert(chi.count(tmp));
    tmp = chi[tmp];
    cout << tmp << ' ';
  }
  cout << endk;
  return 0;
}
