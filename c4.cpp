#include<iostream>
#include<windows.h>
#include<string>
using namespace std;
 
class board
{
	int slots;
	public:
		int row,col;
	    board(int x =4, int y =  4)
	    {
	    	row = x;
	    	col = y;
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
 
	    void fill()
	    {
	    	//fill slot for every player each turn 
	    	
	    	
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
	        	cout<<"Enter player name and symbol for player"<<number+1<<endl;
	        	cin>>name[number];
	        	cin>>symbol[number];
	        	cout<<"Any more players? y/n";
	        	cin>>ch;
	        	if(ch=='y')
	        	number++;
 
	        }while(ch!='n');
 
	        cout<<"\n";
	        //display details
	    	for(int i=0;i<=number;i++)
	    	{
	    		cout<<name[i]<<" "<<symbol[i]<<endl;
	    	}
 
 
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
	        
	        system("cls");

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
	
  /*
    class game
    {
    	int c,r;
    public:
    	game()
    	{
    		r=4;
		}
    	int a[100][100];
    	void setPos()
    		{
    			c=getPos();
			}
    	void nextPosition()
    	{
    		//gives the next possible positions where user can pick 
    		while(r>=0)
			{
				if(a[r][c]!=1)
				{
					//fill it with symbol
					a[r][c] == 1;
					break;
				}
				else
				r--;
			}
			
			
				
    	}
 
    	void check()
    	{
    		//if 4 of same coin connect, call display func nd stop game
    	}
 
 
    };
      */
 
int main()
{
 
	 int row,col,slots,totPlayers,t,c,play=0;
	 
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
	 p.playerDetails();
	 totPlayers = p.getNumber();
	 system("cls");
	 
	 p.setCol(col);
	 
	 while(play<=slots)
	 {
	 	
	 	t = play%totPlayers;
	 	p.turn(t);
	 	c = p.getCol();
	 	
	 	//
	 	
	 			 
		  
	 	
	 	
	 	
	 	cout<<c;
	 	play++;
	 	
	 }
	 
	 
 }
