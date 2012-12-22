/*
 * Package: StandardCodeLibrary.GraphTheory.Edmonds'sMatchingAlgorithm
 * Last Update: 2012-12-21
 * Usage:
 * MAXV:��ҪΪ�������ٿռ�,��һ��Ҫ��0��V-1����MAXVӦ�õ���������
 * MAXE:��ҪΪ�߷�����ٿռ�,һ���߶�Ӧһ������ߺ�һ������ߣ���MAXEҪ����ʵ��������*2
 * V:����
 * add_edge:
 * ����int u,v
 * add_edge(u,v) ��һ��u��v�ıߺ�һ��v��u�ı�
 * build_graph:��ͼ,��ϸ�������ڵ�ע��
 * edmonds:
 * ���int
 * edmonds()=���ƥ����
 * �������:
 * ���match[u]==NOT_NODE��uû�б�ƥ��
 * ����u��match[u]ƥ��
 * */

#include <Core>

namespace StandardCodeLibrary
{
namespace GraphTheory
{
namespace Edmonds_sMatchingAlgorithm
{

const int MAXV=100;
const int MAXE=MAXV*MAXV*2;
const int NOT_NODE=-1;
struct struct_edge{int v;struct_edge* n;};
typedef struct_edge* edge;
int V;
struct_edge pool[MAXE];
edge top;
edge adj[MAXV];
void build_graph()
{
	top=pool;
	clr(adj);
	//V;//����
	//Warning:
	//V�����ϸ����ͼ�еĵ����Ŀ
	//add_edge(u,v);
}
void add_edge(int u,int v)
{
	top->v=v,top->n=adj[u],adj[u]=top++;
	top->v=u,top->n=adj[v],adj[v]=top++;
}
int match[MAXV];
int qh,qt;
int q[MAXV];
bool inq[MAXV];
int father[MAXV];
int base[MAXV];
bool ib[MAXV];
bool ip[MAXV];
int LCA(int root,int u,int v)
{
	clr(ip);
	lp
	{
		ip[u=base[u]]=true;
		if (u==root) break;
		u=father[match[u]];
	}
	lp
	{
		if (ip[v=base[v]]) rtn v;
		else v=father[match[v]];
	}
}
void mark_blossom(int lca,int u)
{
	whl(base[u]!=lca)
	{
		int v=match[u];
		ib[base[u]]=true;
		ib[base[v]]=true;
		u=father[v];
		if (base[u]!=lca) father[u]=v;
	}
}
void blossom_contraction(int s,int u,int v)
{
	int lca=LCA(s,u,v);
	clr(ib);
	mark_blossom(lca,u);
	mark_blossom(lca,v);
	if (base[u]!=lca) father[u]=v;
	if (base[v]!=lca) father[v]=u;
	rep(u,V)
		if (ib[base[u]])
		{
			base[u]=lca;
			if (!inq[u]) inq[q[++qt]=u]=true;
		}
}
int find_augmenting_path(int s)
{
	clr(inq),fl(father,NOT_NODE);
	for (int i=0;i<V;i++) base[i]=i;
	inq[q[qh=qt=0]=s]=true;
	whl(qh<=qt)
	{
		int u=q[qh++];
		for (edge e=adj[u];e;e=e->n)
		{
			int v=e->v;
			if (base[u]!=base[v]&&match[u]!=v)
			{
				if ((v==s)||(match[v]!=NOT_NODE&&father[match[v]]!=NOT_NODE))
					blossom_contraction(s,u,v);
				else if (father[v]==NOT_NODE)
				{
					father[v]=u;
					if (match[v]==NOT_NODE) rtn v;
					else if (!inq[match[v]]) inq[q[++qt]=match[v]]=true;
				}
			}
		}
	}
	rtn NOT_NODE;
}
int augment_path(int s,int t)
{
	int u,v,w;
	u=t;
	whl(u!=NOT_NODE)
	{
		v=father[u];
		w=match[v];
		match[v]=u;
		match[u]=v;
		u=w;
	}
	rtn t!=NOT_NODE;
}
int edmonds()
{
	int matchc=0;
	fl(match,NOT_NODE);
	for (int u=0;u<V;u++)
		if (match[u]==NOT_NODE)
		matchc+=augment_path(u,find_augmenting_path(u));
	rtn matchc;
}

}
}
}
