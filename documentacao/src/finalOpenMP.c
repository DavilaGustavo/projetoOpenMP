#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 1000 // Define o tamanho maximo do vetor utilizado

// gcc finalOpenMP.c -o final -fopenmp
// .\final

// Funcao para organizar os numeros no vetor de forma crescente ou decrescente (QuickSort)
void quickSort(int num, int *vetor, int ascendente) {
    if (num <= 1)
        return;
    
    int x = vetor[0];
    int a = 1;
    int b = num - 1;
    do {
        if (ascendente) {
            while (a < num && vetor[a] <= x)
                a++;
            while (vetor[b] > x)
                b--;
        } else {
            while (a < num && vetor[a] >= x)
                a++;
            while (vetor[b] < x)
                b--;
        }
        if (a < b) {
            int aux = vetor[a];
            vetor[a] = vetor[b];
            vetor[b] = aux;
            a++;
            b--;
        }
    } while (a <= b);

    vetor[0] = vetor[b];
    vetor[b] = x;

    // Separacao da recursividade do quicksort utilizando de dois threads
    #pragma omp task
    quickSort(b, vetor, ascendente);
    #pragma omp task
    quickSort(num - a, &vetor[a], ascendente);
}

// Funcao para verificar se o valor escolhido equivale a um numero primo
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void comecaCaos(int loops, int numThreads) {
    int arrumae[N];

    // Utiliza a biblioteca openMP para dividir a tarefa de lotar o vetor arrumae com numeros aleatorios
    // dividindo essa tarefa para cada thread em tamanho igual, agilizando o processo
    // foi utilizado um mecanismo de loop para aumentar o custo computacional e dificultar o trabalho para o processador
    #pragma omp parallel num_threads(numThreads)
    {
        int numThread = omp_get_thread_num();

        // Separa o inicio e fim dos vetores de cada thread
        int start_i = (numThread * N) / numThreads;
        int end_i = ((numThread + 1) * N) / numThreads;

        printf("Thread: %d, start i: %d, end i: %d\n", numThread, start_i, end_i);

        for (int j = 0; j < loops; j++) {
            int num = 2;
            for (int i = start_i; i < end_i; i++) {
                while (!isPrime(num)) {
                    num++;
                }
                arrumae[i] = num;
                num++;
            }
        }

        // Sincronize todas as threads
        #pragma omp barrier
        
        // Executa o QuickSort com uma unica thread
        #pragma omp single
        quickSort(N, arrumae, 0); // Sendo zero para fazer o QuickSort ao contrario
    }
}

int main() {
    double startTime, endTime, elapsedTime; // Variaveis responsaveis para medir o tempo de execucao do programa
    int loops; // Define o numero de vezes que o loop sera executado
    int numThreads; // Define o numero de threads a ser utilizado no programa

    printf("Escreva quantos loops e threads usar (Exemplo: 10000 12): ");
    scanf("%d %d", &loops, &numThreads);
    printf("\n");

    if(numThreads > omp_get_num_procs())
    {
        numThreads = omp_get_num_procs();
    }

    omp_set_num_threads(numThreads);

    // Inicia a contagem do tempo de execucao
    startTime = omp_get_wtime();

    comecaCaos(loops, numThreads);

    // Termina a contagem do tempo de execucao
    endTime = omp_get_wtime();
    elapsedTime = endTime - startTime;

    printf("\nEXEC TIME: %.5f sec\n", elapsedTime);

    return 0;
}