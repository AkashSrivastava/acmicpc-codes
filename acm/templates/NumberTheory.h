/*
 * Package: StandardCodeLibrary.NumberTheory
 * Last Update: 2012-12-21
 * Description:
 * O(n)��ɸ����������;
 * Rabin-Miller��������;
 * Pollard's rho�����ֽ�;
 * ����phi;
 * ��չgcd;
 * �й�ʣ�ඨ��;
 * ָ��ѭ����;
 * */
#include <Core>

namespace StandardCodeLibrary
{
namespace NumberTheory
{

//O(n)��ɸ����������
//MAXPS=[1,MAXP]�������ĸ���
enum{MAXP=10000000,MAXPS=664579};
bool isp[MAXP+1];//isp[x]=x�Ƿ�Ϊ����
int pp[MAXP+1];//pp[x]=x���������е�λ��(��0��ʼ)
int fac[MAXP+1];//fax[x]=x��С��������(x<=1ʱ������)
int ps;//������Ĵ�С
int p[MAXPS];//������
void make_prime_table()
{
	fl(isp,true);
	isp[0]=isp[1]=false;
	ft(i,2,MAXP)
	{
		if (isp[i]) pp[p[ps]=i]=ps,ps++,fac[i]=i;
		for (int j=0;p[j]*i<=MAXP;j++)
		{
			isp[p[j]*i]=false,fac[p[j]*i]=p[j];
			if(i%p[j]==0) break;
		}
	}
}

lli mulWithMod(lli x,lli y,lli z)
{
	lli ret=0;
	x%=z;
	y%=z;
	whl(y)
	{
		if (y&1)
		{
			ret+=x;
			if (ret>=z) ret-=z;
		}
		x<<=1;
		if (x>=z) x-=z;
		y>>=1;
	}
	rtn ret;
}
lli powWithMod(lli x,lli y,lli z)
{
	lli ret=1;
	x%=z;
	whl(y)
	{
		if (y&1) ret=mulWithMod(ret,x,z);
		y>>=1;
		x=mulWithMod(x,x,z);
	}
	rtn ret;
}

//Rabin-Miller��������
bool isProbablePrime(lli n,lli k=50)
{
	if (n<=1) rtn false;
	else if (n<=3) rtn true;
	else
	{
		lli d=n-1;
		whl(!(d&1)) d>>=1;
		rep(i,k)
		{
			lli a=rand()%(n-3)+2;//2 to n-2
			lli x=powWithMod(a,d,n);
			if (x==1) continue;
			whl(d!=n-1&&x!=n-1&&x!=1)
			{
				x=mulWithMod(x,x,n);
				d<<=1;
			}
			if (x!=n-1) rtn false;
		}
		rtn true;
	}
}

//Pollard's rho�����ֽ�
lli factor(lli n,lli k=50)
{
	if (isProbablePrime(n,k)) rtn n;
	lp
	{
		lli d=1,x=rand()%(n-1)+1,//1 to n-1
				y=rand()%(n-1)+1,//1 to n-1
				c=rand()%n;
		if (c==0) c++;//c!=0
		if (c==n-2) c++;//c!=n-2
		lli loop=0;
		whl(d==1)
		{
			loop++;
			if (((-loop)&loop)==loop) y=x;
			x=(mulWithMod(x,x,n)+c)%n;
			if (x==y) break;
			d=gcd(y-x+n,n);
			if (d!=1&&d!=n) rtn factor(d,k);
		}
	}
}

//����phi
lli phi(lli x,lli k=50)
{
	lli ret=x;
	whl(x!=1)
	{
		lli d=factor(x,k);//�����С��Χ�� �˴�����fac[x]����
		ret/=d;
		ret*=d-1;
		whl(x%d==0) x/=d;
	}
	rtn ret;
}

//��չgcd
lli gcd(lli a,lli b,lli& x,lli& y)
{
	if (b)
	{
		lli g=gcd(b,a%b,y,x);
		rtn y-=a/b*x,g;
	}
	else rtn x=1,y=0,a;
}

//�й�ʣ�ඨ��
//һ���,�й�ʣ�ඨ����ָ����һЩ�������ʵ�����m[i],������������a[i],��������ͬ�෽�����ģm[i]�й���
//x mod m[i]=a[i]
lli chinese_remainder(lli n,lli m[],lli a[])
{
	lli lcm=1;
	rep(i,n) lcm*=m[i];
	lli ans=0;
	rep(i,n)
	{
		lli Mi=lcm/m[i],x,y;
		gcd(Mi,m[i],x,y);
		ans+=Mi*x*a[i];
		ans%=lcm;
	}
	if (ans<0) ans+=lcm;
	rtn ans;
}

//ָ��ѭ����
//���(a,p)=1		a^x%p=a^(x%phi(p))%p
//������x>=phi(p)	a^x%p=a^(x%phi(p)+phi(p))%p
lli mod(lli x,lli phip)
{
	rtn x>=phip?x%phip+phip:x;
}

}
}
