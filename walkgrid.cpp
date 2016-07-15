#include <iostream>
#include <algorithm>

using namespace std;

int maxLen(int &N, int &k)
{
	int aux;
	int mat[N + 1][N + 1];
	int pathMat[N + 1][N + 1];
	int maior;
	for(int i = 1; i <= N + 1; i++)
	{
		for(int j = 1; j <= N + 1; j++)
		{
			cin >> aux;
			mat[i][j] = aux;
			pathMat[i][j] = 0;
		}
	}

	int e, d, b, sum=0;
	for(int i = 1; i <= N + 1;)
	{
		for(int j = 1; j <= N + 1;)
		{
			if(j == 1 && i == 1) //start
			{
				pathMat[i][j] = 1;
				d = mat[i][j + 1];
				b = mat[i + 1][j];
				maior = max(d, b);
			}
			if(j > 1)
			{//pode andar pra esquerda
				e = mat[i][j-1];
			}
			if(j < N+1){
				d = mat[i][j+1];
			}
			if(i < N+1){
				b = mat[i+1][j];
			}
			maior = max(e, d);
			maior = max(maior, b);
			
	}
}


}

int main()
{

	int n, k;
	scanf("%d %d", &n, &k);
	cout << maxLen(n) << endl;

	return 0;
}
