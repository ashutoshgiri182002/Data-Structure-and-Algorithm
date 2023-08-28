#include <bits/stdc++.h> 
int maxSumRectangle(vector<vector<int>>& arr, int n, int m){

	vector<vector<int>>ps(n,vector<int>(m+1,0));
	//create the prefix sum array 
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			ps[i][j+1] = ps[i][j] + arr[i][j];
		}
	}

	//Main Logic of the code
	int ans = INT_MIN;
	
	for(int i = 0;i<m;i++){
		for(int j = i+1;j<m+1;j++){
			int sum = 0;
			for(int k = 0;k<n;k++){
				sum += ps[k][j]-ps[k][i];
				ans = max(ans,sum);
				if(sum<0)sum = 0;
			}
		}
	}
	
	return ans;
}
