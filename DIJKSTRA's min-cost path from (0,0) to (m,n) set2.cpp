//  IMPORTANT!!!!!!!   This method includes only all movements from current cell except diagonal movements

#include <bits/stdc++.h>
#define MAX 50
using namespace std;

bool isValid(int row,int col,int r,int c){
    if(row>=0 && row<r && col>=0 && col<c){
        return true;
    }
    return false;
}
int rowMove[]={0,1,0,-1};
int colMove[]={1,0,-1,0};

int main() {
	long long t;
	cin>>t;
	while(t--){
	   int n;
	   cin>>n;
	   int mat[n][n];
	   int dist[n][n];
	   for(int i=0;i<n;i++){
	       for(int j=0;j<n;j++){
	           cin>>mat[i][j];
	           dist[i][j] = INT_MAX;
	       }
	   }
	   dist[0][0]=mat[0][0];
	   queue<pair<int,int>> q;
	   q.push({0,0});
	   while(!q.empty()){
	       pair<int,int> p = q.front();
	       int a1 = p.first;
	       int a2 = p.second;
	       q.pop();
	       for(int i=0;i<4;i++){
	           int row = a1 + rowMove[i];
	           int col = a2 + colMove[i];
	           if(isValid(row,col,n,n) && dist[row][col]>(dist[a1][a2] + mat[row][col])){
	               dist[row][col] = dist[a1][a2]+mat[row][col];
	               q.push({row,col});
	           }
	       }
	   }
	   cout<<dist[n-1][n-1]<<endl;
	   
	   
	}
	return 0;
}
