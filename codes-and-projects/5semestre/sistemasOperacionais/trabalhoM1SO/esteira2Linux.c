//Servidor pipe (testado usando WSL)
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define SOCK_PATH "/tmp/esteira2"

int main()
{
    int sock, len;
    struct sockaddr_un remote;

    char ch;

    struct timespec start_time, end_time;
    double total_time;

    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // coneccao do socket
    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("Falha em criar o socket");
        return 1;
    }

    printf("Conectando ao display...\n");

    memset(&remote, 0, sizeof(remote));
    remote.sun_family = AF_UNIX;
    strncpy(remote.sun_path, SOCK_PATH, sizeof(remote.sun_path) - 1);
    len = strlen(remote.sun_path) + sizeof(remote.sun_family);
    if (connect(sock, (struct sockaddr *)&remote, len) < 0)
    {
        perror("Falha em conectar ao display");
        close(sock);
        return 1;
    }

    int flags = fcntl(0, F_GETFL, 0);
    fcntl(0, F_SETFL, flags | O_NONBLOCK);
    fcntl(sock, F_SETFL, O_NONBLOCK);

    //Loop de contagem e envio das informações

    int qtd = 0, kg = 0;
    while(1){
        
        qtd++;
        kg += 2;

        printf("qtd: %d ", qtd);
        printf("kg: %d\n", kg);


//Envia quantidade e peso de forma consecutiva
        if (write(sock, &qtd, sizeof(qtd)) < 0)
        {
            perror("Falha em escrever a quantidade no socket");
            close(sock);
            return 1;
        }

       if (write(sock, &kg, sizeof(kg)) < 0)
        {
            perror("Falha em escrever o peso no socket");
            close(sock);
            return 1;
        }

//Encerramento do codigo
        ch = getchar();
        if (ch == 'q' || ch == 'Q')
        {
            printf("\n\nPrograma finalizado");
            close(sock);

            clock_gettime(CLOCK_MONOTONIC, &end_time);

            // Calcula o tempo total de execução
            total_time = (end_time.tv_sec - start_time.tv_sec) +
                        (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

            printf("Tempo de execução: %.6f segundos\n", total_time);

            return 1;
        }

        usleep(1000000);
    }
}