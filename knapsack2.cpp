#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath> 
#include<cstring>

int N,V;
const int MAXV=1e6+5;
const int MAXN=1e4+5;
//N types of item, max volume of knapsack is V.
struct item{
	int w,v,c;
	//weight,value,count limit.
}arr[MAXN];

int dp[MAXV];
//dp[v] means the maximum value placed in a knapsack with capacity of v.


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
		for(int k=1;k<=arr[i].c;k++){
			for(int j=V;j>=arr[i].w;j--){
				dp[j]=std::max(dp[j],dp[j-arr[i].w]+arr[i].v);
			}
		}
	}
	printf("%d",dp[V]);
	return 0;
}

/*
n
wi vi ci
*/
