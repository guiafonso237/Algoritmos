#include <iostream>
using namespace std;

struct Camada{
  int numCamada;
  char letraCamada;
  int MAX_Camda;
  int possue;

  void imprime(){
    cout<<"numero da camada: "<<numCamada<<" letra do subnivel '"<<letraCamada<<"' e possue "<<possue<<" eletrons";
  }
};
int main() {
  int numAtoVar, ultimaCamadaPre=0, eletronsUltiCama;
  int numAtoEst;
  Camada distribuicao[18] = {{1, 's', 2}, {2, 's', 2}, {2, 'p', 6}, {3, 's', 2}, {3, 'p', 6}, {4, 's', 2}, {3, 'd', 10}, {4, 'p', 6}, {5, 's', 2}, {4, 'd', 10}, {5, 'p', 6}, {6, 's', 2}, {4, 'f', 14}, {5, 'd', 10}, {6, 'p', 6}, {7, 's', 2}, {5, 'f', 14}, {6, 'd', 10}};
  cout<<"Numero Atomico: ";
  cin>>numAtoVar;
  numAtoEst=numAtoVar;
  for(int i=0; i<18||numAtoVar==0; i++){
    if(numAtoVar-distribuicao[i].MAX_Camda<=0){
      distribuicao[i].possue=numAtoVar;
      break;
    }
    if(numAtoVar-distribuicao[i].MAX_Camda>0){
      distribuicao[i].possue = distribuicao[i].MAX_Camda;
      numAtoVar-=distribuicao[i].MAX_Camda;
      ultimaCamadaPre++;
    }
  }
  for(int i=0; i<=ultimaCamadaPre; i++){
    distribuicao[i].imprime();
    cout<<endl;
  }
}