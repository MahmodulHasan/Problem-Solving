#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll cap[110][110],ResCap[110][110],flow[110][110];

ll maxFlow = 0;
ll par[110];

ll tmp[110][110];
ll lvl[110];

vector<int>gp[110];

int bfs(ll u,ll t)
{
    queue<ll>q;
    memset(lvl,0,sizeof(lvl));
    q.push(u);
    lvl[u]=1;
    while(!q.empty())
    {
        ll u = q.front();
        q.pop();
        for(int i=0; i<gp[u].size(); i++)
        {
            int v= gp[u][i];
            if(lvl[v]==0 && cap[u][v]> 0)
            {
                lvl[v]=1;
                par[v]=u;
                q.push(v);
            }
        }
    }
    if(lvl[t]==1)
    {
        return true;
    }
    return false;
}

void FordFulkerson(ll s, ll t)
{
    maxFlow = 0;
    memset(par,-1,sizeof(par));
    while(bfs(s,t))
    {
        ll v =t;
        ll mn = 10000000;
        while(par[v]!=-1)
        {
            //getchar();
            ll u=par[v];
            ll cst = cap[u][v];
            mn = min(cst,mn);
            v=par[v];
        }
        v = t;
        while(par[v]!=-1)
        {
            ll u=par[v];
            cap[u][v] -= mn;
            ResCap[u][v] +=mn;
            v=par[v];
        }
        maxFlow+=mn;
        //cout<<maxFlow<<endl;
        memset(par,-1,sizeof(par));
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int tst=1; tst<=test; tst++)
    {
        ll n;
        memset(cap,0,sizeof(cap));
        memset(ResCap,0,sizeof(ResCap));
        scanf("%lld",&n);

        for(int i=0;i<=n;i++)
        {
            gp[i].clear();
        }

        ll s,t,m;
        scanf("%lld%lld%lld",&s,&t,&m);

        for(int i=0; i<m; i++)
        {
            ll u,v,w;
            scanf("%lld%lld%lld",&u,&v,&w);
            gp[u].push_back(v);
            gp[v].push_back(u);
            cap[u][v]+=w;
            cap[v][u]+=w;
            //ResCap[v][u]+=w;
        }

        FordFulkerson(s,t);

        printf("Case %d: %lld\n",tst,maxFlow);
    }

    return 0;
}
/*

2
4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
4
1 4 2
1 4 20
1 4 20

*/
