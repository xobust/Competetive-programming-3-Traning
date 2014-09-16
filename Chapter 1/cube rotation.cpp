#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

bool rev (int i,int j) { return (i>j); }



using namespace std;


int main () {

	char cube[300][300];
	char sub[300][300];
	
	int N,n;

	while(cin >> N >> n)
	{

		if(N == 0)
			break;

		for(int i = 0; i<N; i++)
		{
		for(int j = 0; j<N; j++)
		{
			char c;
			cin >> c;
			cube[i][j] = c;
		}
		}


		for(int i = 0; i<n; i++)
		{
		for(int j = 0; j<n; j++)
		{
			char c;
			cin >> c;
			sub[i][j] = c;
		}
		}


		int rota=0, rotb = 0, rotc = 0, rotd = 0;

		for(int i = 0; i<=(N-n); i++)
		{
		for(int j = 0; j<=(N-n); j++)
		{
			bool k = true;
			for(int a = 0; a<n; a++)
			{
			for(int b = 0; b<n; b++)
			{
				if(cube[i+a][j+b] != sub[a][b])
				{
					k = false;
					a=n;
					break;
				}

			}
			}
			
			if(k)
				rota++;
			

		}
		}

		for(int i = 0; i<=(N-n); i++)
		{
		for(int j = 0; j<=(N-n); j++)
		{
			bool k = true;
			for(int a = 0; a< n; a++)
			{
			for(int b = 0; b< n; b++)
			{

				if(cube[i+a][j+b] != sub[n-b-1][a])
				{
					k = false;
					a=n;
					break;
				}


			}
			}
			
			if(k)
				rotb++;

		}
		}

		for(int i = 0; i<=(N-n); i++)
		{
		for(int j = 0; j<=(N-n); j++)
		{
			bool k = true;
			for(int a = 0; a< n; a++)
			{
			for(int b = 0; b< n; b++)
			{

				if(cube[i+a][j+b] != sub[a][n-b-1])
				{
					k = false;
					a=n;
					break;
				}


			}
			}
			
			if(k)
				rotc++;

		}
		}

		for(int i = 0; i<=(N-n); i++)
		{
		for(int j = 0; j<=(N-n); j++)
		{
			bool k = true;
			for(int a = 0; a< n; a++)
			{
			for(int b = 0; b< n; b++)
			{

				if(cube[i+a][j+b] != sub[b][n-a-1])
				{
					k = false;
					a=n;
					break;
				}


			}
			}
			
			if(k)
				rotd++;

		}
		}

		for(int a = 0; a< n; a++)
			{
			for(int b = 0; b< n; b++)
			{

				cout << sub[a][n-b-1];


			}
			cout <<"\n";
			}
	
		

		cout << rota << " " <<rotb << " " << rotc << " " << rotd << "\n";



	}
	
	return 0;

}
