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
		int c=arr[i].c;
		for(int k=1;k<=c;k<<=1){//1 2 4 8...
			int w=k*arr[i].w;
			int v=k*arr[i].v;
			
			for(int j=V;j>=w;j--){
				dp[j]=std::max(dp[j],dp[j-w]+v);
			}
			
			c-=k;
		}
		
		if(c>0){
			int w=c*arr[i].w;
			int v=c*arr[i].v;
			
			for(int j=V;j>=w;j--){
				dp[j]=std::max(dp[j],dp[j-w]+v);
			}
		}
	}
	printf("%d",dp[V]);
	return 0;
}

/*
n
wi vi ci
3 15
2 3 7
5 8 2
9 20 1

*/
