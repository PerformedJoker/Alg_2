#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


int pathMat[76][76];
int impossivel = 0;

int maxLen(int** mat, int N, int k, int linha, int coluna, int somatorio)
{
	int aux, caso1, caso2, caso3, maior;
	//int mat[N+1][N+1] = matriz;
	int i = linha;
	int j = coluna;
	int e, d, b, sum = somatorio;
	int kE, kD, kB;
	e = d = b = -10000000;

	kE = kD = kB = k;

	if(i == N && j == N) return sum;

	if(pathMat[i][j] > 1)
		return pathMat[i][j];

	if(pathMat[i][j - 1] != 1)
	{
		if(j > 1) //pode andar pra esquerda
		{
			if(mat[i][j - 1] >= 0)
				e = mat[i][j - 1];
			else if(k > 0)
			{
				e = mat[i][j - 1];
				kE--;
			}
		}
		else e = -1000000;
	}
	else e = -1000000;

	if(pathMat[i][j + 1] != 1)
	{
		if(j < N) //Pode andar pra direita
		{
			if(mat[i][j + 1] >= 0)
				d = mat[i][j + 1];
			else if(k > 0)
			{
				d = mat[i][j + 1];
				kD--;
			}
		}
		else d = -1000000;
	}
	else d = -100000;

	if(pathMat[i + 1][j] != 1)
	{
		if(i < N) //pode ir pra baixo
		{
			if(mat[i + 1][j] >= 0)
				b = mat[i + 1][j];
			else if(k > 0)
			{
				b = mat[i + 1][j];
				kB--;
			}//else b = -1000000;
		}
		else b = -1000000;
	}
	else b = -1000000;

	if(e == -1000000 && d == -1000000 && b == -1000000)
	{
		impossivel = 1;
		return 0;
	}

	if(e == d )
	{
		if(e >= -10000 & d >= -10000)
		{
			caso1 = maxLen(mat, N, k, i, j - 1, sum);
			caso2 = maxLen(mat, N, k, i, j + 1, sum);
			sum += max(caso1, caso2);
			return sum;
		}
	}
	if(e == b )
	{
		if(e >= -10000 & b >= -10000)
		{
			caso1 = maxLen(mat, N, k, i, j - 1, sum);
			caso2 = maxLen(mat, N, k, i + 1, j, sum);
			sum += max(caso1, caso2);
			return sum;
		}
	}

	if(d == b )
	{
		if(d >= -10000 & b >= -10000)
		{
			caso1 = maxLen(mat, N, k, i, j + 1, sum);
			caso2 = maxLen(mat, N, k, i + 1, j, sum);
			sum += max(caso1, caso2);
			return  sum;
		}
	}

	if(d == b == e )
	{
		if(d >= -10000 & b >= -10000 & e >= -10000)
		{
			caso1 = maxLen(mat, N, k, i, j + 1, sum); //Direita
			caso2 = maxLen(mat, N, k, i + 1, j, sum); //Baixo
			caso3 = maxLen(mat, N, k, i, j - 1, sum); //Esquerda
			return  sum = max(max(caso1, caso2), caso3);
		}
	}

	maior = max(max(e, d), b);

	if(maior == e)
	{
		pathMat[i][j] = sum;
		sum += mat[i][j - 1];
		j--;
		k = kE;
	}
	else if(maior == d)
	{
		pathMat[i][j] = sum;
		sum += mat[i][j + 1];
		j++;
		k = kD;
	}
	else
	{
		pathMat[i][j] = sum;
		sum += mat[i + 1][j];
		i++;
		k = kB;
	}

	return sum;
}




int main()
{
	int N, k, res, aux;
	scanf("%d %d", &N, &k);
	printf("Tamanho da matrix : %d por %d , com k igual a : %d\n", N, N, k);
	int matriz[N + 1][N + 1];
	//int maior, endA, endB;
	// for(int i = 1; i < N + 1; i++)
	// 	for(int j = 1; j < N + 1; j++)
	// 		matriz[i][j] = -1;

	for(int i = 1; i < N + 1; i++)
	{
		for(int j = 1; j < N + 1; j++)
		{
			scanf("%d", &aux);
			matriz[i][j] = aux;
			pathMat[i][j] = 0;
		}
	}

	int soma = matriz[1][1];
	res = maxLen(matriz, N, k, 1, 1, soma);


	if(impossivel < 1)
		cout << res << endl;
	else
		cout << "impossible" << endl;


	return 0;
}
