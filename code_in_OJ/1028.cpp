#include <iostream>

using namespace std;

#define MAX 505
#define INF 999999999;
int graph[MAX][MAX];// 记录初始情况
int dist[MAX]; // 记录从起始点出发到其他点的最短路径
bool sptSet[MAX];// 记录是否以及访问过某一点

int min(int a, int b){
    return a < b ? a : b;
}

int minDistance(int n){ //找到最短距离，并返回其下标
    int min = INF;
    int min_index;
    for(int v = 1; v <= n; ++v){
        if(!sptSet[v] && dist[v] <= min){
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int main()
{
    int m;
    cin >> m;
    while(m){
        int n, e, s, t;
        cin >> n >> e >> s >> t;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <=n; ++j){
                if(i == j) graph[i][j] = 0;
                else graph[i][j] = INF;
            }
        }

        for(int i = 1; i <= e; ++i){
            int u, v, w;
            cin >> u >> v >> w;
            graph[u][v] = min(graph[u][v], w);// 有重复边只记录长度较短的那个
            graph[v][u] = min(graph[u][v], w);// 无向图记得对角线对称的地方也要记录
        }


        //dijkstra
        for(int i = 1; i <= n; ++i){
            dist[i] = INF;
            sptSet[i] = false;
        }

        dist[s] = 0;

        for(int count = 1; count < n; ++count){ // 重复n-1次

            int u = minDistance(n);

            sptSet[u] = true;

            for(int v = 1; v <= n; ++v){
                if(!sptSet[v] && graph[u][v] != 999999999 && graph[u][v] != 0 && dist[u] != 999999999
                   && dist[u] + graph[u][v] < dist[v]){// 符合上述条件，对dist[]进行更新
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
        if(dist[t] == 999999999) cout << -1 << endl;
        else cout << dist[t] << endl;

        m--;
    }

    return 0;
}