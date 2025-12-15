#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath> 
#include<cstring>

int N,V;
const int MAXV=1e5+5;
const int MAXN=1e3+5;
//N types of item, max volume of knapsack is V.
struct item{
	int w,v,c;
	//weight,value,count limit.
}arr[MAXN];

int dp[MAXN][MAXV];
//dp[i][v] means the maximum value placed in a knapsack with capacity of v for first i types of items.


int main(){
	memset(dp,0,sizeof(dp));
	
	scanf("%d%d",&N,&V);
	for(int i=1;i<=N;i++){
		scanf("%d%d%d",&arr[i].w,&arr[i].v,&arr[i].c);
	}
	
	//Optimize: ci should lower than V/wi.
	for(int i=1;i<=N;i++){
		arr[i].c=std::min(arr[i].c,V/arr[i].w);
	}
	
	for(int i=1;i<=N;i++){
		for(int j=0;j<=V;j++){
			dp[i][j]=dp[i-1][j];//don't choose i th item
		}
		
		for(int j=0;j<=V;j++){
			for(int k=1;k<=arr[i].c&&k*arr[i].w<=j;k++){
				dp[i][j]=std::max(dp[i][j],dp[i-1][j-k*arr[i].w]+k*arr[i].v);
			}
		}
	}
	printf("%d",dp[N][V]);
	return 0;
}

/*
n
wi vi ci
*/
