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
node * head;
node * temp;
node * temp2;
public:
	list(){
		head=NULL;
	}

	void create(int x){
		
		if(head==NULL){ //from start
			head = new node; 
			head->next=NULL;
			head->data=x;
			cout<<"yes "<<head->data;
		}
		else{
			cout<<"1.insert start 2.end 3.any\n";
			int t; cin>>t;
			switch(t){
			case 1:	temp = new node;
				temp->next = head;
				temp->data = x;
				head = temp;
				cout<<"yes2 "<<temp->data;
				break;
			case 2: temp = new node;
				temp2 = head;
				while(temp2->next)
					temp2=temp2->next;
				temp2->next=temp;
				temp->data=x;
				temp->next=NULL; 
				cout<<"yes3 "<<temp->data;
				break;
			case 3: // segmentation fault
				cout<<"value after? ";
				int s; cin>>s;
				temp=head;
				while(temp->data != s)
					temp=temp->next;
				temp2->next=temp->next;
				temp->next=temp2;
				temp2->data=x;
				cout<<"yes4 "<<temp->data;
				break;
			}
		}
	}

	void pop(){ 
		cout<<"1.pop start 2.end 3.any\n";
		int t; cin>>t;
		switch(t){	//from start
		case 1:	cout<<head->data; 
			head = head->next; 
			break;
		case 2: while(temp->next!=NULL)
			{ temp2=temp; temp= temp->next; }
			cout<<temp->data;
			temp2->next = NULL;
			delete temp; // pointer being freed was not allocated
			break;
		case 3:
			int x;
			cout<<"enter el ";
			cin>>x;
			while(temp->data == x){
				temp2 =temp;
				temp =temp->next;
			}
			cout<<temp->data;
			temp2->next = temp->next;
		}
	}
	void display(){ 
		temp = head;
		while(temp->next!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
};

int main(){
	cout<<"***** A program to push & pop from start, end, anywhere and display on demand! *****";
	list l; int t;
	while(1){
		cout<<"1.in 2.pop 3.show 4.stop";
		cin>>t; 
		switch(t){
			case 1: cin>>t; l.create(t);  break;
			case 2: l.pop(); break;
			case 3: l.display(); break;
			case 4: exit(0); break;
		}
	}
}