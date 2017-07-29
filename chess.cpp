#include <iostream>
using namespace std;
class chess
{
public:
	int a[8][8];
	int r,c;
	chess(){
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j)
				a[i][j]=0;

		cout<<"your empty chess board\n";
		display();
	}
	void display(){
		cout<<"  0 1 2 3 4 5 6 7 \n";
		for (int i = 0; i < 8; ++i)
		{
			cout<<i<<" ";
			for (int j = 0; j < 8; ++j)
				cout<<a[i][j]<<" ";
			cout<<"\n";
		}
	}

	void rook(){
		cout<<"enter position";
		cin>>r>>c;
		for (int i = 0; i < 8; ++i)
		{	
			a[r][c]=1;
			if(a[r][i]==0) a[r][i]=1;
			if(a[i][c]==0) a[i][c]=1;
		}
		display();
	}

	void bishop(){
		cout<<"enter position";
		cin>>r>>c;
		for (int i = 0; i < 8; ++i)
		{
			a[r][c]=1;
			if(a[r+i][c+i]==0 && (r+i <8 && c+i<8) && (r+i>=0 && c+i>=0)) a[r+i][c+i]=1;
			if(a[r-i][c-i]==0 && (r-i <8 && c-i<8) && (r-i>=0 && c-i>=0)) a[r-i][c-i]=1;
			if(a[r+i][c-i]==0 && (r+i <8 && c-i<8) && (r+i>=0 && c-i>=0)) a[r+i][c-i]=1;
			if(a[r-i][c+i]==0 && (r-i <8 && c+i<8) && (r-i>=0 && c+i>=0)) a[r-i][c+i]=1;
		}
		display();
	}
	void king(){
		cout<<"enter position";
		cin>>r>>c;
			a[r][c]=2;
			if(r-1<8 && r-1>=0 && a[r-1][c]==0) a[r-1][c]=2;
			if(r+1<8 && r+1>=0 && a[r+1][c]==0) a[r+1][c]=2;
			if(c-1<8 && c-1>=0 && a[r][c-1]==0) a[r][c-1]=2;
			if(c+1<8 && c+1>=0 && a[r][c+1]==0) a[r][c+1]=2;
			if(r-1<8 && c-1>=0 && a[r-1][c-1]==0) a[r-1][c-1]=2;
			if(r+1<8 && c+1>=0 && a[r+1][c+1]==0) a[r+1][c+1]=2;
			if(r-1<8 && c+1>=0 && a[r-1][c+1]==0) a[r-1][c+1]=2;
			if(r+1<8 && c-1>=0 && a[r+1][c-1]==0) a[r+1][c-1]=2;
		display();
	}
	void pawn(){
		cout<<"enter position";
		cin>>r>>c;
			a[r][c]=3;
			if(r+1<8) a[r+1][c]=3;
			if(r+1<8 && c-1<8 && c-1>=0 && a[r+1][c-1]!=0) a[r+1][c-1]=3;
			if(r+1<8 && c+1<8 && c+1>=0 && a[r+1][c+1]!=0) a[r+1][c+1]=3;
		display();
	}
	void queen(){
		cout<<"enter position";
		cin>>r>>c;
		for (int i = 0; i < 8; ++i)
		{
			a[r][c]=8;
			if(a[r+i][c+i]==0 && (r+i<8 && c+i<8) && (r+i>=0 && c+i>=0)) a[r+i][c+i]=8;
			if(a[r-i][c-i]==0 && (r-i<8 && c-i<8) && (r-i>=0 && c-i>=0)) a[r-i][c-i]=8;
			if(a[r+i][c-i]==0 && (r+i<8 && c-i<8) && (r+i>=0 && c-i>=0)) a[r+i][c-i]=8;
			if(a[r-i][c+i]==0 && (r-i<8 && c+i<8) && (r-i>=0 && c+i>=0)) a[r-i][c+i]=8;
			if(a[r][i]==0) a[r][i]=8;
			if(a[i][c]==0) a[i][c]=8;
		}
		display();
	}
	void knight(){
		cout<<"enter position";
		cin>>r>>c;
			a[r][c]=9;
			if(a[r+2][c+1]==0 && (r+2<8 && c+1<8) && (r+2>=0 && c+1>=0)) a[r+2][c+1]=9;
			if(a[r+2][c-1]==0 && (r+2<8 && c-1<8) && (r+2>=0 && c-1>=0)) a[r+2][c-1]=9;
			if(a[r-2][c+1]==0 && (r-2<8 && c+1<8) && (r-2>=0 && c+1>=0)) a[r-2][c+1]=9;
			if(a[r-2][c-1]==0 && (r-2<8 && c-1<8) && (r-2>=0 && c-1>=0)) a[r-2][c-1]=9;
			if(a[r+1][c+2]==0 && (r+1<8 && c+2<8) && (r+1>=0 && c+2>=0)) a[r+1][c+2]=9;
			if(a[r-1][c+2]==0 && (r-1<8 && c+2<8) && (r-1>=0 && c+2>=0)) a[r-1][c+2]=9;
			if(a[r+1][c-2]==0 && (r+1<8 && c-2<8) && (r+1>=0 && c-2>=0)) a[r+1][c-2]=9;
			if(a[r-1][c-2]==0 && (r-1<8 && c-2<8) && (r-1>=0 && c-2>=0)) a[r-1][c-2]=9;	
		display();
	}
};

int main()
{
	chess player;
	int response;
	while(1){
		cout<<"1.king 2.queen 3.rook 4.bishop 5.knight 6.pawn 7.exit";
		cin>>response;
		switch(response){
			case 1: player.king(); break;
			case 2: player.queen(); break;
			case 3: player.rook(); break;
			case 4: player.bishop(); break;
			case 5: player.knight(); break;
			case 6: player.pawn(); break;
			case 7: exit(0);
 		}
	}
}