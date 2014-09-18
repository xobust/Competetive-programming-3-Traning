#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
#include <string>
#include <map>

bool rev (int i,int j) { return (i>j); }


#define size 200


bool adjmatrix[size][size];


std::vector<int> adjlist[size];

std::vector<std::pair<int,int>> edgelist;

using namespace std;

void AmtoAl()
{

	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			if(adjmatrix[i][j])
				adjlist[i].push_back(j);

}


void AmtoEl()
{
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			if(adjmatrix[i][j])
			{
				std::pair<int,int> p;
				p.first=i;
				p.second = j;

				edgelist.push_back(p);
			}
}


void AltoAm()
{


}




int main () {


	memset(adjmatrix,false,size*sizeof(bool));

	while(true)
	{
		int i,j;
		cin >> i >> j;
		std::pair<int,int> p;
		p.first=i;
		p.second = j;

		adjmatrix[i][j] = true;

		adjlist[i].push_back(j);

		edgelist.push_back(p);

	}


	return 0;

}
