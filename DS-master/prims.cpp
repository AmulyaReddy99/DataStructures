#include<iostream>
using namespace std;
int n,e,a[10],b[10],w[10],visited[10],sum=0,mini=100,min_i;
// void display(){
// 	for(int i=0;i<e;i++){
// 		printf("%d\t|%d\t|%d\n",a[i],b[i],w[i]);
// 	}
// }
void select(){

	visited[a[min_i]]=1; visited[b[min_i]]=1; sum+=w[min_i]; cout<<w[min_i]<<" ";
	int x=a[min_i],y=b[min_i],x_min=500,y_min=500, x_i,y_i;
	for(int j=0;j<n-1;j++){
		x_min=500;y_min=500;
		for(int i=0; i<e; i++){
			if ((x==a[i]||x==b[i]) && i!=min_i && x_min>w[i]){
				x_min=w[i]; 
				x_i=i;
			}
		}
		for(int i=0; i<e; i++){
			if ((y==a[i]||y==b[i]) && i!=min_i && y_min>w[i]){
				y_min=w[i];
				y_i=i;
			}
		}
		if(x_min>y_min) {
			visited[y_i]=1;
			sum+=w[y_i];
			cout<<w[y_i]<<" ";
			x=a[y_i]; y=b[y_i];
		}
		else{
			visited[x_i]=1;
			sum+=w[x_i];
			cout<<w[x_i]<<" ";
			x=a[x_i]; y=b[x_i];
		}
	}
	// for(int i=0;i<n; i++) cout<<visited[i]<<" ";
	cout<<endl<<"Sum: "<<sum<<endl;
}
int main(){
	cin>>n>>e;
	for(int i=0;i<e;i++){
		cin>>a[i]>>b[i]>>w[i];
		if(mini>w[i]) {mini=w[i]; min_i=i;}
	}
	for(int i=0;i<e;i++){
		for(int j=0;j<e;j++){
			if(w[i]<w[j]){
				int temp;
				temp=b[j]; b[j]=b[i]; b[i]=temp;
				temp=a[j]; a[j]=a[i]; a[i]=temp;
				temp=w[j]; w[j]=w[i]; w[i]=temp;
			}
		}
	}
	select();
	//display();
}
/*
6
10
0 1 10
1 2 50
2 5 15
3 5 20
0 3 30
0 4 45
4 5 55
4 2 35
1 4 40
1 5 25
*/