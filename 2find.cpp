#include <iostream>
#include <random>
using namespace std;

class findMax
{
public:
	int a[10]={12, 2, 19, 1, 20, 44, 18, 17, 0, 13};
	int sum, s[10], l;
	findMax(){
		sum=0; l=0;
	}
	void profit(){

		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if(a[i]==a[j]+1 || a[i]==a[j]-1)
				{
					s[l]=a[i];
					cout<<s[l]<<" "; l++;
					a[i]=0;
					a[j]=0;
				}
			}
		}
		for (int i = 0; i <= 10; i++)
		{
			sum+=a[i];
		}
		for (int i = 0; i < l; ++i)
		{
			sum+=s[l];
		}
		cout<<"\nSum: "<<sum<<endl;
	}
};

int main(){
	findMax f;
	f.profit();
}