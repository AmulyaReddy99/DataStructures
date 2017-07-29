#include <iostream>
using namespace std;
class node
{
public:
	node * next;
	int data;
};

class list: public node
{
public:
node * head;
node * temp;
node * temp2;
	
	list(){
		head=NULL;
		temp=head;
	}

	void create(int x){
		if(head==NULL){ //from start
			head = new node; 
			head->next=NULL;
			head->data=x;
			cout<<"yes "<<head->data;
		}
		else{
			temp = new node;
			temp->next = head;
			temp->data = x;
			head = temp;
			cout<<"yes2 "<<temp->data;
		}
	}
	
};

class matrix: public list
{
int r,c;
public:

	void getmatrix(){
		head=NULL;
		cout<<"enter size: ";
		cin>>r>>c;
		cout<<"elements? ";
			for(int i=0; i<r*c; i++)
			{
				int x; cin>>x;
				create(x);
			}
	}

	void operator+(matrix & m){
		if(r==m.r && c==m.c){
			temp = head;
			cout<<"\n";
			for (int i = 0; i < r; ++i)
			{
				for (int j = 0; j < c; ++j)
				{
					cout<<temp->data+m.temp->data<<" ";
					temp=temp->next;
					m.temp=m.temp->next;
				}
				cout<<"\n";
			}
		}
		else cout<<"addition not possible";
	}

	void operator*(matrix & m)
	{
		int rsum=0; 
		if(c==m.r){
			temp = head; m.temp=m.head;
			for (int i = 0; i < r; i++)
			{ 
				m.temp=m.head;
				for (int j = 0; j < m.c; j++)
				{
					for (int k = 0; k < c; k++)
					{
						rsum += (temp->data * m.temp->data);
						temp=temp->next;
						for (int l = 0; l < m.c; ++l)  //m.c*j --> wrong
							m.temp=m.temp->next;
					}
					cout<<rsum<<" ";
					rsum=0;
					temp=head;
					m.temp=m.head;
					for (int l = 0; l < j; l++)
						m.temp=m.temp->next;
					// m.temp->data=m.temp->next->data;
					cout<<m.temp->data<<"\t";
				}

				for (int l = 0; l <= c*i; l++)
				{	cout<<temp->data<<" "; temp=temp->next;}
				cout<<"\n";
			}
		}
		else cout<<"multiplication not possible";
	}
};

int main(){
	matrix m1, m2;
	m1.getmatrix();
	m2.getmatrix();
	m1+m2;
	m1*m2;
}