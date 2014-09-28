#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

char a[2][100005];
int n;
int MOD = 1000000007;

int top_bigger(int k)
{
	long long ans = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[k][i] == '?' && a[1 - k][i] == '?')
			ans *= 55;
		else if (a[k][i] == '?')
			ans *= 10 - ((int) a[1 - k][i] - '0');
		else if (a[1 - k][i] == '?')
			ans *= (int) a[k][i] - '0' + 1;
		else 
		{
			if (a[k][i] < a[1 - k][i])
				return 0;
		}
		ans %= MOD;
	}
	return ans;
}

int num_equal()
{
	long long ans = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[0][i] == '?' && a[1][i] == '?')
			ans *= 10;
		else if (a[0][i] == '?' || a[1][i] == '?')
			ans *= 1;
		else if (a[0][i] != a[1][i])
			return 0;
		ans %= MOD;
	}
	return ans;

}

int main()
{
	cin >> n;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	long long ans = 1;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] == '?')
			{
				ans *= 10;
				ans %= MOD;
			}
	ans -= top_bigger(0) + top_bigger(1);
	ans += num_equal();
	ans += 2 * MOD;
	ans %= MOD;
	cout << ans << "\n";	

	return 0;
}
