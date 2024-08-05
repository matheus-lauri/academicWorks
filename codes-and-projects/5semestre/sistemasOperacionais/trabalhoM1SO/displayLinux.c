#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define SOCK_PATH_1 "/tmp/esteira1"
#define SOCK_PATH_2 "/tmp/esteira2"

void atualiza_display(int qtd, int kg)
{

    int aux = 0;
    int atualizacao = 0;

    printf("\033[H\033[J");
    printf("--MONITORAMENTO DAS ESTEIRAS--\n\n");
    printf("Quantidade total de itens: %d\n", qtd);
    if (qtd >= atualizacao + 500)
    {
        aux = kg;
        atualizacao += 500;
    }
    printf("Peso total: %d\n", aux);
}

int main()
{
    // Variáveis de contagem da esteira
    int qtd_anterior, kg_anterior, qtd_total, kg_total, qtd1 = 0, qtd2 = 0, kg1 = 0, kg2 = 0;

    // Variáveis dos sockets
    int sock_local1, sock_remoto1, sock_local2, sock_remoto2, len, estado_socket;
    ;
    struct sockaddr_un local1, remote1, local2, remote2;

    // Controle do imput do usuário para fechar a execução do código
    char ch;

    struct timespec start_time, end_time;
    double total_time;

    // Processo de criação e coneccao dos pipes
    sock_local1 = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock_local1 < 0)
    {
        perror("Falha em criar o pipe da esteira 1");
        return 1;
    }

    sock_local2 = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock_local2 < 0)
    {
        perror("Falha em criar o pipe da esteira 2");
        return 1;
    }

    clock_gettime(CLOCK_MONOTONIC, &start_time);

    memset(&local1, 0, sizeof(local1));
    local1.sun_family = AF_UNIX;
    strncpy(local1.sun_path, SOCK_PATH_1, sizeof(local1.sun_path) - 1);
    unlink(local1.sun_path);
    len = strlen(local1.sun_path) + sizeof(local1.sun_family);

    if (bind(sock_local1, (struct sockaddr *)&local1, len) < 0)
    {
        perror("Falha em capturar o socket da esteira 1");
        close(sock_local1);
        return 1;
    }

    memset(&local2, 0, sizeof(local2));
    local2.sun_family = AF_UNIX;
    strncpy(local2.sun_path, SOCK_PATH_2, sizeof(local2.sun_path) - 1);
    unlink(local2.sun_path);

    if (bind(sock_local2, (struct sockaddr *)&local2, len) < 0)
    {
        perror("Falha em capturar o socket da esteira 2");
        close(sock_local2);
        return 1;
    }

    if (listen(sock_local1, 2) < 0)
    {
        perror("Falha em escutar o socket da esteira 1");
        close(sock_local1);
        return 1;
    }

    if (listen(sock_local2, 2) < 0)
    {
        perror("Falha em escutar o socket da esteira 2");
        close(sock_local2);
        return 1;
    }

    printf("\n\nAguardadndo coneccao da esteira 1...\n");

    memset(&remote1, 0, sizeof(remote1));
    len = sizeof(remote1);
    sock_remoto1 = accept(sock_local1, (struct sockaddr *)&remote1, &len);
    if (sock_remoto1 < 0)
    {
        perror("Falha em aceitar coneccao");
        close(sock_local1);
        return 1;
    }

    printf("\n\nAguardadndo coneccao da esteira 2...\n");

    memset(&remote2, 0, sizeof(remote2));
    len = sizeof(remote2);
    sock_remoto2 = accept(sock_local2, (struct sockaddr *)&remote2, &len);
    if (sock_remoto2 < 0)
    {
        perror("Falha em aceitar coneccao");
        close(sock_local2);
        return 1;
    }

    int flags = fcntl(0, F_GETFL, 0);
    fcntl(0, F_SETFL, flags | O_NONBLOCK);

    fcntl(sock_remoto1, F_SETFL, O_NONBLOCK);
    fcntl(sock_remoto2, F_SETFL, O_NONBLOCK);

    while (1)
    {

        // Loop para capturar valores do socket até que ele esteja vazio
        // Intuito de descartar infomrações obsoletas da fila
        estado_socket = 1;

        while (estado_socket > 0)
        {
            estado_socket = recv(sock_remoto1, &qtd1, sizeof(qtd1), 0);
            estado_socket = recv(sock_remoto1, &kg1, sizeof(kg1), 0);
        }

        estado_socket = 1;
        while (estado_socket > 0)
        {
            estado_socket = recv(sock_remoto2, &qtd2, sizeof(qtd2), 0);
            estado_socket = recv(sock_remoto2, &kg2, sizeof(kg2), 0);
        }

        qtd_total = qtd1 + qtd2;
        kg_total = kg1 + kg2;

        // quantidade e kg total = informações mais recentes capturadas das esteiras.
        // quantidade e kg anterior = informações da ultima vez que o socket atualizou kg

        if (qtd_anterior / 500 != qtd_total / 500)
        {
            qtd_anterior = qtd_total;
            kg_anterior = kg_total;
        }
        atualiza_display(qtd_total, kg_anterior);

        // Encerramento do código
        ch = getchar();
        if (ch == 'q' || ch == 'Q')
        {
            close(sock_local1);
            close(sock_local2);
            close(sock_remoto1);
            close(sock_remoto2);

            clock_gettime(CLOCK_MONOTONIC, &end_time);

            // Calcula o tempo total de execução
            total_time = (end_time.tv_sec - start_time.tv_sec) +
                         (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

            printf("Tempo de execução: %.6f segundos\n", total_time);

            return 1;
        }

        usleep(2000000);
    }
}