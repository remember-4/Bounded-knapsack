#include <bits/stdc++.h>
using namespace std;

struct Item {
    int w, v, c;
};

static int dp[1000005];
static int q[1000005], val[1000005];
static Item arr[100005];

int N, V;

void solve()
{
    memset(dp, 0, (V + 1) * sizeof(int));

    for (int i = 1; i <= N; i++)
        arr[i].c = min(arr[i].c, V / arr[i].w);

    for (int i = 1; i <= N; i++)
    {
        int w = arr[i].w;
        int v = arr[i].v;
        int c = arr[i].c;

        for (int mod = 0; mod < w; mod++)
        {
            int head = 0, tail = 0;

            for (int j = mod, k = 0; j <= V; j += w, k++)
            {
                int curVal = dp[j] - k * v;

                while (head < tail && k - val[head] > c)
                    head++;

                while (head < tail && q[tail - 1] <= curVal)
                    tail--;

                q[tail] = curVal;
                val[tail] = k;
                tail++;

                dp[j] = q[head] + k * v;
            }
        }
    }
}
int main()
{
    srand(0);
    freopen("time.out","w",stdout);
    printf("V,N,time_ms\n");

    for (V = 5000; V <= 200000; V +=5000 )
    {
        N = V / 200;

        for (int i = 1; i <= N; i++)
        {
            arr[i].w = rand() % (V / 10) + 1;
            arr[i].v = rand() % 100 + 1;
            arr[i].c = rand() % (V / arr[i].w) + 1;
        }

        clock_t start = clock();
        solve();
        clock_t end = clock();

        double time_ms = 1000.0 * (end - start) / CLOCKS_PER_SEC;
        printf("%d,%d,%.3f\n", V, N, time_ms);
	}
}

