#include<bits/stdc++.h>
using namespace std;
vector<int>gp[20003];
int vis[100007];
int level[100007];
int bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=1;
    level[src]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<gp[u].size();i++)
        {
            int v=gp[u][i];
            if(!vis[v])
            {
                vis[v]=1;
                level[v]=!level[u];
                q.push(v);
            }
        }
    }

}

int main()
{
    int test;
    scanf("%d",&test);
    //freopen("out.txt","w",stdout);
    for(int tst=1;tst<=test;tst++)
    {
        memset(vis,0,sizeof(vis));
        memset(level,0,sizeof(level));
        for(int i=0;i<20002;i++)
            gp[i].clear();
        long long int n;
        scanf("%lld",&n);
        set<int>s;
        int k=0;
        int arr[100006];
        for(int i=0;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            //int sz=s.size();
            s.insert(a);
            //int sz1=s.size();
//            if(sz<sz1)
//                arr[k++]=a;
            s.insert(b);
//            sz=s.size();
//            if(sz>sz1)
//                arr[k++]=b;
            gp[a].push_back(b);
            gp[b].push_back(a);
        }
        int m=s.size();
       // cout<<"siz "<<s.size()<<endl;
        for(int i=0;i<m;i++)
        {
            arr[k++]=*(s.begin());
            //cout<<k<<endl;
            s.erase(s.begin());
        }
        s.clear();
        //cout<<k<<endl;
        //cout<<k<<endl;
        int maxx=0;
        for(int i=0;i<k;i++)
        {
            if(!vis[arr[i]])
            {
                //cout<<arr[i]<<endl;
                bfs(arr[i]);
                int cnt1=0,cnt2=0;
                for(int j=0;j<k;j++)
                {
                    if(vis[arr[j]]==1)
                    {
                        vis[arr[j]]=2;
                        if(level[arr[j]])
                            cnt1++;
                        else
                            cnt2++;
                    }
                }
                maxx+=max(cnt1,cnt2);
                //cout<<"maxx "<<maxx<<endl;
            }
        }
        //cout<<"k "<<k<<endl;
//        for(int i=0;i<k;i++)
//        {
//            cout<<level[arr[i]]<<" ";
//        }
//        cout<<endl;

        printf("Case %d: %d\n",tst,maxx);
    }

    return 0;
}
