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

vector<string> D;
vector<string> S;
int N;
string ans;
char num[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
string cmp(string s1, string s2) {
  if(s1.size() == s2.size()) {
    if(s1[0] > s2[0]) return s1;
    else return s2;
  } else if(s1.size() > s2.size()) {
    return s1;
  } else {
    return s2;
  }
}
int main() {
  int K;
  cin >> N >> K;
  string d[] = {"1110111", "0010010", "1011101", "1011011", "0111010",
		"1101011", "1101111", "1010010", "1111111", "1111011"};
  D = vector<string>(10);
  rep(i, 10) D[i] = d[i];
  S = vector<string>(N);
  rep(i, N) cin >> S[i];

  vector<map<int, int> > C(N);
  int mx = 0;
  rep(i, N) {
    int tmp = 0;
    rep(j, 10) {
      bool ok = true;
      int cnt = 0;
      rep(k, 7) {
	if(D[j][k]=='1') {
	  if(S[i][k]=='0') cnt++;
	} else {
	  if(S[i][k]=='1') ok = false;
	}
      }
      if(ok) {
	if(!C[i].count(cnt)) C[i][cnt] = j;
	else C[i][cnt] = max(j, C[i][cnt]);
	// C[i].insert(make_pair(j, cnt));
	tmp = max(cnt, tmp);
      }
    }
    mx += tmp;
  }
  // cout << C << endl;

  if(mx < K) {
    cout << -1 << endl;
    return 0;
  }

  vector<vector<string>> dp(2, vector<string>(K+1, ""));
  rrep(i, N) {
    int ii = 1-i%2;
    rep(j, K+1) dp[1-ii][j] = "";
    rep(j, K+1) {
      for(auto k: C[i]) {
	int cost = k.first;
	int id = k.second;
	if(cost <= j && ((i==N-1 && j==K) || dp[ii][j]!="")) {
	  // dp[1-ii][j-cost] = max(dp[ii][j]+num[id], dp[1-ii][j-cost]);
	  dp[1-ii][j-cost] = cmp(num[id]+dp[ii][j], dp[1-ii][j-cost]);
	}
      }
    }
  }
  // cout << dp << endl;
  if(dp[0][0] == "") cout << -1 << endl;
  else cout << dp[0][0] << endl;
  return 0;
}
