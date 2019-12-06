#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
	cin>>t;
	while(t--){
	    int r,c;
	    cin>>r>>c;
	    int mat[r][c];
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            cin>>mat[i][j];
	        }
	    }
	    int dp[r][c];
	    dp[0][0] = mat[0][0];
	    for(int i=1;i<r;i++){
	        dp[i][0] = mat[i][0] + dp[i-1][0];
	    }
	    for(int i=1;i<c;i++){
	        dp[0][i] = mat[0][i] + dp[0][i-1];
	    }
	  
	    for(int i=1;i<r;i++){
	        for(int j=1;j<c;j++){
	            dp[i][j] = min(dp[i-1][j] , dp[i][j-1]) + mat[i][j];
	        }
	    }
	    cout<<dp[r-1][c-1];
	}
	return 0;
}
