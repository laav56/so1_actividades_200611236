#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Error al crear el proceso hijo");
        exit(1);
    } else if (pid == 0) {
        // Este es el proceso hijo
        printf("Proceso hijo (PID: %d) terminando.\n", getpid());
        exit(0);  // El proceso hijo termina inmediatamente
    } else {
        // Este es el proceso padre
        printf("Proceso padre (PID: %d), hijo (PID: %d) convertido en zombie.\n", getpid(), pid);
        sleep(60);  // El padre espera 60 segundos mientras el hijo es un zombie
        // Finalmente, el padre hace wait para limpiar el proceso zombie
        wait(NULL);  // Esto elimina el proceso zombie
        printf("El proceso zombie ha sido limpiado.\n");
    }

    return 0;
}
