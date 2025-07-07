#include <iostream>
#include <stdlib.h>
using namespace std;

void inicio();
void mostrarJogo();
void mostrarTabu();
void esc(int, char);
int venc();

struct Case{
int val = 0;
char let = ' ';
int cas;
int tem = 0;
};

Case casa[3][3];

int main() {
  int cho, vence;
  bool acab = false;
  char ti = 'X';
  inicio();
  do{
    mostrarJogo();
    cout<<endl<<"------------------"<<endl;
    mostrarTabu();
    cout<<"\n\nVez da "<<ti<<"\nEscolha o numero correspondente a casa desejada: ";
    cin>>cho;
    esc(cho, ti);
    if(ti == 'X'){
      ti = 'O';
    }else{
      ti = 'X';
    }
    system("clear");
    vence = venc();
    if(vence==1){
      acab = true;
      cout<<"X eh o vencedor";
    }
    if(vence==-1){
      acab = true;
      cout<<"O eh o vencedor";
    }
    if(vence==10){
      acab = true;
      cout<<"Deu empate";
    }
  }while(acab==false);
}

void inicio(){
  int vez = 1;
  for(int i=0; i<3; i++){
    for(int o =0; o<3; o++){
      casa[i][o].cas = vez;
      vez++;
    }
  }
}

void mostrarJogo(){
  for(int i=0; i<3; i++){
    for(int o =0; o<3; o++){
      cout << casa[i][o].let;
      if(o!=2){
        cout<<"|";
      }
    }
    if(i!=2){
      cout<<"\n-----"<<endl;
    }
  }
}

void mostrarTabu(){
  for(int i=0; i<3; i++){
    for(int o =0; o<3; o++){
      if(casa[i][o].val==0){
        cout << casa[i][o].cas;
      }else{
        cout<<" ";
      }
      if(o!=2){
        cout<<"|";
      }
    }
    if(i!=2){
      cout<<"\n-----"<<endl;
    }
  }
}

void esc(int esc, char time){
  for(int i=0; i<3; i++){
      for(int o=0; o<3; o++){
        if(casa[i][o].cas==esc){
          casa[i][o].let = time;
        }
        if(casa[i][o].let == 'X'){
          casa[i][o].val = 1;
          casa[i][o].tem = 1;
        }
        if(casa[i][o].let == 'O'){
          casa[i][o].val = -1;
          casa[i][o].tem = 1;
        }
      }
    }
}

int venc(){
  int dP=0, dS=0, col=0, lin=0, venc=0, tem=0;
  for(int i=0; i<3; i++){
    for(int o=0; o<3; o++){
      lin+=casa[i][o].val;
      col+=casa[o][i].val;
      if(i==o){
        dP+=casa[i][o].val;
      }
      if(i+o==2){
        dS+=casa[i][o].val;
      }
    }
    //linha
    if(lin==3){
      return 1;
    }
    if(lin==-3){
      return -1;
    }
    lin=0;
    //coluna
    if(col==3){
      return 1;
    }
    if(col==-3){
      return -1;
    }
    col=0;
  }
  //dP
     if(dP==3){
      return 1;
    }
    if(dP==-3){
      return -1;
    }
    dP=0;
  //dS
  if(dS==3){
      return 1;
    }
    if(dS==-3){
      return -1;
    }
    dS=0;
  for(int i=0; i<3; i++){
    for(int o=0; o<3; o++){
      tem+=casa[i][o].tem;
    }
  }
  if(tem==9){
    return 10;
  }
  return 0;
}