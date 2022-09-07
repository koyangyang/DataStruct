#include "iostream"
#include "vector"
using namespace std;
struct eage{
    int to;
    eage(int a): to(a) {}
};
class graph{
    vector<vector<eage>> Eages;
    vector<int> degree;
    int num;
public:
    graph(int a,int b)
    {
        num=a;
        Eages.resize(num+1);
        degree.resize(num+1,0);
        int from,to;
        for(int i=0;i<b;i++)
        {
            cin>>from>>to;
            Eages[from].push_back(to);
            degree[to]++;
        }
    }
    void top_sort()
    {
        vector<int> mem;
        vector<int> vis(num,0);
        for(int i=0;i<num;i++)
        {
            int idx=-1;
            for(int j=0;j<num;j++)
            {
                if(vis[j]==0&&degree[j]==0)
                {
                    idx=j;
                    vis[j]=1;
                    break;
                }
            }
            if(idx!=-1)
                mem.push_back(idx);
            else
                break;
            for(int j=0;j<Eages[idx].size();j++)
            {
                degree[Eages[idx][j].to]--;
            }
        }
        if(mem.size()==num)
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
};
int main()
{
    int a,b;
    cin>>a>>b;
    graph p(a,b);
    p.top_sort();
    return 1;

}