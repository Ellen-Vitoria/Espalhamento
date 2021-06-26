# Espalhamento

Espalhamento (ou Hashing) é uma técnica usada para armazenamento e pesquisa de informações sem requerer ordenação. Para o programa, é considerado uma tabela que é a
estrutura de dados que implementa o espalhamento, representada por um vetor h[W], onde h equivale a toda tabela, enquanto W é uma constante que diz a quantidade de listas que haverá nessa tabela (cada lista vai ser um ponteiro que apontará para o valor armazenado a ele).
Considerando apenas números inteiros, para definir em qual lista um determinado valor vai ser armazenado, é feito uma divisão desse valor pelo W e o resto da divisão é o índice da lista.

Opções do menu:
    1 - Inserir um novo número;
    2 - Buscar um elemento;
    3 - Remover um elemento;
    4 - Exibir a tabela hashing;
    5 - Fim.
