#include <stdio.h>
#include <omp.h>

// gcc exampleOpenMP.c -o example -fopenmp
// .\example

// O código abaixo cria um vetor C de tamanho N que é o resultado da soma dos vetores A e B, estes sendo preenchidos com números de 1 a N, contando um por um
int main(){

    int amountThread; // Quantidade de threads
    int N = 80000; // Tamanho do vetor
    int loops; // Número de execuções

    printf("Escreva quantos loops e threads usar (Exemplo: 100000 12): ");
    scanf("%d %d", &loops, &amountThread);
    printf("\n");

    // Verifica se a quantidade de threads escolhida é coerente com o processador utilizado
    if(amountThread > omp_get_num_procs()){
        amountThread = omp_get_num_procs();
    }

    int i;
    int A[N], B[N], C[N];
    int numThread;
    double startTime, endTime, elapsedTime;

    // Preenche ambos os vetores de 0 a N adicionando um a cada posição do vetor
    for (i = 0; i < N; i++) {
        A[i] = i + 1;
        B[i] = i + 1;
    }

    // Define a quantidade de threads a ser utilizada
    omp_set_num_threads(amountThread);

    // Começa a contar o tempo para ver a duração do experimento
    startTime = omp_get_wtime();

    #pragma omp parallel private(numThread)
    {
        // Recupera o número da thread atual sendo utilizada
        numThread = omp_get_thread_num();

        // Variáveis de iteração para o laço for
        int start_k = 0;
        int end_k = loops;
        int start_j = (numThread * N) / amountThread;
        int end_j = ((numThread + 1) * N) / amountThread;

        // Laço for responsável por somar A[] e B[] ao vetor C, A e B sendo o mesmo número resultará em uma sequência múltipla de dois (2, 4, 6...)
        for (int k_iter = start_k; k_iter < end_k; k_iter++) {
            for (int j_iter = start_j; j_iter < end_j; j_iter++) {
                C[j_iter] = A[j_iter] + B[j_iter];
            }
        }
    }

    // Para de contar o tempo
    endTime = omp_get_wtime();
    elapsedTime = endTime - startTime;

    // Imprime informações sobre tudo
    printf("\nTAMANHO DO VETOR: %d\n", N);
    printf("LOOPS: %d\n", loops);
    printf("THREADS: %d\n", amountThread);
    printf("TEMPO DE EXECUCAO: %.5f seg\n", elapsedTime);

    return 0;
}
