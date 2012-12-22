/*
 * Package: StandardCodeLibrary.GraphTheory.MinCostMaxFlow
 * Last Update: 2012-12-22
 * Usage:
 * MAXV:��ҪΪ�������ٿռ�,��ֻҪ��0��MAXV-1�Ϳ����ˣ���MAXVӦ�ô��������
 * MAXE:��ҪΪ�߷�����ٿռ�,һ���߶�Ӧһ������ߺ�һ������ߣ���MAXEҪ����ʵ��������*2
 * add_edge:
 * ����int u,v,c,d
 * add_edge(u,v,c,d) ��һ��u��v������Ϊc����Ϊd�������,��һ��v��u������Ϊ0����Ϊ-d�������
 * build_graph:��ͼ,��ϸ�������ڵ�ע��
 * min_cost_max_flow:
 * min_cost_max_flow(�����,��С����)
 * */
#include <Core>

namespace StandardCodeLibrary
{
namespace GraphTheory
{
namespace MinCostMaxFlow
{

#define oo 0x7f7f7f7f
const int MAXE=1000000;
const int MAXV=1000000;
typedef struct struct_edge* edge;
struct struct_edge{int v,c,d;edge n,b;};
struct_edge pool[MAXE];
edge top;
int S,T;
edge adj[MAXV];
int d[MAXV];
int q[MAXV];
bool inq[MAXV];
int qh,qt;
void add_edge(int u,int v,int c,int d)
{
	top->v=v,top->c=c,top->d=d,top->n=adj[u],adj[u]=top++;
	top->v=u,top->c=0,top->d=-d,top->n=adj[v],adj[v]=top++;
	adj[u]->b=adj[v],adj[v]->b=adj[u];
}
edge p[MAXV];
void min_cost_max_flow(int& flow,int& cost)
{
	flow=0,cost=0;
	lp
	{
		fl(d,oo),inq[q[qh=qt=0]=S]=true,d[S]=0,p[S]=0;
		whl(qh<=qt)
		{
			int u=q[(qh++)%MAXV];
			inq[u]=false;
			for (edge i=adj[u];i;i=i->n)
				if (i->c&&cmin(d[i->v],d[u]+i->d))
				{
					if (!inq[i->v]) inq[q[(++qt)%MAXV]=i->v]=true;
					p[i->v]=i;
				}
		}
		if (d[T]==oo) break;
		else
		{
			int delta=oo;
			for (edge i=p[T];i;i=p[i->b->v]) cmin(delta,i->c);
			for (edge i=p[T];i;i=p[i->b->v]) i->c-=delta,i->b->c+=delta;
			flow+=delta;
			cost+=d[T]*delta;
		}
	}
}
void build_network()
{
	top=pool,clr(adj);
	//S,T;//Դ,��
	//add_edge(u,v,c,d);
}

}
}
}
