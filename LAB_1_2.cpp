
#include <iostream>
#include <stdlib.h>
#include <cmath>
 
using namespace std;
 
int main()
{
	double z,y;
	int x,s_x,s_y,p,q,*a,count_x=0,count_y=1,n;
	cout << "Введите кол-во бит:"; cin >> n;
	if(n==32) {p=8;q=127;}
	else if(n==64) {p=11;q=1023;}
	else if(n==128) {p=15;q=16383;}
	a = new int [n];
	cout << "Введите число: "; cin >> z;
	x=z;
	y=z;
	x=abs(x);
	y=abs(y);
	s_x=x;
	a = new int [n];
	if (x!=0)
	{
		while(x!=1)
		{	
			x=x/2;
			count_x++;
		}
		x=count_x+q;
		for (int i=p;i>0;i--)
			{
				a[i]=x%2;
				x=x/2;
			}
		for (int i=p+count_x;i>p;i--)
		{
			a[i]=s_x%2;
			s_x=s_x/2;
		}
		
		if(y!=0)
		{	
			while(y<10000)
			{	
				y=y*10;
				count_y=count_y*10;
			}
			
			s_y=y;
			for(int i=count_x+p+1;i<n;i++)
			{
				a[i]=(s_y*2)/count_y;
				s_y=(s_y*2)%count_y;
			}
		}
		else
			for(int i=count_x+p+1;i<n;i++)
				a[i]=0;
	}
	else 
	{
		while(y<10000)
		{	
			y=y*10;
			count_y=count_y*10;
		}			
		s_y=y;
		for(int i=0;i<n;i++)
		{
			a[i]=(s_y*2)/count_y;
			s_y=(s_y*2)%count_y;
		}
		for(int i=0;i<n;i++)
			if(a[i]!=1)
				count_x++;
			else i=n;
			
		count_x=q-count_x-1;
		
		for (int i=p;i>0;i--)
		{
			a[i]=count_x%2;
			count_x=count_x/2;
		}
				
	}
	
	if (z>0) 
		a[0]=0;
	else a[0]=1;
	cout << " --------------- " << endl;
	for(int i=0;i<n;i++)
		cout << a[i] << " ";

return 0; 
	
}


