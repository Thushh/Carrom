/**********************************************
Assignment       : Gaming project(Carrom)
Group no         : 19
Members          : S. Thushithan  (20/ENG/202)
                   A.N.A. Nusri   (20/ENG/192)
                   S. Poorvajaa   (20/ENG/103)
                   M.F.M. Azeem   (20/ENG/175)
                   S. Sithamparam (20/ENG/133)
Submission date  : 31/12/2021
************************************************/   



// Header files
#include<iostream>  		 // cout, cin
#include<stdlib.h> 			// random number gen
#include <windows.h> 		// WinAPIs
#include <conio.h> 			// get user input
#include<ctime>				// seeding time
#include<iomanip>			// setw, setfill
#include<math.h>			// abs()
#include<cstdio>
#include <stdio.h>


// Defining functions
void clearScreen();
void striker_1();  		// Printing player1's striker
void striker_2();  		// Printing player2's striker
void print(); 	   		// Function for printing
void arrowPoint();	    // Function for the '+' sign which indicates the direction
void strikerHit_1();	// Launching the player1's striker towards the direction 
void strikerHit_2();	// Launching the player2's striker towards the direction 
int collision_1();   	// Collision of the first striker
int collision_2();	 	// Collision of the second striker
int collision_coins();  // Collision between coins
void clearStriker_1();	// Clearing the striker
void clearStriker_2();	// Clearing the striker
int points1();			// Increasing the point of player 1
int points2();			// Increasing the point of player 2
void play();			// Function to implement the game
void instructions();	// Instructions
int gameover();			// Implement once after game is over
void enter();
void gotoxy();

void fullScreen();

#include "map.h" // Including an external coded file

	
	int x,y;
	int count=0;
	int points_1 =0 , points_2 = 0 ;
	char *strike, *strike_1; // Defining pointer variables
	
	char t   = 153; // Initializing to the character with ASCII code 154 i.e coin
	char t_1 = 111; // Initializing to the character with ASCII code 111 i.e striker
	char s = 245;
	char exi = 'm';

using namespace std;		//to avoid std::cout ,std::cin

int main(){
	
		clearScreen();
		
	//Declare variables
	bool IfInitial, IfHoriz, IfFromCheck, IfFromGame, IfFromPause;
	int iniStrikerX, iniStrikerY;
	
	enum SDirection { STAY = 0, A, D, W, S };
    SDirection dir;
       
	srand( (unsigned)time(NULL));

		
		
		

	do{
		system("cls");
    cout << "\t\t\t\t\t\t\t            ########          #        ##########   ##########    ########    ###       ###   	   "<< endl;
    cout << "\t\t\t\t\t\t\t           ##      ##        # #       ##      ##   ##      ##   ##      ##   ## #     # ##       "<< endl;
    cout << "\t\t\t\t\t\t\t          ##                ## ##      ##      ##   ##      ##  ##        ##  ##  #   #  ##  	   "<< endl;
    cout << "\t\t\t\t\t\t\t          ##               ##   ##     ##      ##   ##      ##  ##        ##  ##   # #   ## 	   "<< endl;
    cout << "\t\t\t\t\t\t\t          ##              #########    ##########   ##########  ##        ##  ##    #    ##        "<< endl;
    cout << "\t\t\t\t\t\t\t          ##             ##       ##   ##  ##       ##  ##      ##        ##  ##         ##        "<< endl;
    cout << "\t\t\t\t\t\t\t           ##      ##   ##         ##  ##    ##     ##    ##     ##      ##   ##         ##        "<< endl;   
    cout << "\t\t\t\t\t\t\t            ########   ##           ## ##      ##   ##      ##     #######    ##         ##   	   "<< endl;	
	cout << endl<<endl;
	cout<<"\n\n\t\t\t\t\t\t\t                                        Select option:   "<<endl;
	cout<<"\n\n\n\t\t\t\t\t\t\t                                1.  |S|T|A|R|T| |G|A|M|E|       "<<endl;
	cout<<"\n\n\n\t\t\t\t\t\t\t                                2. |I|N|S|T|R|U|C|T|I|O|N|S|      "<<endl;; 
	cout<<"\n\n\n\t\t\t\t\t\t\t                                3.         |Q|U|I|T|           "<<endl;
		
		
	char op = getch();

	if( op=='1')
	{
		system("cls");
		play();
		enter();
		
	}
	else if( op=='2') instructions();
	else if( op=='3') exit(0);
		

	}
	while(1);
	
 	 return 0; 	

}

void gotoxy(short x, short y)
{
	COORD pos{x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void play()
{
	 print(); // Printing the map
     
      do{
      	
	 striker_1(); 		// Setting the position of the striker
	 arrowPoint(); 		// Setting the position of the striker
	 strikerHit_1(); 	// Striker hitting the coin
	 collision_1(); 	// Collision between striker and coins
	 collision_coins(); // Collision between coins
	 clearStriker_1();  // Getting the striker to the inital position
	 points1();
	 
	 
	 striker_2(); 		 // Setting the position of the striker
	 arrowPoint();		 // Setting the position of the striker
	 strikerHit_2(); 	 // Striker hitting the coin
	 collision_1(); 	 // Collision between striker and coins
	 collision_coins();  // Collision between coins
	 clearStriker_2();   // Getting the striker to the inital position
	 points2();
	 
	 
	 //exi = getch();
	 
	 if( exi != 27){
	clearScreen();
    print(); // Printing 
    
    
    gotoxy(75, 3);cout << "Player 1 points = " << points_1 << endl;
    gotoxy(75, 4);cout << "Player 2 points = " << points_2 << endl;
    gameover();
}
 	}while(exi != 27)  	;
}


// Function to clear screen
void clearScreen(){
		COORD cursorPosition;
		cursorPosition.X = 0;
		cursorPosition.Y = 0;
		
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cursorPosition);
		
}


void instructions()
{
	system("cls");
	cout<<"\t\t\t\t\t\t                                                   |Instructions|                           ";
	cout<<"\n\t\t\t\t\t\t                                                  ----------------"                         ;
	cout<<"\n\n\t\t\t\t\t\t                                                  For the striker                             ";
	cout<<"\n\n\t\t\t\t\t\t                                                Press 'A' to move left                      ";
	cout<<"\n\t\t\t\t\t\t                                                Press 'D' to move right                     ";
	cout<<"\n\n\n\n\t\t\t\t\t\t                                               For the Direction(+ sign)                    ";
	cout<<"\n\n\t\t\t\t\t\t                                                Press 'A' to move left                      ";
	cout<<"\n\t\t\t\t\t\t                                                Press 'D' to move right                     ";
	cout<<"\n\t\t\t\t\t\t                                                Press 'W' to move up                        ";
	cout<<"\n\t\t\t\t\t\t                                                Press 'S' to move down                      ";
	cout<<"\n\n\t\t\t\t\t\t                                              Press Enter key once you set up the position                       ";
	cout<<"\n\n\n\t\t\t\t\t\t                                           Press any key to go back to menu.......         ";
	getch();
}

// Function which will be implemented once the game is over
int gameover()
{
	for(int i = 0; i < 23; i++){
		for (int j=0; j < 58; j++){
			if(map[i][j] == t)
				return 0;
		}
	}
	clearScreen();
	cout<<endl;
	cout<<"\t\t--------------------------"<<endl;
	cout<<"\t\t-------- Game Over -------"<<endl;
	cout<<"\t\t--------------------------"<<endl<<endl;
	
	
	if( points_1 > points_2)
		cout << "Player 1 has won the game" << endl;
	
	else if (points_1< points_2)
		cout << "Player 2 has won the game" << endl;
		
	else
		cout << "Game tied"<< endl;	
	
	
	cout<<"\t\tPress any key to go back to menu.";
	clearScreen();
}

void print(){
		for(int i =0; i<35; i++){

  			for(int j=0; j<60; j++){
    		cout << map[i][j];
 		 	}
  		cout << "\n";
		}
		enter();
}



void striker_1(){
	
	
	y=29;
	
	if(count >= 1)
	 y=28;
	 
	unsigned char disk;
	do{
 	
 	disk = getch();
 	// Moving the disk in the right side
 	if(disk == 'd' || disk == 'D' ){
			if( y > 1 && y < 54){
	 			map[21][y] = ' ';
		 		y+=1;
	 			map[21][y] = e;
 			}
 	clearScreen();
    print(); // Printing 	
 	}
 	
 	// Moving the disk in the left side
 	if(disk == 'a' || disk == 'A' ){
			if( y > 4 && y < 58){
		
	 			map[21][y] = ' ';
		 		y-=1;
	 			map[21][y] = e;
 			}
 	clearScreen(); // Clearing the screen
    print(); // Printing 	
 	}
 	
 	strike = &map[21][y];
 	count++;
 	
 }while( (disk == 'a' || disk == 'A' || disk == 'd' || disk == 'D') || disk !=13 );
   
}



void striker_2(){
	
	y=29;
	unsigned char disk;
	do{
 	
 	disk = getch();
 	// Moving the disk in the right side
 	if(disk == 'd' || disk == 'D' ){
			if( y > 1 && y < 54){
	 			map[2][y] = ' ';
		 		y+=1;
	 			map[2][y] = e;
 			}
 	clearScreen();
    print(); // Printing 	
 	}
 	
 	// Moving the disk in the left side
 	if(disk == 'a' || disk == 'A' ){
			if( y > 4 && y < 58){
		
	 			map[2][y] = ' ';
		 		y-=1;
	 			map[2][y] = e;
 			}
 	clearScreen(); // Clearing the screen
    print(); // Printing 	
 	}
 	
 	strike_1 = &map[2][y];
 	
 }while( (disk == 'a' || disk == 'A' || disk == 'd' || disk == 'D') || disk !=13 );
   
}


void arrowPoint(){
		
	y = 27;
	x = 9;
	char arrow;
 	int count = 0, var = 0;


	clearScreen();
	map[9][27] = '+'; // initializing the target

    print(); // Printing 
 do{

	//Moving the arrow
	 do{
 	
 	arrow = getch();
 	
 	
 		if( count == 1){
			var = 1;
			count = 0;
		}
	

	
 	// Moving the disk in the up direction
 	if(arrow == 'w' || arrow == 'W' ){
			if( x > 2 && x < 24){
		
				
		 		x = x - 1;
		 		if( map[x][y] == t ) 
					count =  1;
				
				
				if ( var == 1){
		 	    	map[x+1][y] = p;
		 		    map[x][y] = '+';
	 				var = 0 ;
				 }
				 
				else{
					map[x+1][y] = ' ';
					map[x][y] = '+';
						
					if( count == 1 )
					break;
					
				}
				
	 	
 			}
 	 clearScreen(); // Clearing the screen
 	 print(); // Printing 		
 	}
 	
 		// Moving the disk in the down direction
 	if(arrow == 's' || arrow == 'S' ){
				if( x > 1 && x < 21){
		
		
		 			x = x + 1;	
		 			if( map[x][y] == t  )
							count =  1;
				
						
							
							
		 			if ( var == 1){
		 				map[x-1][y] = p;
		 				map[x][y] = '+';
	 					var = 0 ;
				 	}
				 	
				 	else{	
						map[x-1][y] = ' ';
	 					map[x][y] = '+';
	 				
	 				if( count == 1 )
						break;
	 				
	 				 }
 			}
 	clearScreen(); // Clearing the screen
    print(); // Printing 		
 	}
 	
 	
 	
 	// Moving the arrow in the right side
 	if(arrow == 'd' || arrow == 'D' ){
			if( y > 1 && y < 56){
		
					y+=1;
					if(map[x][y] == t ){
					count = 1;
					}
				
	 				if ( var == 1){
	 					map[x][y] = '+';
	 					map[x][y-1] = p;
	 					var = 0 ;
					}
		 			
		 			else {
	 				map[x][y] = '+';
	 				map[x][y-1] = ' ';
	 				
	 				if( count == 1 )
						break;	
	 				}
 			}
 			
 	clearScreen();
 	print(); // Printing 	
 	}
 	

 	// Moving the disk in the left side
 	if(arrow == 'a' || arrow == 'A' ){
			if( y > 2 && y < 59){

				y-=1;
					
				if(map[x][y] == t )
					count = 1;
			
						
				
	 			if ( var == 1){
	 				map[x][y] = '+';
	 				map[x][y+1] = p;
	 				var = 0 ;
				}
		 			
		 		else {	
	 				map[x][y] = '+';
	 				map[x][y+1] = ' ';
	 				
	 				if( count == 1 )
						break;
	 			}
	 			
 			clearScreen(); // Clearing the screen
    		print(); // Printing 	
 			}
	}	
 	
	}while( (arrow  == 'a' || arrow  == 'A'|| arrow  == 'd' || arrow  == 'D'|| arrow  == 'w' || arrow  == 'W'||arrow  == 's' || arrow  == 'S') || arrow  != 13 );

	}while(count == 1 || var == 1);

}


void strikerHit_1(){
	for(int i =0; i < 35; i++){
		for(int j=0; j <60; j++){
			if( map[i][j] == '+'){
				map[i][j] = e;
				*strike = ' ';
			}
		}
	}
	clearScreen();
	print();
}

void strikerHit_2(){
	for(int i =0; i < 23; i++){
		for(int j=0; j <60; j++){
			if( map[i][j] == '+'){
				map[i][j] = e;
				*strike_1 = ' ';
			}
		}
	}
	clearScreen();
	print();
}

// collision between coins and the striker
int collision_1(){
	
	for(int i=3; i <35 ; i++){
		for(int j=0; j<60; j++){
			if( map[i][j] == t_1){
				
				// Position 1
				if(map[i+1][j-1] == t){
					if( ((i+4)< 11 && (i+4)> 2 && (j-4) < 2) || ((i+4)< 11 && (i+4)> 2 &&  (j-4) < 0) ){
						map[10][8] = t;
						map[i-2][j+2] = t_1;
					map[i][j] = ' ';
					map[i+1][j-1] = ' ';
					clearScreen();
					print();
					}
					
					else if(((i+4) > 11 && (j-4) < 2 && (i+4) < 21)  || ((i+4) > 11 && (j-4) < 0 && (i+4) < 21)  ){
						map[20][8] = t;
						map[i-2][j+2] = t_1;
					map[i][j] = ' ';
					map[i+1][j-1] = ' ';
					clearScreen();
					print();
					}
					
					else if((i+4) > 11 && (i+4) > 21 && (j-4) < 29  ){
						map[19][8]= t;
							map[i-2][j+2] = t_1;
					map[i][j] = ' ';
					map[i+1][j-1] = ' ';
					clearScreen();
					print();
					}
					
					else if(j-4 > 29 && (i+4) > 11 && (i+4) > 21  ){
						map[20][32]= t;
							map[i-2][j+2] = t_1;
					map[i][j] = ' ';
					map[i+1][j-1] = ' ';
					clearScreen();
					print();
					}
					
					else{
					map[i+4][j-4] = t;
					map[i-2][j+2] = t_1;
					map[i][j] = ' ';
					map[i+1][j-1] = ' ';
					clearScreen();
					print();
				}
				}
				
				
				// Position 2
				else if(map[i][j-1] == t){
					
					if((j-4) < 0 ||(j-4) < 2 ){
						
						if(i>2 && i < 22){					
						map[i][6] = t;
						map[i][j+2] = t_1;
					map[i][j] = ' ';
					map[i][j-1] = ' ';
					clearScreen();
					print();
						}
						
						else{
					map[i][j-4] = t;
					map[i][j+2] = t_1;
					map[i][j] = ' ';
					map[i][j-1] = ' ';
					clearScreen();
					print();
				}
						
						
					}
					
					else{
					map[i][j-4] = t;
					map[i][j+2] = t_1;
					map[i][j] = ' ';
					map[i][j-1] = ' ';
					clearScreen();
					print();
				}
					
				}
				
				// Position 3
				else if(map[i-1][j-1] == t){
					
					if(((i-4) < 11 && (j-4) < 2 && (i-4) > 2) ||( (i-4) < 11 && (j-4) < 0 && (i-4) > 2)  ){
						map[3][5] = t;
						map[i+2][j+2] = t_1;
					map[i][j] = ' ';
					map[i-1][j-1] = ' ';
					clearScreen();
					print();
						
					}
					
					else if(((i-4)<2 && (j-4) <29 &&(j-4) >4 ) || ( (i-4)<0 && (j-4) <29 &&(j-4) >4 ) ){
						map[3][7]= t;
						map[i+2][j+2] = t_1;
					map[i][j] = ' ';
					map[i-1][j-1] = ' ';
					clearScreen();
					print();
						
					}
					
					else if(((i-4) >11 && (j-4)< 2 && (i-4) < 21 ) || ((i-4) >11 && (j-4)< 0 && (i-4) < 21)) {
						map[14][5]=t;
						map[i+2][j+2] = t_1;
					map[i][j] = ' ';
					map[i-1][j-1] = ' ';
					clearScreen();
					print();
						
					}
					
					else if(((i-4) < 2 && (j-4) > 29 && (j-4) < 55 ) || ((i-4) <0 && (j-4)>29 && (j-4) < 55  ) ) {
						map[3][32]= t;
						map[i+2][j+2] = t_1;
					map[i][j] = ' ';
					map[i-1][j-1] = ' ';
					clearScreen();
					print();
						
					}
					
					
					else{
					map[i-4][j-4] = t;
					map[i+2][j+2] = t_1;
					map[i][j] = ' ';
					map[i-1][j-1] = ' ';
					clearScreen();
					print();
				}
					
				}
				
				
				// Position 4
				else if(map[i+1][j] == t){
					
					if( (i+4)> 20 || (i+4)> 23 )
					
					{
						if(j < 55 & j > 4)
						{
						
						map[20][j+1]=t;
						map[i-2][j] = t_1;
					map[i][j] = ' ';
					map[i+1][j] = ' ';
					clearScreen();
					print();
					}
					else{
					
					map[i+4][j] = t;
					map[i-2][j] = t_1;
					map[i][j] = ' ';
					map[i+1][j] = ' ';
					clearScreen();
					print();
					}	
					}
					
					else{
					
					map[i+4][j] = t;
					map[i-2][j] = t_1;
					map[i][j] = ' ';
					map[i+1][j] = ' ';
					clearScreen();
					print();
					}
					
				}
				
				// Position 5
				else if(map[i-1][j] == t){
					
					if((i-4) <3 || (i-4) < 0  ){
					if(j < 55 & j > 4){
						
						
						map[3][j+1] = t;
					map[i+2][j] = t_1;
					map[i][j] = ' ';
					map[i-1][j] = ' ';
					clearScreen();
					print();
					}	
					
					else{
					map[i-4][j] = t;
					map[i+2][j] = t_1;
					map[i][j] = ' ';
					map[i-1][j] = ' ';
					clearScreen();
					print();
					}
					
					}
					
					else{
					map[i-4][j] = t;
					map[i+2][j] = t_1;
					map[i][j] = ' ';
					map[i-1][j] = ' ';
					clearScreen();
					print();
					}
				}
				 
				
				
				// Position 6
				else if(map[i+1][j+1] == t){
					
					if( (i+4) > 20 && (j+4) < 29 && (j+4) > 4){
						map[19][25] = t;
						map[i-2][j-2] = t_1;
					map[i][j] = ' ';
					map[i+1][j+1] = ' ';
					clearScreen();
					print();
					}
					
					else if ( (i+4) > 20 && (j+4) >= 29 && (j+4) < 55){
					map[19][55] = t;
					map[i-2][j-2] = t_1;
					map[i][j] = ' ';
					map[i+1][j+1] = ' ';
					clearScreen();
					print();	
				}
				
				else if ( (i+4) > 11 && (i+4) < 22 && (j+4) > 56){
					map[17][55] = t;
					map[i-2][j-2] = t_1;
					map[i][j] = ' ';
					map[i+1][j+1] = ' ';
					clearScreen();
					print();
				}
				
				else if ( (i+4) < 11 && (i+4) > 2 && (j+4) > 56){
					map[9][55] = t;
					map[i-2][j-2] = t_1;
					map[i][j] = ' ';
					map[i+1][j+1] = ' ';
					clearScreen();
					print();
				}
				
				else{
					map[i+4][j+4] = t;
					map[i-2][j-2] = t_1;
					map[i][j] = ' ';
					map[i+1][j+1] = ' ';
					clearScreen();
					print();
				}
				
			}
				
				// Position 7
				else if(map[i][j+1] == t){
					
					if( (j+4) > 56){
						if( i >2 && i < 21)
					map[i+1][55] = t;
					map[i][j-2] = t_1;
					map[i][j] = ' ';
					map[i][j+1] = ' ';
					clearScreen();
					print();
					}
					
					else{
					
					map[i][j+4] = t;
					map[i][j-2] = t_1;
					map[i][j] = ' ';
					map[i][j+1] = ' ';
					clearScreen();
					print();
					}
				}
				
				
				else if(map[i-1][j+1] == t){
					
					if((i-4) > 11 && (i-4) < 21 && (j+4) > 56){
					map[14][53] = t;
					map[i+2][j-2] = t_1;
					map[i][j] = ' ';
					map[i-1][j+1] = ' ';
					clearScreen();
					print();
					}
					
					else if((i-4) < 11 && (i-4) > 2 && (j+4) > 56){
					map[6][53] = t;
					map[i+2][j-2] = t_1;
					map[i][j] = ' ';
					map[i-1][j+1] = ' ';
					clearScreen();
					print();
					}
					
					else if((i-4) < 3 && (j+4) >= 29 && (j+4) < 56){
					map[5][52] = t;
					map[i+2][j-2] = t_1;
					map[i][j] = ' ';
					map[i-1][j+1] = ' ';
					clearScreen();
					print();
					}
					
					else if((i-4) < 3 && (j+4) < 29  && (j+4) > 3){
					map[5][25] = t;
					map[i+2][j-2] = t_1;
					map[i][j] = ' ';
					map[i-1][j+1] = ' ';
					clearScreen();
					print();
					}
					
					
					
					else{
					
					map[i-4][j+4] = t;
					map[i+2][j-2] = t_1;
					map[i][j] = ' ';
					map[i-1][j+1] = ' ';
					clearScreen();
					print();
					}
				}
				
				else
					return 0;
				
				
			}
		}
	}
	
	
}
// collision between coins
int collision_coins(){
		for(int i=0; i <35 ; i++){
		for(int j=0; j<60; j++){
			if( map[i][j] == t){
				if(map[i+1][j-1] == t){
					map[i+4][j-4] = t;
					map[i-2][j+2] = t;
					map[i][j] = ' ';
					map[i+1][j-1] = ' ';
					clearScreen();
					print();
					collision_coins();
					
				
				}
				
				else if(map[i][j-1] == t){
				
					map[i][j-5] = t;
					map[i][j+2] = t;
					map[i][j] = ' ';
					map[i][j-1] = ' ';
					clearScreen();
					print();
					collision_coins();
					
				}
				
				else if(map[i-1][j-1] == t){
						
					map[i-4][j-4] = t;
					map[i+2][j+2] = t;
					map[i][j] = ' ';
					map[i-1][j-1] = ' ';
					clearScreen();
					print();
					collision_coins();
					
				}
				
				else if(map[i+1][j] == t){
						
					map[i+4][j] = t;
					map[i-2][j] = t;
					map[i][j] = ' ';
					map[i+1][j] = ' ';
					clearScreen();
					print();
					collision_coins();
					
				}
				
				else if(map[i-1][j] == t){
					
					map[i-4][j] = t;
					map[i+2][j] = t;
					map[i][j] = ' ';
					map[i-1][j] = ' ';
					clearScreen();
					print();
					collision_coins();
					
				}
				
				else if(map[i+1][j+1] == t){
						
					map[i+4][j+4] = t;
					map[i-2][j-2] = t;
					map[i][j] = ' ';
					map[i+1][j+1] = ' ';
					clearScreen();
					print();
					collision_coins();
					
				}
				
				else if(map[i][j+1] == t){
					
					map[i][j+4] = t;
					map[i][j-2] = t;
					map[i][j] = ' ';
					map[i][j+1] = ' ';
					clearScreen();
					print();
					collision_coins();
					
				}
				
				else if(map[i-1][j+1] == t){

					map[i-4][j+4] = t;
					map[i+2][j-2] = t;
					map[i][j] = ' ';
					map[i-1][j+1] = ' ';
					clearScreen();
					print();
					collision_coins();
					
				}
				
				else
					return 0;
				
			}
		}
	}
	//collision_coins();
}


// Clearing the striker
void clearStriker_1(){
	
	for( int i =1; i<24; i++ ){
		for(int j = 0; j<59; j++){
			if( i == 2 && j == 29)
				continue;
			if(map[i][j] == t_1){
				map[i][j] = ' ';
				map[21][28]= t_1;
				clearScreen();
				print();
			}
		}
	}
}

// Clearing the striker
void clearStriker_2(){
	
	for( int i =2; i<21; i++ ){
		for(int j = 0; j<59; j++){
			if(map[i][j] == t_1){
				map[i][j] = ' ';
				map[2][29]= t_1;
				clearScreen();
					print();
			}
		}
	}
}

// Increasing points for player 1
int points1() {
	
		for( int i=0; i<2; i++){
			for (int j=0; j < 5; j++){
				if(map[i][j] == t){
					map[i][j] = ' ';
					points_1++;
					return points_1;
		}
	}
}

		for( int i=0; i<2; i++){
			for (int j=54; j <59; j++){
				if(map[i][j] == t){
					map[i][j] = ' ';
					points_1++;
					return points_1;
		}
	}
}

		for( int i=22; i<24; i++){
			for (int j=0; j <5; j++){
				if(map[i][j] == t){
					map[i][j] = ' ';
					points_1++;
					return points_1;
		}
	}
}

		for( int i=22; i<24; i++){
			for (int j=54; j <59; j++){
				if(map[i][j] == t){
					map[i][j] = ' ';
					points_1++;
					return points_1;
		}
	}
}


}


int points2() {
	
		for( int i=0; i<2; i++){
			for (int j=0; j < 5; j++){
				if(map[i][j] == t){
					map[i][j] = ' ';
					points_2++;
					return points_2;
		}
	}
}

		for( int i=0; i<2; i++){
			for (int j=54; j <59; j++){
				if(map[i][j] == t){
					map[i][j] = ' ';
					points_2++;
					return points_2;
		}
	}
}

		for( int i=22; i<24; i++){
			for (int j=0; j <5; j++){
				if(map[i][j] == t){
					map[i][j] = ' ';
					points_2++;
					return points_2;
		}
	}
}

		for( int i=22; i<24; i++){
			for (int j=54; j <59; j++){
				if(map[i][j] == t){
					map[i][j] = ' ';
					points_2++;
					return points_2;
		}
	}
}


}

void enter()
{	
	gotoxy(75, 1);cout<<"     Press enter key to fix the position ::  keep the + sign around the coin "<<endl;
	 
}


