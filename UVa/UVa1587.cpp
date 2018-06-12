//
// Created by Hu on 2018/6/12.
//

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
struct Box
{
    int h, w;
    bool operator < (const Box& rha) const{
        if(h == rha.h) return w < rha.w;
        return h < rha.h;
    }
}boxes[10];

bool ok()
{
    if(boxes[0].h != boxes[1].h || boxes[0].w != boxes[1].w) return false;
    if(boxes[2].h != boxes[3].h || boxes[2].w != boxes[3].w) return false;
    if(boxes[4].h != boxes[5].h || boxes[4].w != boxes[5].w) return false;
    if(boxes[1].h != boxes[2].h) return false;
    if(boxes[1].w != boxes[4].h) return false;
    if(boxes[3].w != boxes[4].w) return false;
    return true;

}
int main()
{
    while(scanf("%d%d", &boxes[0].h, &boxes[0].w) != EOF)
    {
        if(boxes[0].h > boxes[0].w) swap(boxes[0].h, boxes[0].w);
        for(int i = 1; i < 6; ++i)
        {
            scanf("%d%d", &boxes[i].h, &boxes[i].w);
            if(boxes[i].h > boxes[i].w) swap(boxes[i].h, boxes[i].w);
        }
        sort(boxes, boxes+6);
        if(ok()) puts("POSSIBLE");
        else puts("IMPOSSIBLE");
    }
    return 0;
}