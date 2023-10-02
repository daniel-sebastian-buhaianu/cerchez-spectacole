#include <fstream>

#define NMAX 1002

using namespace std;

ifstream fin("spectacole.in");
ofstream fout("spectacole.out");

struct Spectacol
{
	int ts, tf, nr;
};

int main()
{
	int n, i, hs, ms, hf, mf, schimb, ultim;
	Spectacol s[NMAX], aux;

	fin >> n;

	for (i = 1; i <= n; i++)
	{
		fin >> hs >> ms >> hf >> mf;

		s[i].ts = hs*60 + ms;
		s[i].tf = hf*60 + mf;
		s[i].nr = i;
	}

	fin.close();

	// ordonez spectacolele crescator dupa timpul final
	do
	{
		schimb = 0;

		for (i = 1; i < n; i++)
		{
			if (s[i].tf > s[i+1].tf)
			{
				aux = s[i];
				s[i] = s[i+1];
				s[i+1] = aux;

				schimb = 1;
			}
		}
	}
	while (schimb);

	fout << s[1].nr;

	ultim = 1;

	for (i = 2; i <= n; i++)
	{
		if (s[i].ts >= s[ultim].tf)
		{
			fout << ' ' << s[i].nr;

			ultim = i;
		}
	}
	
	fout << '\n';

	fout.close();

	return 0;
}
