#define ll long long
vector<ll> coins_now;
ll n;
ll dp[100005];

ll func(ll koto)
{
	// cout<<"koto: "<<koto<<endl;
	if (koto == n)
	{
		return 0;
	}
	else if (koto > n)
	{
		return 1e9;
	}
	if (dp[koto] != -1)
	{
		return dp[koto];
	}
	ll koita = 1e18;
	for (int i = 0; i < coins_now.size(); i++)
	{
		// cout<<"paisa: "<<coins_now[i]<<endl;
		koita = min(koita, 1 + func(koto + coins_now[i]));
	}
	// cout<<"koita: "<<koita<<endl;
	return dp[koto] = koita;
}

class Solution
{
public:
	int coinChange(vector<int> &coins, int amount)
	{
		for (int i = 0; i < coins.size(); i++)
		{
			coins_now.push_back(coins[i]);
		}
		n = amount;
		for (int i = 0; i <= n + 5; i++)
		{
			dp[i] = -1;
		}
		ll now = func(0);
		coins_now.clear();
		if (now < 0 || now >= 1e9)
			return -1;
		return now;
	}
};