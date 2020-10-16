#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

ll score[5000][5000];

int to_binary(string s){
  int n = s.size();
  int ret = 0;
  int j = 0;
  for(int i=n-1; i>=0; i--){
    ret += int(s[i] - '0') * pow(2,j);
    j++;
  }
  return ret;
}

int main(){
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> W(n);
  for(int i=0; i<n; i++)
    cin >> W[i];

  for(int i=0; i<pow(2,n); i++)
    for(int j=0; j<pow(2,n); j++)
      score[i][j] = 0LL;

  for(int i=0; i<n; i++){
    int ib = pow(2, i);
    for(int j=0; j<pow(n,2); j+=2*ib)
      for(int k=0; k<pow(n,2); k+=2*ib)
	for(int jj=j; jj<j+ib; jj++)
	  for(int kk=k; kk<k+ib; kk++){
	    score[jj][kk] += W[n-1-i];
	    score[jj+ib][kk+ib] += W[n-1-i];
	  }
  }

  // for(int i=0; i<(int)pow(2,n); i++){
  //   for(int j=0; j<(int)pow(2,n); j++){
  //     cout << score[i][j] << ' ';
  //   }
  //   cout << endl;
  // }

  vector<int> S(n);
  for(int i=0; i<m; i++){
    string sin;
    cin >> sin;
    S[i] = to_binary(sin);
  }

  for(int i=0; i<q; i++){
    string tin;
    int t;
    int k;
    cin >> tin >> k;
    t = to_binary(tin);
    int ans = 0;
    for(int j=0; j<m; j++)
      if(score[S[j]][t] <= k)
	ans++;
    cout << ans << endl;
  }

  return 0;
}

