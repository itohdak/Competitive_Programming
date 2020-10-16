#include <bits/stdc++.h>
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

int main() {
  int N, K;
  cin >> N >> K;
  set<ll> on_screen;
  queue<ll> q;
  rep(i, N) {
    ll id;
    cin >> id;
    if(!on_screen.count(id)) {
      if((int)on_screen.size() == K) {
        ll top = q.front();
        on_screen.erase(top);
        q.pop();
      }
      q.push(id);
      on_screen.insert(id);
    }
  }
  vector<ll> ans;
  while(!q.empty()) {
    ans.push_back(q.front());
    q.pop();
  }
  reverse(all(ans));
  cout << ans.size() << endl;
  for(ll a: ans) cout << a << ' ';
  cout << endl;
  return 0;
}

