#include<stdio.h>
#include<math.h>
#include<stdbool.h>
int len(int x)
{
	int ans=0;
	while(x)
	{
		ans++;
		x/=10;
	}
	return ans;
}

bool mirror(int a,int b)
{
	if(b>a)
	{
		int temp =a;
		a=b;
		b=temp;
	}
	//printf("%d %d\n",a,b);
	int rev=0;
	while(a)
	{
		int q = a%10;
		a/=10;
		rev*=10;
		rev+=q;
	}
	//printf("%d\n",rev);
	if(rev==b)
	{
		return true;
	}
	else{
		return false;
	}

}

bool check(int i, int j, int x,int n)
{
	int a=0,b=0,c=0;
	int z=0;
	for(int ii = n-1;ii>j;ii--)
	{
		int q = x%10;
		x/=10;
		a+=((pow(10,z))*q);
		z++;
	}
	z=0;
	for(int ii=j;ii>i;ii--)
	{
		int q = x%10;
		x/=10;
		b+=((pow(10,z))*q);
		z++;
	}
	z=0;
	for(int ii=i;ii>=0;ii--)
	{
		int q = x%10;
		x/=10;
		c+=((pow(10,z))*q);
		z++;
	}
	//printf("%d %d %d\n",a,b,c);
	if((a+b) ==c)
	{

		//printf("%d yess\n",0);
		if(mirror(a,b))
		{
			printf("%d\n",c);
			return true;
		}
	}
	else if((b+c) == a)
	{
		if(mirror(b,c))
		{

			printf("%d\n",a);
			return true;
		}
	}
	else if((a+c) ==b)
	{
		if(mirror(c,a))
		{

			printf("%d\n",b);
			return true;
		}
	}
	else{
		return false;
	}
	return false;
}


int main(){
	int x;
	scanf("%d",&x);
	//printf("aa");
	int n = len(x);
	//printf("%d\n",n);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n-1;j++)
		{
			//printf("%d %d\n",i,j);
			if(check(i,j,x,n))
			{
				return 0;
			}
		}
	}
	printf("%d\n",0);
	return 0;
}