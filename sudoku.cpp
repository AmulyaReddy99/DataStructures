#include <iostream>
using namespace std;
class sudoku
{
int a[9][9];
	public:
	sudoku()
	{
		for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			a[i][j]=0;
	}
	void display(){
		cout<<"1 2 3   4 5 6   7 8 9\n";
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
				{	
					cout<<a[i][j]<<" ";
					for (int n = 0; n < 9; ++n)
						if(j==3*n-1 && j!=0) cout<<"| ";
				}
			cout<<"\n";
			for (int n = 1; n <= 9; ++n)
			if(i==3*n-1 && i!=0) cout<<"----------------------\n";

		}
	}

	void initialWorld(){
		a[0][3]=8; 
		a[1][0]=5;
		a[1][1]=9;
		a[1][2]=4;
		a[1][6]=2;
		a[2][1]=6;
		a[2][5]=3;
		a[2][6]=1;
		a[2][7]=9;
		a[2][8]=4;
		//
		a[3][0]=6; 
		a[3][3]=3;
		a[3][4]=7;
		a[3][7]=2;
		a[4][1]=4;
		a[4][2]=9;
		a[4][4]=1;
		a[4][6]=5;
		a[4][7]=8;
		a[5][1]=2;
		a[5][4]=9;
		a[5][5]=8;
		a[5][8]=6;
		//
		a[6][0]=9; 
		a[6][1]=8;
		a[6][2]=6;
		a[6][3]=1;
		a[6][7]=4;
		a[7][2]=3;
		a[7][6]=9;
		a[7][7]=6;
		a[7][8]=7;
		a[8][5]=6;
	}

		void insert(int x){
			int i,j;
			cout<<"Enter element position";
			cin>>i>>j;
			if(
		a[i][j]==a[0][3] ||
		a[i][j]==a[1][0] ||
		a[i][j]==a[1][1] ||
		a[i][j]==a[1][2] ||
		a[i][j]==a[1][6] ||
		a[i][j]==a[2][1] ||
		a[i][j]==a[2][5] ||
		a[i][j]==a[2][6] ||
		a[i][j]==a[2][7] ||
		a[i][j]==a[2][8] ||
		//
		a[i][j]==a[3][0] ||
		a[i][j]==a[3][3] ||
		a[i][j]==a[3][4] ||
		a[i][j]==a[3][7] ||
		a[i][j]==a[4][1] ||
		a[i][j]==a[4][2] ||
		a[i][j]==a[4][4] ||
		a[i][j]==a[4][6] ||
		a[i][j]==a[4][7] ||
		a[i][j]==a[5][1] ||
		a[i][j]==a[5][4] ||
		a[i][j]==a[5][5] ||
		a[i][j]==a[5][8] ||
		//
		a[i][j]==a[6][0] ||
		a[i][j]==a[6][1] ||
		a[i][j]==a[6][2] ||
		a[i][j]==a[6][3] ||
		a[i][j]==a[6][7] ||
		a[i][j]==a[7][2] ||
		a[i][j]==a[7][6] ||
		a[i][j]==a[7][7] ||
		a[i][j]==a[7][8] ||
		a[i][j]==a[8][5])
			{
				cout<<"Cannot change. It is predefined\n";
				
			} else {
				a[i][j]=x;
				cout<<"Done! "<<x<<"\n";
			}
			display();
		}
		void check(){
			for (int i = 0; i < 9; ++i) //check row
		        for (int j = 0; j < 9; ++j)
		        	for (int k = 0; k < 9; ++k)
		        		for (int l = 0; l < 9; ++l)
		        			if(a[i][j]==a[k][l]) //check this again!
				        	{
				        		cout<<"failed!"; 
				        		exit(0);
				        	}
			cout<<"success!";
		}
};

int main()
{
	sudoku player;
	int element;
	while(1){
		cout<<"Enter 0 to exit game!\n";
		cin>>element;
		if(element == 0) break;
		//cin>>element;
		player.initialWorld();
		player.display();
		while(1){
			cin>>element;
			if(element == 0) break;
			player.insert(element);
		}
		player.check();
	}
}