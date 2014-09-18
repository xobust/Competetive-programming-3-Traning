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


#define vi std::vector<int>


//Segmented Tree
class SegmentTree
{
private:
	vi st, A;
	int n;
	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }

	/*
	O(n) build the tree
	*/
	void build(int p, int L, int R)
	{
		if(L == R)
			st[p] = L; 
		else
		{
			build(left(p), L  , (L+R)/2);
			build(right(p), (L + R) / 2 + 1,R);
			int p1 = st[left(p)], p2  = st[right(p)];
			st[p] = (A[p1] <= A[p2]) ? p1 : p2;
		}
	}

	int rmq(int p, int L, int R, int i, int j)		// O(log n)
	{
		if(i > R || j < L) return -1; // boundry check
		if(L >= i && R <= j) return st[p];

		//compare min position in the left and right part of interval
		int p1 = rmq(left(p), L, (L+R) / 2, i ,j);
		int p2 = rmq(right(p), (L+R) / 2 +1, R, I,J);

		if(p1 == -1) return p2;
		if(p2 == -1) return p1;

		return (A[p1] <= A[p2]) ? p1 : p2;

	}

public:
	SegmentTree(const vi &_A) {
		A = _A; n = (int)A.size();
		st.assign(4* n, 0);
		build(1, 0, n-1);

	}

	
	int rmq(int i, int j) { return rmq(1,0, n-1, i, j); }
	

};