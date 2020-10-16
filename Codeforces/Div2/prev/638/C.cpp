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

void solve() {
  int N, K;
  string S;
  cin >> N >> K >> S;
  sort(all(S));
  map<char, int> mp;
  rep(i, N) mp[S[i]]++;
  if(mp.size() == 1) {
    rep(i, (N+K-1)/K) cout << S[0];
    cout << endl;
    return;
  }
  set<char> se;
  rep(i, K) {
    se.insert(S[i]);
    mp[S[i]]--;
    if(mp[S[i]] == 0) mp.erase(S[i]);
  }
  if(se.size() != 1) {
    cout << *(--se.end()) << endl;
  } else {
    if(mp.size() == 1) {
      cout << S[0];
      rep(i, (N-1)/K) cout << S[K];
      cout << endl;
    } else {
      cout << S[0];
      REP(i, K, N) cout << S[i];
      cout << endl;
    }
  }
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
