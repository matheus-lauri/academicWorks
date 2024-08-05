#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

static pthread_mutex_t usando_contagem = PTHREAD_MUTEX_INITIALIZER;

static int cont_itens = 0;
static int cont_peso = 0;

void *esteira1(void)
{
    while (1)
    {
        pthread_mutex_lock(&usando_contagem);
        cont_itens++;
        cont_peso += 5;
        pthread_mutex_unlock(&usando_contagem);
        usleep(2000000);
    }
}

void *esteira2(void)
{
    while (1)
    {
        pthread_mutex_lock(&usando_contagem);
        cont_itens++;
        cont_peso += 2;
        pthread_mutex_unlock(&usando_contagem);
        usleep(1000000);
    }
}

void *display(void)
{
    int aux = 0;
    int atualizacao = 0;
    while (1)
    {
        system("clear");
        printf("--MONITORAMENTO DA ESTEIRA--\n\n");
        pthread_mutex_lock(&usando_contagem);
        printf("Quantidade total de itens: %d\n", cont_itens);
        if (cont_itens >= atualizacao + 500)
        {
            aux = cont_peso;
            atualizacao += 500;
        }
        printf("Peso total: %d\n", aux);
        pthread_mutex_unlock(&usando_contagem);
        usleep(2000000);
    }
}

int main(void)
{
    struct timespec start_time, end_time;
    double total_time;

        // Cria as threads
    pthread_t thread_esteira1, thread_esteira2, thread_display;
    pthread_create(&thread_esteira1, NULL, (void *)esteira1, NULL);
    pthread_create(&thread_esteira2, NULL, (void *)esteira2, NULL);
    pthread_create(&thread_display, NULL, (void *)display, NULL);

    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // Aguarda o usuário pressionar 'q' para sair
    char ch;
    while (1)
    {
        ch = getchar();
        if (ch == 'q' || ch == 'Q')
        {
            break;
        }
    }

    // Para as threads
    pthread_cancel(thread_esteira1);
    pthread_cancel(thread_esteira2);
    pthread_cancel(thread_display);

    // Espera as threads terminarem
    pthread_join(thread_esteira1, NULL);
    pthread_join(thread_esteira2, NULL);
    pthread_join(thread_display, NULL);

    clock_gettime(CLOCK_MONOTONIC, &end_time);

    // Calcula o tempo total de execução
    total_time = (end_time.tv_sec - start_time.tv_sec) +
                 (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    printf("Tempo de execução: %.6f segundos\n", total_time);

    return 0;
}