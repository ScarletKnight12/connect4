#include<iostream>
#include<windows.h>
#include<string>
using namespace std;
 
class board
{
	int slots,i,j;
	char a[100][100];
	public:
		int row,col;
	    board(int x =4, int y =  4)
	    {
	    	row = x;
	    	col = y;
	    	for(i=0;i<100;i++)
	    	{
	    		for(j=0;j<100;j++)
	    		a[i][j]=' ';
			}
	    	
	    }
	    
	    void setSlots()
	    {
	    	//number of slots
	    	slots = row*col;
	    }
	    
	    int getSlots()
	    {
	    	return slots;
		}
 
	    void fill(int r, int c, char symbol) {
	    //fill slot for every player each turn
		
		a[r][c] = symbol; 
	    	for(i=0;i<row;i++) {
	    		cout<<"\t";
	    	for(j=0;j<col;j++) {
			cout<<a[i][j]<<"  ";
	        }
	    	cout<<"\n\n";
	       }
	    	
	    }
	    
	    
 
 
	};
	
    class player
	{
	public:
		int number,pos,col,totColumn;
		string name[100];
		char symbol[100];
		char ch;
	    player()
	    {
	        //constructor
	        for(int i=0;i<25;i++)
	        {
	        	name[i] = " ";
	        	symbol[i] = ' ';
 
	        }
	        number=1;
	       
	    }
 
	    void playerDetails()
	    {
	        //name 
	        //number of players
	        cout<<"\tNOte: max 25 players allowed\n"<<endl;
 
	        do{
	        	cout<<"Enter player name and symbol for player"<<number<<endl;
	        	cin>>name[number-1];
	        	cin>>symbol[number-1];
	        	cout<<"Any more players? y/n";
	        	cin>>ch;
	        	if(ch=='y')
	        	number++;
 
	        }while(ch!='n');
 
	        cout<<"\n";
	        //display details
	    	for(int i=0;i<number;i++)
	    	{
	    		cout<<name[i]<<" "<<symbol[i]<<endl;
	    	}
 
 
	    }
	    
	    char getSymbol(int plyr)
	    {
	    	return symbol[plyr];
		}
	    
	    int getNumber()
	    {
	    	return number;
		}
		
		
	    void turn(int t)
	    {
	        //current player as well as current coin
 
	        cout<<"\n Player "<<t+1<<" turn"<<endl;
	        cout<<"Select col position within "<<totColumn<<endl;
	        cin>>col;
	        
	        //system("cls");

	    }
	    
	    int setCol(int c)
	    {
	    	totColumn = c;
		}

	    int getCol()
	    {	
			return col;	        
	    }

	}; 
 
   /*
	class score: public player
	{
		void display()
	    {
	    	//if 4 connect from game, display winner
 
 
	    }
	    void final()
	    {
	        //if coins for both players are over (or) all slots are filled , no winner
	    }
 
	};
	
	*/
 

 
 /*
	class coins
	{
	    int i,coin,rem,slots;
	    int playerCoins[100];
	public:
	    coins()
	    {
	        //constructor
	        coin = 0;
	        rem = 0;
	        for(i=0;i<=100;i++)
	        playerCoins[i] = 0;
 
	        i=0;
 
	    }
 
 
	    void coinsPerPlayer()
	    {
	        //calculate total coins for each player
            slots = getSlots();
            number = getNumber();
            
	        coin = slots/number;
	        rem = slots%number;
 
	        while(rem!=0)
	        {
	        	 playerCoins[i]=coin+1;
	        	 rem--;
	        	 i++;
			}
 
 
 
 
	        //this keeps decreasing after every turn
	    }
 
 
 
	}; */
	
  
    class game
    {
    	int a[100][100],roow,cool;
    public:
    	game()
    	{
    		for(int i =0;i<100;i++)
    		for(int j = 0;j<100;j++)
    		a[i][j]=0;
    		
		}
    	
    
    	void nextPosition(int r,int c) //col specified by the player
    	{
    		
    		//gives the next possible positions where user can pick 
    	
    		while(r>=0)
			{
				if(a[r][c]!=1)
				{
					//fill it with symbol
					a[r][c] = 1;
					roow = r;
					break;
				}
				else
				r--;
			}
			
			
				
    	}
    	
    	int getRoow()
    	{
    		return roow;
		}
		
		
    	void check()
    	{
    		//if 4 of same coin connect, call display func nd stop game
    	}
 
 
    };
    
 
int main()
{
 
	 int row,col,slots,totPlayers,possibleRow,t=0,c,play=0;
	 char s = ' ';
	 //board
	 
	 cout<<"Enter board rows and column!"<<endl;
	 cin>>row>>col;
	 board b(row,col);
	 b.setSlots();
	 slots = b.getSlots();
	 cout<<slots<<endl;
	 
	 system("cls");
	 
	 //player
	 
	 player p;
	 p.setCol(col);
	 p.playerDetails();
	 totPlayers = p.getNumber();
	 
	 system("cls");
	 
	//game
	 
	 game g;
	 
	 while(play<=slots)
	 {
	 	
	 	t = play%totPlayers;
	 	cout<<"t="<<t<<endl;
	 	p.turn(t);
	 	c = p.getCol();
	 	
	 	g.nextPosition(row-1,c-1);
	 	
	 	possibleRow = g.getRoow();
	 	
	 	//cout<<"\n possibleROw "<<possibleRow;
	 	
	 	s = p.getSymbol(t);
	 	
	 	//cout<<"\n s = "<<s<<endl;
	 	
	 	
	 	b.fill(possibleRow,c-1,s);  //you need class game to find row and need player to get symbol!
	 	
	 	
	 	//
	 	//cin.get();
	 	//system("cls");		 
	 	
	 
	 	play++;
	 	
	 }
	 
	 
 }
