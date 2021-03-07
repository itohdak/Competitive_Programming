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
  vector<ll> XOR(n);
  map<ll, vector<int>> mp;
  bool hasSame = false;
  ll same;
  rep(i, n) {
    if(i) {
      cout << "XOR " << 1 << ' ' << i+1 << endl;
      cin >> XOR[i];
      mp[XOR[i]].push_back(i);
      if(mp[XOR[i]].size() > 1) {
        hasSame = true;
        same = XOR[i];
      }
    }
  }
  if(hasSame) {
    vector<ll> ans(n);
    int p1 = mp[same][0], p2 = mp[same][1];
    cout << "AND " << p1+1 << ' ' << p2+1 << endl;
    cin >> ans[p1];
    ans[p2] = ans[p2];
    ans[0] = XOR[p1] ^ ans[p1];
    rep(i, n) {
      if(i) ans[i] = XOR[i] ^ ans[0];
    }
    cout << "! ";
    rep(i, n) cout << ans[i] << ' ';
    cout << endl;
  } else {
    assert(mp.count(n-1));
    int a = 0, b = mp[n-1][0], c = (b == 1 ? 2 : 1);
    cout << "AND " << b+1 << ' ' << c+1 << endl;
    ll ANDbc; cin >> ANDbc;
    cout << "AND " << a+1 << ' ' << c+1 << endl;
    ll ANDac; cin >> ANDac;
    ll ab = n-1, bc = (XOR[b]^XOR[c])+2*ANDbc, ac = XOR[c]+2*ANDac;
    ll abc = (ab+bc+ac)/2;
    vector<ll> ans(n);
    ans[a] = abc-bc;
    rep(i, n) {
      if(i) ans[i] = XOR[i] ^ ans[0];
    }
    cout << "! ";
    rep(i, n) cout << ans[i] << ' ';
    cout << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
