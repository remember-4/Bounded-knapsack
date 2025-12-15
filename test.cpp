#include <bits/stdc++.h>

using namespace std;

int main()
{
	srand(time(0));
	for (int T = 1; T <= 10000; T++)
	{
		FILE *fp = fopen("input.txt", "w");

		int N = rand() % 7 + 1;
		int V = rand() % 30 + 20;

		fprintf(fp, "%d %d\n", N, V);

		for (int i = 1; i <= N; i++)
		{
			int w = rand() % 7 + 1;
			int v = rand() % 10 + 1;
			int c = rand() % 5 + 1;
			fprintf(fp, "%d %d %d\n", w, v, c);
		}

		fclose(fp);

		system("knapsack1.exe < input.txt > out1.txt");

		system("knapsack4.exe < input.txt > out2.txt");

		int ans_std, ans_my;
		FILE *fs1 = fopen("out1.txt", "r");
		FILE *fs2 = fopen("out2.txt", "r");

		fscanf(fs1, "%d", &ans_std);
		fscanf(fs2, "%d", &ans_my);

		fclose(fs1);
		fclose(fs2);

		if (ans_std != ans_my)
		{
			printf("Mismatch on test %d!!!\n", T);
			printf("Input:\n");
			system("type input.txt");
			printf("\nStd = %d\n", ans_std);
			printf("My  = %d\n", ans_my);
			break;
		}

		printf("Test %d OK\n", T);
	}

	return 0;
}

