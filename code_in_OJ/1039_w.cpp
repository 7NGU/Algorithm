//邻接矩阵实现
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 301;
vector<int> graph[maxn];//定义存储图的二维数组 
int indegree[maxn];//存储矩阵入度的矩阵 
vector<int> res;//存储顶点结果 
 
int main(){
    int t, n, m, x, y;//t组测试数据，n个顶点，m条边，x->y表示一条边 
    queue<int> q;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i <= n; i++){//初始化入度矩阵，等价于fill(indegree, indegree+n, 0); 
        	indegree[i] = 0;
		}
		for(int i = 1; i <= n; i++){
		        graph[i].clear();//把size设置成0，capacity不变。 
		    }
        for(int i = 1; i <= m; i++){
            cin >> x >> y;
            graph[x].push_back(y);//表示顶点x->y 
            indegree[y]++;//y的入度加1 
        }
        res.clear();
        int count = 0;//用来记录输出顶点的个数 
        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){//当队列非空时 
            int cur = q.front();//取下当前队列的对头元素 
            res.push_back(cur);//放入结果矩阵 
            q.pop();//弹出cur顶点 
            count++;
            //graph[cur].size()表示以cur为起点边的个数 
            for(int i = 0; i < graph[cur].size(); i++){//更新与顶点cur相关的顶点的入度,
                y = graph[cur][i];//找出以cur为开始顶点指向的顶点 
                indegree[y]--;//由于顶点cur弹出，顶点y入度减1 
                if(indegree[y] == 0){
                    q.push(y);
                }
            }
        }
        if(count != n){//图的顶点没有完全输出，则此图不存在拓扑序列输出0 
            cout << 0 << endl;
        }
        else{
            for(int i = 0; i < count; i++){
                cout << res[i] << " ";
            }
            cout << endl;
        }
    }
}