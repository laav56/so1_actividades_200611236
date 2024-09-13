1. En total se crean 8 procesos; el programa en sí es un proceso, con el primer fork se crean 2 procesos, el segundo fork crea un proceso en cada proceso anterior, por lo que llevaría un total de 4; el último fork se ejecuta en los 4 procesos anteriores dando el total de 8.

2.Código en C:
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

Resultado de la ejecución:
Proceso padre (PID: 15872), hijo (PID: 15887) convertido en zombie.
Proceso hijo (PID: 15887) terminando.
El proceso zombie ha sido limpiado.
[1] + Done                       "/usr/bin/gdb" --interpreter=mi --tty=${DbgTerm} 0<"/tmp/Microsoft-MIEngine-In-h2pheyqt.dbh" 1>"/tmp/Microsoft-MIEngine-Out-ysrbtmt2.05t"

Validación en terminal con ps-l:
lalberto@lalberto-Lenovo-ideapad-330-15ARR:~$ ps -l
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000   15967   15947  0  80   0 -  3452 do_wai pts/1    00:00:00 bash
4 R  1000   15981   15967  0  80   0 -  3801 -      pts/1    00:00:00 ps
lalberto@lalberto-Lenovo-ideapad-330-15ARR:~$ 

3.Código
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0){
        fork();
        thread_create();
    }
    fork();
    return 0;
}


