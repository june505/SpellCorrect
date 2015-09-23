#include "../inc/MinEditDist.h"
#include <iostream>
#include <cstring>

int min(int a,int b)
{
	return a<b?a:b;
}
/*
MinEditDist::MinEditDist(string target,string source)
	:source_(source),
	target_(target),
	tarlen(target_.size()),
	srclen(source_.ize())
{
}
*/
int MinEditDist::calcMinEditDistance(string target_,string source_)
{
	int tarlen=target_.size();
	int srclen=source_.size();

	int arr[srclen+1][tarlen+1];
	memset(arr,0,sizeof(arr));
	for(int i=0;i<srclen+1;i++)
	{
		arr[i][0]=i;
	}
	
	for(int i = 0;i<tarlen+1;i++)
	{
		arr[0][i]=i;
	}

	for(int i=1;i<srclen+1;i++)
	{
		for(int j=1;j<tarlen+1;j++)
		{
			int d;
			int temp = min(arr[i-1][j]+1,arr[i][j-1]+1);

			if(source_[i-1]==target_[j-1])
			{
				d=0;
			}
			else
			{
				d=2;
			}

			arr[i][j]=min(temp,arr[i-1][j-1]+d);

		}
	}
	/*for(int i =0;i<srclen+1;i++)
	{
		for(int j=0;j<tarlen+1;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	int dis = arr[srclen][tarlen];
	return dis;
}

