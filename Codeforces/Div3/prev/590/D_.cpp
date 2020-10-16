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
  string S;
  cin >> S;
  unordered_map<char, set<int> > mp;
  rep(i, 26) mp['a'+i] = set<int>();
  rep(i, S.size()) mp[S[i]].insert(i);
  int Q;
  cin >> Q;
  rep(q, Q) {
    int i;
    cin >> i;
    if(i == 1) {
      int j;
      char c;
      cin >> j >> c;
      j--;
      mp[S[j]].erase(j);
      S[j] = c;
      mp[c].insert(j);
    } else {
      int l, r;
      cin >> l >> r;
      l--; r--;
      int cnt = 0;
      for(auto &m: mp) {
        if(m.second.size() > 0) {
          auto itr = m.second.lower_bound(l);
          if(itr == m.second.end()) continue;
          int L = *itr;
          if(l <= L && L <= r) cnt++;
        }
      }
      cout << cnt << endl;
    }
  }
  return 0;
}
