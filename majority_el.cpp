#include<iostream>
#include<map>
using namespace std;

void majority(int [], int);

int main()
{
	int t;
	cin>>t;
	while(t)
	{
		int n;
		cin>>n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin>>a[i];
		}
		
		majority(a,n);
		t--;
	}
}


void majority(int a[],int n)
{
	int count=1;
	int major=0;
	for (int i=1;i<n;i++)			//candidate for majority element
		{
			if(a[major]==a[i])
				count++;
			else
				count--;
			if(count==0)
			{
				major=i;
				count=1;
			}
		}

	int c=0;							//checking if candidate is actually majority element
	for (int i = 0; i < n; ++i)
	{
		if (a[major]==a[i])
		{
			c++;
		}
	}

	if(c > (n/2))
		cout<<a[major]<<endl;
	else
		cout<<"NO majority element"<<endl;
}