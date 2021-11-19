#include <iostream>
#include <algorithm>
using namespace std;

struct edge{
    int x;
    int y;
    int len;
};
edge p[20005];
int g[505];
int node[505];

bool cmp(edge a, edge b){
    return a.len  < b.len;
}

int ufind(int x){
    if(g[x] == x){
        return x;
    }
    return g[x] = ufind(g[x]);
}



int main()
{
    int m;
    cin >> m;
    while(m > 0){
        int n, e;
        cin >> n >> e;
        for(int i = 1; i <= e; ++i){
            cin >> p[i].x >> p[i].y >> p[i].len;
        }
        /*
         * 首先对len进行从小到大的排序
         * 开始将边加入集合，判断加入的边是否是同一个集合，若是则不加入，不是就加入（Kruskal Algorithm）
         * 便利完成后判断图中存在的集合是不是只有一个，若是说明最小生成树构建成功，若不是说明构建失败，返回-1
         * ps:对节点是否属于同一个集合的判断可以用并查集进行优化
         */
        // sort according to length of edge
        sort(p+1, p+1+e, cmp);

        for(int i = 1; i <= n; ++i){
            g[i] = i;
            node[i] = 0;
        }

        int tot = 0, dis = 0;
//        for(int i = 1; i <= n; ++i){
//            cout << node[i] << " ";
//        }
//        cout << endl;

        for(int i = 1; i <= e && tot < n - 1; ++i){
            int gx = ufind(p[i].x);
            int gy = ufind(p[i].y);
            if(gx != gy){
                g[gx] = g[gy];
                tot++;
                dis += p[i].len;
                node[p[i].x] = 1;
                node[p[i].y] = 1;
            }
        }
        for(int i = 1; i <= n; ++i){
            if(node[i] == 0){
                dis = -1;
                break;
            }
        }
        cout << dis << endl;


        m--;
    }
    return 0;
}
