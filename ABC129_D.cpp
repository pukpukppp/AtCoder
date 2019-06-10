#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <map> // pair
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> data(H,vector<char>(W));
  vector<vector<int>> L(H,vector<int>(W,0));
  vector<vector<int>> R(H,vector<int>(W,0));
  vector<vector<int>> D(H,vector<int>(W,0));
  vector<vector<int>> U(H,vector<int>(W,0));
  int Lamp = 0;

  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      cin >> data[i][j];
    }
  }

  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      if(data[i][j] != '#'){
        //左方向に照らされるマスの数を数える
        if(j == 0){
          L[i][j] = 1;
        }else{
          L[i][j] = L[i][j - 1] + 1;
        }
        //上方向に照らされるマスの数を数える
        if(i == 0){
          U[i][j] = 1;
        }else{
          U[i][j] = U[i - 1][j] + 1;
        }
      }
    }
  }

  for(int i = H - 1;i >= 0;i--){
    for(int j = W - 1;j >= 0;j--){
      if(data[i][j] != '#'){
        //右方向に照らされるマスの数を数える
        if(j == W - 1){
          R[i][j] = 1;
        }else{
          R[i][j] = R[i][j + 1] + 1;
        }
        //上方向に照らされるマスの数を数える
        if(i == H - 1){
          D[i][j] = 1;
        }else{
          D[i][j] = D[i + 1][j] + 1;
        }
      }
    }
  }

  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      Lamp = max(Lamp,L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3);
    }
  }

  cout << Lamp << endl;
}
