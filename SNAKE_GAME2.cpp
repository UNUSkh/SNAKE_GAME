#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
const int weight=26;
const int hight=20;
bool lost;
int x,y,fruitx,fruity,urscore;
enum edirection{ null,lEFT,rIGHT,Up,Down};
edirection dim;
void setup_game()
{
    lost = false ;
    dim=null;
    x = 8 ;
    y = 10 ;
    fruitx = rand()%weight;
    fruity = rand()%hight;
    urscore=0;
}
int nb,tailX[100],taily[100];
void Drawing()
{
    system("cls");
        for(int i=0;i<weight+2;i++){
    cout<<"~";
}
cout<<endl;
        for(int i=0;i<hight;i++){
        	for(int j=0;j<weight;j++){
        		if(j==0) cout<<"|";
                if(i==y && j==x) {
                    cout<< "Q";
                }
                else if(i==fruity && j==fruitx)
                cout<<"*";
                else{
                    bool print=false;
                    for(int k=0;k<nb;k++){
                        if(tailX[k]==j && taily[k]==i)
                        {cout<<"o";
                        print=true;}
                    }
                    if(!print) cout<<" ";
                }

        		if(j==weight-1) cout<<"|";

			}
			cout<<endl;
		}
        for(int i=0;i<weight+2;i++){
    cout<<"~";
}
cout<<endl;
cout<<"you lost ,your score is "<<urscore<<endl;
}
void the_input()
{
    if(_kbhit()){
        switch (_getch())
        {
        case 'z' : dim=Up;
            break;
        case 's' : dim=Down;
            break;
        case 'd' : dim=rIGHT;
            break;
        case 'q' : dim=lEFT;
            break;
        case 'x' : lost=true;
            break;
        }
    }
}
void the_logic()
{
    int prex=tailX[0];
    int prey=taily[0];
    int prevx,prevy;
    tailX[0]=x;
    taily[0]=y;
    for(int i=1;i<nb;i++){
        prevx=tailX[i];
        prevy=taily[i];
        tailX[i]=prex;
        taily[i]=prey;
        prex=prevx;
        prey=prevy;
    }
  switch(dim){
    case lEFT : x--;break;
    case rIGHT : x++;break;
    case Up : y--;break;
    case Down : y++;break;
    default : break;
  }
  if(x>weight){
    x=x-weight;
  }
  if( x<0 ){
    x=x+weight;
  }
  if( y<0 ){
    y=y+hight;
  }
if( y>hight ){
    y=y-hight;
  }
  if(x==fruitx && y==fruity){
     urscore++;
     fruitx = rand()%weight;
     fruity = rand()%hight;
     nb++;
  }
  for(int i=1;i<nb;i++){
    if(tailX[i]==x && taily[i]==y) lost=true;
  }
}
int main()
{
    setup_game();
   while(!lost){
    Drawing();
    the_input();
    the_logic();
    Sleep(5);
   }
    return 0;
}
