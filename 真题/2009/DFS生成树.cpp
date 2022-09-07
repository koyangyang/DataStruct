#include<bits/stdc++.h>
using namespace std;
class graph{
    int **matrix;
    int num;
    vector<int> vis;
    vector<int>mem;
public:
    graph(int n)
    {
        num=n;
        matrix=new int*[n];
        vis.resize(num,0);
        for(int i=0;i<num;i++)
        {
            matrix[i]=new int[num];
        }
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<num;j++)
            {
                cin>>matrix[i][j];
            }
        }
    }
    void DFS_travel()
    {
        for(int i=0;i<num;i++)
        {
            if(vis[i]==0)
                DFS(i);
        }
        for(int i=0;i<mem.size();i++)
        {
            cout<<mem[i];
            if(i<mem.size()-1)
                cout<<" ";
        }
        cout<<endl;
    }
    void DFS(int pos)
    {
        mem.push_back(pos);
        vis[pos]=1;
        for(int i=0;i<num;i++)
        {
            if(vis[i]==0&&matrix[pos][i]==1)
                DFS(i);
        }
    }
};

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        graph p(n);
        p.DFS_travel();
    }
    return 1;
}