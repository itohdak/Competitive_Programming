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
    string S;
    cin >> S;
    set<char> ok, ng;
    int tmp = 0;
    char tmpc = S[0];
    rep(i, S.size()) {
      if(S[i] == tmpc) {
        tmp++;
      } else {
        if(tmp % 2 == 1) ok.insert(tmpc);
        else ng.insert(tmpc);
        tmpc = S[i];
        tmp = 1;
      }
    }
    if(tmp % 2 == 1) ok.insert(tmpc);
    else ng.insert(tmpc);

    for(char c: ok)
      cout << c;
    cout << endl;
  }
  return 0;
}

