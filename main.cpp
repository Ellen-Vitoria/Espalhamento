#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include "hashing.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Hash dh;
    int opc, num;


    //Menu
    do{
        cout<< "\n\t        #                               #" <<endl;
        cout<< "\t        #  T A B E L A   H A S H I N G  #" <<endl;
        cout<< "\t ###############################################" <<endl;
        cout<< "\t        #  1 - Inserir um Novo Número   #" <<endl;
        cout<< "\t        #  2 - Buscar um Elemento       #" <<endl;
        cout<< "\t        #  3 - Remover um Elemento      #" <<endl;
        cout<< "\t        #  4 - Exibir a Tabela Hashing  #" <<endl;
        cout<< "\t ###############################################" <<endl;
        cout<< "\t        #  5 - Fim                      #\n\t        #                               #\n" <<endl;
        cout<< "\n\t Selecione: ";
        cin>> opc;

        system("cls");

        cout<< "\n\t        #                               #\n\t        #  T A B E L A   H A S H I N G  #\n\t ###############################################\n\n" <<endl;

        switch(opc){
            //Inserir um Número na Lista
            case 1:
                cout<< "\t    Número: ";
                cin>> num;
                dh.inserir(num);
                break;

            //Buscar um Elemento
            case 2:
                cout<< "\t    Número: ";
                cin>> num;

                if(dh.buscarElemento(num) != -1){
                    int lista = dh.buscarElemento(num);
                    cout<< "\n\t    h[" <<lista<<"]-> " <<num;
                }
                else
                {
                    cout<< "\t    Elemento Não Encontrado!";
                }
                break;

            //Remover um Elemento
            case 3:
                cout<< "\t   Número: ";
                cin>> num;

                if(dh.remover(num)){
                    cout<< "\n\t   Elemento Removido! ";
                }
                else{
                    cout<< "\t   Elemento Não Encontrado! ";
                }
                break;

            //Exibir Tabela
            case 4:
                for(int i=0; i<W; i++){
                    if(dh.listaVazia(i)){
                        cout<< "\t    h[" <<i<<"]-> ..........................." <<endl;
                    }
                    else{
                        Node *aux = dh.h[i];
                        cout<< "\t    h[" <<i<<"]-> ";
                        while(aux != NULL){
                            cout<< aux->info <<"-> ";
                            aux = aux->prox;
                        }
                        cout<<endl;
                    }
                }
                break;

            //Fim
            case 5:
                cout<< "\t    Fim........................\n\n\t ";
                return 0;
                break;

            //Se for digitado outro Valor
            default:
                continue;
                break;
        }
        cout<< "\n\n\t ";
        system("pause");
        system("cls");
    }
    while(opc != 5);
}
