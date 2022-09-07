#include<iostream>
#include "vector"
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
                if(matrix[i][j]==0)
                    matrix[i][j]=INT_MAX;
            }
        }
    }
    void djstria(int pos)
    {
        vector<int> dis(num,0);
        for(int i=0;i<num;i++)
        {
            if(pos!=i)
            {
                if(matrix[pos][i]!=INT_MAX)
                    dis[i]=matrix[pos][i];
                else
                    dis[i]=INT_MAX-1;
            }
        }
        int idx,mindis;
        vis[pos]=1;
        for(int i=0;i<num;i++)
        {
            mindis=INT_MAX-2;
            idx=-1;
            for(int j=0;j<num;j++)
            {
                if(vis[j]==0&&dis[j]<mindis)
                {
                    idx=j;
                    mindis=dis[j];
                }
            }
            if(idx==-1)
                break;
            for(int i=0;i<num;i++)
            {
                if(vis[i]==0&&(long long)mindis+matrix[idx][i]<dis[i])
                    dis[i]=mindis+matrix[idx][i];
            }
            vis[idx]=1;
        }
        for(int i=0;i<num;i++)
        {
            if(i!=pos)
            {
                if(dis[i]!=INT_MAX-1)
                    cout<<dis[i];
                else
                    cout<<-1;
                if(i<num-1)
                    cout<<" ";
            }
        }
        cout<<endl;
    }
};

int main()
{
    int n,pos;
    while(scanf("%d %d",&n,&pos)!=EOF)
    {
        graph p(n);
        p.djstria(pos);
    }
    return 1;
}