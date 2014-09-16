//
//  union.h
//  UAV
//
//  Created by Alexander Bladh on 2014-09-16.
//  Copyright (c) 2014 ab. All rights reserved.
//

#ifndef __UAV__union__
#define __UAV__union__
#include <iostream>
#include <vector>

class UnionFind
{
private:
    std::vector<int> p, rank, size;
    int NumSets;
    
public:
    
    UnionFind(int N)
    {   rank.assign(N,0); p.assign(N, 0); size.assign(N, 1);
        for(int i = 0; i < N; i++) p[i] = i;
        NumSets = N;
    }
    int FindSet(int i)
    {
        return (p[i] == i ? i : p[i] = FindSet(p[i]));
    }
    bool IsSameSet(int i, int j)
    {
        return FindSet(i) == FindSet(j);
    }
    void UnionSet(int i, int j)
    {
        if(!IsSameSet(i, j))
        {
            int x = FindSet(i); int y = FindSet(j);
            if(rank[x] > rank[y])
            {
                p[y] = x;
                size[x] += size[y];
            }
            else
            {
                p[x] = y;
                size[y] += size[x];
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
    
    int NumDisjointSets()
    {
        return NumSets;
    }
    
    int SizeOfSet(int i)
    {
        return size[FindSet(i)];
    }
    
    
};


#endif /* defined(__UAV__union__) */
