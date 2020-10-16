#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

bool solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> C(k);
  set<int> unused;
  rep(i, n) unused.insert(i+1);
  rep(i, k) {
    int s;
    cin >> s;
    C[i] = vector<int>(s);
    rep(j, s) {
      cin >> C[i][j];
      unused.erase(C[i][j]);
    }
  }
  // cout << C << endl;
  auto query = [&](int l, int r) {
    set<int> se;
    REP(i, l, r) for(int c: C[i]) se.insert(c);
    cout << "? " << se.size();
    for(int s: se) cout << ' ' << s;
    cout << endl;
    int mx;
    cin >> mx;
    return mx;
  };

  int Mx;
  cout << "? " << n;
  rep(i, n) cout << ' ' << i+1;
  cout << endl;
  cin >> Mx;

  auto binary_search = [&]() {
    ll l = 0, r = k;
    while(abs(r - l) > 1) {
      ll mid = (r + l) / 2;
      int res = query(mid, r);
      if(res == -1) return -1LL;
      else if(res == Mx) l = mid;
      else r = mid;
    }
    return l;
  };
  int mxi = binary_search();
  if(mxi == -1) return false;

  int mx;
  set<int> se;
  for(int u: unused) se.insert(u);
  rep(i, k) if(i != mxi) for(int c: C[i]) se.insert(c);
  cout << "? " << se.size();
  for(int s: se) cout << ' ' << s;
  cout << endl;
  cin >> mx;

  cout << "! ";
  rep(i, k) {
    if(i != mxi) cout << Mx << ' ';
    else         cout << mx << ' ';
  }
  cout << endl;

  string res;
  cin >> res;
  return (res == "Correct");
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) if(!solve()) break;
  return 0;
}
