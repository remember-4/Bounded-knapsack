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
int q[MAXV],val[MAXV];


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
		for(int mod=0;mod<arr[i].w;mod++){
			memset(q,0,sizeof(q));
			memset(val,0,sizeof(val));
			
			int head=0,tail=0;
			
			for(int j=mod,k=0;j<=V;j+=arr[i].w,k++){
				int curVal=dp[j]-k*arr[i].v;
				while(head<tail&&k-val[head]>arr[i].c)
					head++;
				while(head<tail&&q[tail-1]<=curVal)
					tail--;
				
				q[tail]=curVal;
				val[tail]=k;
				tail++;
				
				dp[j]=q[head]+k*arr[i].v;
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
