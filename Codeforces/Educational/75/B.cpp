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
  int Q;
  cin >> Q;
  rep(q, Q) {
    int N;
    cin >> N;
    vector<string> S(N);
    vector<int> sizes(N);
    int zeros = 0, ones = 0;
    int Sodd = 0;
    rep(i, N) {
      cin >> S[i];
      sizes[i] = S[i].size();
      if(sizes[i] % 2 == 1) Sodd++;
      rep(j, sizes[i]) {
        if(S[i][j] == '0') zeros++;
        else ones++;
      }
    }
    if(Sodd % 2 == 0) {
      if(zeros % 2 == 1 && Sodd == 0) cout << N-1 << endl;
      else cout << N << endl;
    } else {
      cout << N << endl;
    }
  }
  return 0;
}

