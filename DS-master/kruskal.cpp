#include<iostream>
using namespace std;
int n,e,a[10],b[10],w[10],visited[10],sum=0,counter=0;
// void display(){
// 	for(int i=0;i<e;i++){
// 		printf("%d\t|%d\t|%d\n",a[i],b[i],w[i]);
// 	}
// }
void select(){
	visited[a[0]]=1; visited[b[0]]=1; sum+=w[0];
	for(int i=1;i<e;i++){
		if(visited[a[i]]==0 || visited[b[i]]==0){
			visited[a[i]]=1; visited[b[i]]=1; sum+=w[i];
		}
		else{
			counter++;
			if(counter==1) sum+=w[i]; 
		}
	}
	// for(int i=0;i<n; i++) cout<<visited[i]<<" ";
	cout<<endl<<"Sum: "<<sum<<endl;
}
int main(){
	cin>>n>>e;
	for(int i=0;i<e;i++)
		cin>>a[i]>>b[i]>>w[i];
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
