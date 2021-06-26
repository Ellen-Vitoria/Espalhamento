#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED
#define W 3

//Nesse caso, como a lista vai ser de inteiros, então não precisa de template
struct Node{
    int info;
    Node *prox;
};

struct Hash{
    Node *h[W]; //h equivale a lista toda; W é uma constante

    Hash(){
        for (int i=0; i<W; i++){
            h[i] = NULL; //Cada lista do Todo
        }
    }

    int fht(int x){
        return x % W; //Para saber qual lista o Número irá ser armazenado
    }

    bool listaVazia(int lista){
        return h[lista] == NULL;
    }

    void inserir(int x){
        Node *aux2; //Nesse não há "= new Node", pois só foi declarado para apontar
        Node *aux = new Node; //Alocando espaço de memória
        aux->info = x;
        int p = fht(x); //Qual Lista
        //A Lista está Vazia ou Número é menor que a Cabeça da Lista
        if(h[p] == NULL || x <= h[p]->info){
            aux->prox = h[p];
            h[p] = aux;
        }
        else{
            aux2 = h[p]; //Apontando para h[p]
            while(aux2->prox != NULL && x> aux2->prox->info){
                aux2 = aux2->prox;
            }
            aux->prox = aux2->prox;
            aux2->prox = aux;
        }
    }

    int buscarElemento(int x){
        Node *aux;

        for(int i=0; i<W; i++){
            aux = h[i];
            while(aux != NULL){
                if(x == aux->info){
                    return i;
                }
                aux = aux->prox;
            }
        }
        return -1;
    }

    bool remover(int x){
        for(int i=0; i<W; i++){
            //Se Lista é vazia ou se Número a ser removido é menor ao Elemento que está na Cabeça da Lista
            if (h[i] == NULL || x < h[i]->info){
                continue;
            }
            else{
                //Se Número a ser removido é igual ao elemento da Cabeça da Lista
                if(x == h[i]->info){
                    Node *aux = h[i];
                    h[i] = h[i]->prox; //O próximo Valor se torna a Cabeça da Lista
                    delete aux;
                    return true;
                }

                Node *aux = h[i];

                //Enquanto próximo Elemento não for NULL e Número for maior que ele
                while (aux->prox != NULL && x > aux->prox->info){
                    aux = aux->prox;
                }

                //Se o próximo Elemento para o qual o aux atual está apontando é NULL ou se é diferente de Número a ser removido
                if (aux->prox == NULL || aux->prox->info != x){
                    continue;
                }
                else{
                    Node *aux2 = aux->prox;
                    aux->prox = aux->prox->prox;
                    delete aux2;
                    return true;
                }
            }
        }
        return false;
    }

};
#endif // HASHING_H_INCLUDED
