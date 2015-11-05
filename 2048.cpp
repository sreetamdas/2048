#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
class Game_2048
{
	int a[5][5];
public:
	Game_2048()
	{
		for(int i = 0; i < 5; i++)
			for(int j = 0; j< 5; j++)
				a[i][j] = 0;
	}
	void CheckWin();				// Check for 2048   
	void Move( int );				// Shift tiles
	void Display();					// Display
	void Fill();					// Fill '2'  in random spot
	void gamePlay();
};

void Game_2048::CheckWin()			// Done
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j< 4; j++)
		{
			if ( a[i][j] == 2048 )
			{
				cout << "You WIN!!!\n";
				exit(0);
			}
		}
}

void Game_2048::Display()			// Done
{
	cout<<"\t--------------------------\n";
	for(int i = 0; i < 4; i++)
	{	
		cout<<"\n\n\n\t\t";
		for(int j = 0; j< 4; j++)
		{
				cout << a[i][j] << "	";
		}
		cout << "\n\n\t\t";
	}
}

void Game_2048::Fill()				// Done
{
	srand(time(NULL));
	int x, y;

	again:

	x = rand() % 4;
	y = rand() % 4;

	if( a[x][y]!= 0 )
		goto again;

	a[x][y] = 2;
	cout<<" filled at ("<<++x<<","<<++y<<") ";

}

void Game_2048::Move( int x )
{
	int k;

	wrong:
	switch (x)
	{
		case 4:
			for(int i = 0; i < 4; i++)
			{
				int count = 0;

				for (int x = 0; x < 4 ; ++x)
				{
	
					if( a[i][x] )
						a[i][count++] = a[i][x];
				}

				while(count < 4)
					a[i][count++] = 0;		

				for(int j = 0; j < 4; j++)
				{
					if(a[i][j] == a[i][j+1])				// If same, then Add up
					{
						a[i][j] *= 2;
						for(int k = j+1; k < 3; k++)
						{
							a[i][k] = a[i][k+1];
						}
						a[i][3] = 0;
					}
					
				}
			}
			break;
		case 6:
			for(int i = 0; i < 4; i++)
			{
				int count = 3;

				for (int x = 3; x >= 0 ; --x)
				{
	
					if( a[i][x] )
						a[i][count--] = a[i][x];
				}

				while(count >= 0)
					a[i][count--] = 0;		

				for(int j = 3; j >= 0; j--)
				{
					if(a[i][j] == a[i][j-1])				// If same, then Add up
					{
						a[i][j] *= 2;
						for(int k = j-1; k > 0; k--)
						{
							a[i][k] = a[i][k-1];
						}
						a[i][0] = 0;
					}
					
				}
			}
			break;
		
		case 8:
			for(int i = 0; i < 4; i++)
			{
				int count = 0;

				for (int x = 0; x < 4 ; ++x)
				{
	
					if( a[x][i] )
						a[count++][i] = a[x][i];
				}

				while(count < 4)
					a[count++][i] = 0;		

				for(int j = 0; j < 4; j++)
				{
					if(a[j][i] == a[j+1][i])				// If same, then Add up
					{
						a[j][i] *= 2;
						for(int k = j+1; k < 3; k++)
						{
							a[k][i] = a[k+1][i];
						}
						a[3][i] = 0;
					}
					
				}
			}
			break;
		case 2:
			for(int i = 0; i < 4; i++)
			{
				int count = 3;

				for (int x = 3; x >= 0 ; --x)
				{
	
					if( a[x][i] )
						a[count--][i] = a[x][i];
				}

				while(count >= 0)
					a[count--][i] = 0;		

				for(int j = 3; j >= 0; j--)
				{
					if(a[j][i] == a[j-1][i])				// If same, then Add up
					{
						a[j][i] *= 2;
						for(int k = j-1; k > 0; k--)
						{
							a[k][i] = a[k-1][i];
						}
						a[0][i] = 0;
					}
					
				}
			}
			break;
		default:
			cout<<"\n\n\t\tWrong move entered! No Worries, Try again. \n";
			cin>>x;
			goto wrong;
	
		
	}
}

void Game_2048::gamePlay()
{
	cout<<"\n\n\t\tEnter your moves using keypad.\n";
	int x;
	do
	{
		CheckWin();
		cin >> x;
		Move(x);		
		Fill();
		Display();
	}
	while(x);
}
int main()
{
	Game_2048 Game;
	Game.gamePlay();
}
