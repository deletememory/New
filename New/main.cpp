#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int px[3] = { 1,-1,0 }, mx[3] = { 1,1,2 };
int S, T, N, np;
bool used[1000500];
struct Poi
{
	int pos, step;
	Poi(int _pos = 0, int _step = 0) :pos(_pos), step(_step) {}
}p;
int main()
{
	cin >> N;
	while (N--)
	{
		cin >> S >> T;
		memset(used, 0, sizeof(used));
		queue<Poi>q;
		q.push(Poi(S, 1));
		used[S] = true;
		while (!q.empty())
		{
			p = q.front();
			q.pop();
			if ((p.pos % 2) == 0)
			{
				np = p.pos / 2;
				if (np > 0 && np < 1000000 && !used[np])
				{
					used[np] = true;
					if (np == T)
					{
						cout << 2 * p.step << endl;
						break;
					}
					q.push(Poi(np, p.step + 1));
				}
			}
			for (int i = 0;i < 3;++i)
			{
				np = p.pos*mx[i] + px[i];
				if (np > 0 && np < 1000000 && !used[np])
				{
					used[np] = true;
					if (np == T)
					{
						cout << 2 * p.step << endl;
						while (!q.empty())
							q.pop();
						break;
					}
					q.push(Poi(np, p.step + 1));
				}
			}
		}
	}
	return 0;
}