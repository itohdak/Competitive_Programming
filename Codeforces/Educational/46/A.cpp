#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n;
  cin >> n;
  vector<string> A(n), B(n);
  vector<int> Na1(3, 0), Na2(2, 0), Na3(2, 0), Na4(2, 0);
  vector<int> Nb1(3, 0), Nb2(2, 0), Nb3(2, 0), Nb4(2, 0);
  for(int i=0; i<n; i++){
    cin >> A[i];
    if(A[i].size() == 1){
      if(A[i][0] == 'S')
	Na1[0]++;
      else if(A[i][0] == 'L')
	Na1[1]++;
      else if(A[i][0] == 'M')
	Na1[2]++;
    } else if (A[i].size() == 2){
      if(A[i][1] == 'S')
	Na2[0]++;
      else if(A[i][1] == 'L')
	Na2[1]++;
    } else if (A[i].size() == 3){
      if(A[i][2] == 'S')
	Na3[0]++;
      else if(A[i][2] == 'L')
	Na3[1]++;
    } else if (A[i].size() == 4){
      if(A[i][3] == 'S')
	Na4[0]++;
      else if(A[i][3] == 'L')
	Na4[1]++;
    }
  }
  for(int i=0; i<n; i++){
    cin >> B[i];
    if(B[i].size() == 1){
      if(B[i][0] == 'S')
	Nb1[0]++;
      else if(B[i][0] == 'L')
	Nb1[1]++;
      else if(B[i][0] == 'M')
	Nb1[2]++;
    } else if (B[i].size() == 2){
      if(B[i][1] == 'S')
	Nb2[0]++;
      else if(B[i][1] == 'L')
	Nb2[1]++;
    } else if (B[i].size() == 3){
      if(B[i][2] == 'S')
	Nb3[0]++;
      else if(B[i][2] == 'L')
	Nb3[1]++;
    } else if (B[i].size() == 4){
      if(B[i][3] == 'S')
	Nb4[0]++;
      else if(B[i][3] == 'L')
	Nb4[1]++;
    }
  }
  int tmp
    = min(Na1[0], Nb1[0]) + min(Na1[1], Nb1[1]) + min(Na1[2], Nb1[2])
    + min(Na2[0], Nb2[0]) + min(Na2[1], Nb2[1])
    + min(Na3[0], Nb3[0]) + min(Na3[1], Nb3[1])
    + min(Na4[0], Nb4[0]) + min(Na4[1], Nb4[1]);
  cout << n - tmp << endl;
  return 0;
}

