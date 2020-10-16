#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct pos{
  int x;
  int y;
  pos(int i, int j) : x(i), y(j)
  {}
  pos() : x(0), y(0)
  {}
};

int main(){
  int n, k;
  cin >> n >> k;
  vector< vector<int> > A(4, vector<int>(n)); // input
  vector< vector<pos> > P(2, vector<pos>(n)); // position
  pos space;
  for(int i=0; i<4; i++){
    for(int j=0; j<n; j++){
      cin >> A[i][j];
      if((i == 0 || i == 3)){
	if(A[i][j] != 0)
	  P[0][A[i][j]-1] = pos(i, j);
      } else {
	if(A[i][j] == 0)
	  space = pos(i, j);
	P[1][A[i][j]-1] = pos(i, j);
      }
    }
  }

  vector< vector<int> > ans(3, vector<int>(4*n*n, 0));
  int sum = 0;

  for(int i=0; i<k; i++)
    cout << P[0][i].x << P[0][i].y << ' ' << P[1][i].x << P[1][i].y << endl;

  for(int i=0; i<n; i++){
    if(A[0][i] == A[1][i]){
      ans[0][sum] = A[0][i];
      ans[1][sum] = 0;
      ans[2][sum] = i;
      P[1][A[2][i]].x = P[0][A[2][i]].x;
      P[1][A[2][i]].y = P[0][A[2][i]].y;
      sum++;
    }
    if(A[2][i] == A[3][i]){
      ans[0][sum] = A[2][i];
      ans[1][sum] = 3;
      ans[2][sum] = i;
      P[1][A[2][i]].x = P[0][A[2][i]].x;
      P[1][A[2][i]].y = P[0][A[2][i]].y;
      sum++;
    }
  }

  for(int i=0; i<k; i++)
    cout << P[0][i].x << P[0][i].y << ' ' << P[1][i].x << P[1][i].y << endl;

  if(2 * n <= k - sum){
    cout << -1 << endl;
  } else {
    for(int i=0; i<k; i++){
      if(!(P[0][i].x == P[1][i].x && P[0][i].y == P[1][i].y)){
	// how many time to rotate
	int t = 0;
	if(P[0][i].x == 0){
	  if(P[1][i].x == 1){
	    if(P[0][i].y < P[1][i].y)
	      t = 2 * n + P[1][i].y - P[0][i].y;
	    else
	      t = P[0][i].y - P[1][i].y;
	  } else {
	    t = P[1][i].y + P[0][i].y + 1;
	  }
	} else {
	  if(P[1][i].x == 1){
	    t = (n - 1 - P[0][i].y) + (n - 1 - P[1][i].y) + 1;
	  } else {
	    if(P[0][i].y <= P[1][i].y)
	      t = P[0][i].y - P[1][i].y;
	    else
	      t = 2 * n + P[1][i].y - P[0][i].y;
	  }
	}

	// rotate t times
	for(int j=0; j<t-1; j++){
	  for(int k=0; k<2*n; k++){
	    // cout << space.x << ' ' << space.y << endl;
	    pos next = space;
	    if(space.x == 1){
	      if(space.y == 0){
		next.y = 0; next.x = 2;
	      } else {
		next.y = space.y - 1;
	      }
	    } else if(space.x == 2){
	      if(space.y == n-1){
		next.y = n-1; next.x = 1;
	      } else {
		next.y = space.y + 1;
	      }
	    } else {
	      cout << "something wrong" << endl;
	      exit(0);
	    }
	    if(A[next.x][next.y] != 0){
	      ans[0][sum] = A[next.x][next.y];
	      ans[1][sum] = space.x;
	      ans[2][sum] = space.y;
	      A[space.x][space.y] = A[next.x][next.y];
	      A[next.x][next.y] = 0;
	      P[1][A[next.x][next.y]-1] = space;
	      sum++;
	    } else {
	      A[space.x][space.y] = 0;
	    }
	    space = next;
	  }
	}
	// place in the lot
	ans[0][sum] = i+1;
	ans[1][sum] = P[0][i].x;
	ans[2][sum] = P[0][i].y;
	if(P[0][i].x == 0)
	  A[1][P[0][i].y] = 0;
	else if(P[0][i].x == 3)
	  A[2][P[0][i].y] = 0;
	sum++;
      }
    }
    cout << sum << endl;
    for(int i=0; i<sum; i++)
      cout << ans[0][i] << ' ' << ans[1][i]+1 << ' ' << ans[2][i]+1 << endl;
  }
  return 0;
}
