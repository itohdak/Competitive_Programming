#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int T;
  cin >> T;
  rep(t, T) {
    int N;
    cin >> N;
    multiset<ll> se;
    map<int, vector<ll> > mp;
    rep(i, N) {
      int m; ll p;
      cin >> m >> p;
      if(!mp.count(m)) mp[m] = vector<ll>();
      mp[m].push_back(p);
    }
    int tmp = 0;
    map<int, int, greater<ll> > num; // num[x]: # of voter who has m < x
    for(auto m: mp) {
      num[m.first] = tmp;
      tmp += m.second.size();
    }
    int cnt = 0;
    ll ans = 0;
    for(auto n: num) {
      for(auto p: mp[n.first]) se.insert(p);
      if(n.second + cnt < n.first) {
        int rem = n.first - n.second - cnt;
        rep(i, rem) {
          auto top = se.begin();
          ans += *top;
          se.erase(top);
          cnt++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

