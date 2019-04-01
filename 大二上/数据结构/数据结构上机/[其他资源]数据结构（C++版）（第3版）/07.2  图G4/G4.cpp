//《数据结构（C++版）（第3版）》 作者：叶核亚
//7.2.2   图的邻接表表示和实现
//【例7.1】图的存储及操作。
//带权有向图G4的构造、插入及删除操作。

#include "MatrixGraph.h"
//#include "AdjListGraph.h"

int main()
{
    char vertices[]="ABCDE";                               //带权有向图G4的顶点集合
    Triple edges[]={Triple(0,1,10), Triple(0,3,30), Triple(0,4,99),
                     Triple(1,2,50), Triple(1,3,40), 
                     Triple(2,4,10), 
                     Triple(3,2,20), Triple(3,4,60)};    //G4的出边集合
    MatrixGraph<char> graph(vertices, 5, edges, 8);
//    AdjListGraph<char> graph(vertices, 5, edges, 8);
    cout<<"带权有向图G4，"<<graph<<endl;
/*
    cout<<"深度优先遍历非连通图，有向图G2："<<endl;
    for (int i=0; i<graph.count(); i++)
        graph.DFSTraverse(i);

    cout<<"广度优先遍历非连通图，有向图G2："<<endl;
    for (int i=0; i<graph.count(); i++)
        graph.BFSTraverse(i);
    
    cout<<"\nDijkstra算法，单源最短路径\n";
    for (int i=0; i<graph.vertexCount(); i++)              //每对顶点之间的最短路径
        graph.shortestPath(i);                             //顶点vi的单源最短路径，Dijkstra算法
    cout<<endl;
*/
    cout<<"Floyd算法，每对顶点间的最短路径\n";
    graph.shortestPath();                                  //最短路径，Floyd算法

    //习题7
 /*   cout<<"有"<<graph.edgeCount()<<"条边，";
    int i=3;
    char vertice = graph.get(i);
    cout<<"顶点"<<vertice<<"的入度为"<<graph.indegree(i)<<"，出度为"<<graph.outdegree(i)<<endl;*/

    system("pause");
    return 0;
}

/*
程序运行结果如下：
带权有向图G4，顶点集合：(A, B, C, D, E)
邻接矩阵：
     0    10    ∞    30    99
    ∞     0    50    40    ∞
    ∞    ∞     0    ∞    10
    ∞    ∞    20     0    60
    ∞    ∞    ∞    ∞     0
邻接表：
0 -> ((0,1,10), (0,3,30), (0,4,99))
1 -> ((1,2,50), (1,3,40))
2 -> ((2,4,10))
3 -> ((3,2,20), (3,4,60))
4 -> ()

深度优先遍历非连通图：
{ A B C E D } 
{ B C E D } { A } 
{ C E } { D } { A B } 
{ D C E } { A B } 
{ E } { A B C D } 
广度优先遍历非连通图：
{ A B D E C } 
{ B C D E } { A } 
{ C E } { D } { A B } 
{ D C E } { A B } 
{ E } { A B D C } 

Dijkstra算法，单源最短路径
(A,B)10	    (A,D,C)50   (A,D)30	    (A,D,C,E)60	
(B,A)∞	    (B,C)50	    (B,D)40	    (B,C,E)60	
(C,A)∞	    (C,B)∞	    (C,D)∞	    (C,E)10	
(D,A)∞	    (D,B)∞	    (D,C)20	    (D,C,E)30	
(E,A)∞	    (E,B)∞	    (E,C)∞	    (E,D)∞	

dist矩阵（5×5）：
     0    10  9999    30    99
  9999     0    50    40  9999
  9999  9999     0  9999    10
  9999  9999    20     0    60
  9999  9999  9999  9999     0
path矩阵（5×5）：
    -1     0    -1     0     0
    -1    -1     1     1    -1
    -1    -1    -1    -1     2
    -1    -1     3    -1     3
    -1    -1    -1    -1    -1

用顶点A作为其他路径的经过顶点，dist矩阵（5×5）：
     0    10  9999    30    99
  9999     0    50    40  9999
  9999  9999     0  9999    10
  9999  9999    20     0    60
  9999  9999  9999  9999     0
path矩阵（5×5）：
    -1     0    -1     0     0
    -1    -1     1     1    -1
    -1    -1    -1    -1     2
    -1    -1     3    -1     3
    -1    -1    -1    -1    -1

用顶点B作为其他路径的经过顶点，dist矩阵（5×5）：
     0    10    60    30    99
  9999     0    50    40  9999
  9999  9999     0  9999    10
  9999  9999    20     0    60
  9999  9999  9999  9999     0
path矩阵（5×5）：
    -1     0     1     0     0
    -1    -1     1     1    -1
    -1    -1    -1    -1     2
    -1    -1     3    -1     3
    -1    -1    -1    -1    -1

用顶点C作为其他路径的经过顶点，dist矩阵（5×5）：
     0    10    60    30    70
  9999     0    50    40    60
  9999  9999     0  9999    10
  9999  9999    20     0    30
  9999  9999  9999  9999     0
path矩阵（5×5）：
    -1     0     1     0     2
    -1    -1     1     1     2
    -1    -1    -1    -1     2
    -1    -1     3    -1     2
    -1    -1    -1    -1    -1

用顶点D作为其他路径的经过顶点，dist矩阵（5×5）：
     0    10    50    30    60
  9999     0    50    40    60
  9999  9999     0  9999    10
  9999  9999    20     0    30
  9999  9999  9999  9999     0
path矩阵（5×5）：
    -1     0     3     0     2
    -1    -1     1     1     2
    -1    -1    -1    -1     2
    -1    -1     3    -1     2
    -1    -1    -1    -1    -1

用顶点E作为其他路径的经过顶点，dist矩阵（5×5）：
     0    10    50    30    60
  9999     0    50    40    60
  9999  9999     0  9999    10
  9999  9999    20     0    30
  9999  9999  9999  9999     0
path矩阵（5×5）：
    -1     0     3     0     2
    -1    -1     1     1     2
    -1    -1    -1    -1     2
    -1    -1     3    -1     2
    -1    -1    -1    -1    -1

Floyd算法，每对顶点间的最短路径
(A,B)10	    (A,D,C)50	(A,D)30	    (A,D,C,E)60	
(B,A)∞	    (B,C)50	    (B,D)40	    (B,C,E)60	
(C,A)∞	    (C,B)∞	    (C,D)∞	    (C,E)10	
(D,A)∞	    (D,B)∞	    (D,C)20	    (D,C,E)30	
(E,A)∞	    (E,B)∞	    (E,C)∞	    (E,D)∞	


*/