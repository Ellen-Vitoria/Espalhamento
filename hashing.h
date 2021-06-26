#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED
#define W 3

//Nesse caso, como a lista vai ser de inteiros, ent�o n�o precisa de template
struct Node{
    int info;
    Node *prox;
};

struct Hash{
    Node *h[W]; //h equivale a lista toda; W � uma constante

    Hash(){
        for (int i=0; i<W; i++){
            h[i] = NULL; //Cada lista do Todo
        }
    }

    int fht(int x){
        return x % W; //Para saber qual lista o N�mero ir� ser armazenado
    }

    bool listaVazia(int lista){
        return h[lista] == NULL;
    }

    void inserir(int x){
        Node *aux2; //Nesse n�o h� "= new Node", pois s� foi declarado para apontar
        Node *aux = new Node; //Alocando espa�o de mem�ria
        aux->info = x;
        int p = fht(x); //Qual Lista
        //A Lista est� Vazia ou N�mero � menor que a Cabe�a da Lista
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
            //Se Lista � vazia ou se N�mero a ser removido � menor ao Elemento que est� na Cabe�a da Lista
            if (h[i] == NULL || x < h[i]->info){
                continue;
            }
            else{
                //Se N�mero a ser removido � igual ao elemento da Cabe�a da Lista
                if(x == h[i]->info){
                    Node *aux = h[i];
                    h[i] = h[i]->prox; //O pr�ximo Valor se torna a Cabe�a da Lista
                    delete aux;
                    return true;
                }

                Node *aux = h[i];

                //Enquanto pr�ximo Elemento n�o for NULL e N�mero for maior que ele
                while (aux->prox != NULL && x > aux->prox->info){
                    aux = aux->prox;
                }

                //Se o pr�ximo Elemento para o qual o aux atual est� apontando � NULL ou se � diferente de N�mero a ser removido
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
