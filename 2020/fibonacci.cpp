#include<bits/stdc++.h>
#define endl '\n'
#define IO cin.tie(nullptr),ios::sync_with_stdio(false);
using namespace std;
struct matrix {
	unsigned long long mat[2][2];
	matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
		mat[0][0] = a, mat[0][1] = b, mat[1][0] = c, mat[1][1] = d;
	}
};
matrix mul(matrix a, matrix b)
{
	int m = 1e9 + 7;
	matrix ret;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				ret.mat[i][j] += a.mat[i][k] % m * b.mat[k][j] % m;
				ret.mat[i][j] %= m;
			}
		}
	}
	return ret;
}
matrix powm(matrix a, long long n)
{
	if (n == 1)
		return a;
	matrix ret = powm(a, n / 2);
	ret = mul(ret, ret);
	if (n & 1)
		return mul(ret, a);
	return ret;
}
int main()
{
	IO
	long long n;
	matrix base(1, 1, 1, 0);
	while (cin >> n)
	{
		if (n == 0)
		{
			cout << 0 << endl;
			continue;
		}
		matrix ans = powm(base, n);
		cout << ans.mat[1][0] << endl;
	}
}
