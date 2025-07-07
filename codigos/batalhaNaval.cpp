#include <iostream>
#include <random>
#include <cstdlib>
#include <unistd.h>
using namespace std;

short nav, k=0;

struct Casas{
  char cont=' ';
  bool tem=0, tiro=0;
  int tipNav, cas;
};

void most(int);
void gerarNav(short);
void atk();
bool endG(int , int);

Casas cas[8][8];

int main() {
  short dif, tent, jog=0, opa=0;
  cout<<"Digite a dificuldade\nFacil - 0\nMedio - 1\nDificil - 2\n";
  cin>>dif;
  switch (dif){
    case 0: nav=5; tent=40;
      cout<<"Voce escolheu o modo facil: voce tem: "<<tent<<" tentativas e "<<nav<<" navios\n";
    break;
    case 1: nav=11; tent=35;
      cout<<"Voce escolheu o modo Medio: voce tem: "<<tent<<" tentativas e "<<nav<<" navios\n";
    break;
    case 2: nav=18; tent=30;
      cout<<"Voce escolheu o modo Dificil: voce tem: "<<tent<<" tentativas e "<<nav<<" navios\n";
    break;
    default: nav=40; tent=1;
    cout<<"Como voce escolheu um numero diferente voce sofrera\n";
  }
  sleep(2);
  gerarNav(nav);
  do{
    system("clear");
    most(tent-jog);
    atk();
    jog++;
    if(endG(tent-jog, nav-k)){
      cout<<"\nVoce Perdeu!!!\n";
      return 0;
    }
    if(nav-k==0){
      cout<<"\nVoce venceu!!!\n";
      return 0;
    }
  }while(jog<=tent); 
} 

void most(int tent){

  cout<<"tentativas: "<<tent<<endl<<"navios restantes: "<<nav-k<<endl<<endl<<endl;
  for(int i=0; i<8; i++){
    for(int o=0; o<8; o++){
      cout<<"|";
      cout<<cas[i][o].cont;
      if(o==7){
        cout<<"|";
      }
     }cout<<endl;
    if(i!=7){
      cout<<"-----------------\n";
    }
   }
  cout<<"\n";
}

void gerarNav(short n){
  int h=1;
  while(h<=n){
    int xV, yV;
    random_device rd1, rd2;
    mt19937 x(rd1());
    mt19937 y(rd2());
    uniform_int_distribution<int>dist1(0, 7);
    uniform_int_distribution<int>dist2(0, 7);
  
    xV = dist1(x);
    yV = dist2(y);
  
    for(int i=0; i<8; i++){
      for(int o=0; o<8; o++){
        if(xV==i && yV==o){
          cas[i][o].cont=' ';
          cas[i][o].tem=1;
        }
      } 
    }
    h++;
  }
}

void atk(){
  int x, y;
  cout<<"Digite o valor de Y: ";
  cin>>x;
  cout<<"Digite o valor de X: ";
  cin>>y;

  if(cas[x][y].tem==1){
    k+=1;
    cout<<"\nMatou\n";
    cas[x][y].tem=0;
    cas[x][y].cont='1';
    cas[x][y].tiro=1;
    sleep(2);
  }else{
    cas[x][y].cont='0';
  }
  if(x!=7&&cas[x+1][y].tem==1){
    cas[x+1][y].cont='@';
  }
  if(x!=0&&cas[x-1][y].tem==1){
    cas[x-1][y].cont='@';
  }
  if(y!=7&&cas[x][y+1].tem==1){
    cas[x][y+1].cont='@';
  }
  if(y!=0&&cas[x][y-1].tem==1){
    cas[x][y-1].cont='@';
  }
}

bool endG(int tent, int jog){
  if(tent==0){
    return 1;
  } else if(nav-k==0){
    return 1;
  }
  
  return 0;
}