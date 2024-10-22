#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

int main()
{
    
    const int SIZE = 4096;

    const char *name = "OS";

    const char *message_0 = "Hello";
    const char *message_1 = "World!";

    int shm_fd;

    void *ptr; /* Pointer to shared memory object */

    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    ftruncate(shm_fd, SIZE); /* Configure the size of the shared memory object */

    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0); /* Memory map */

    sprintf((char *)ptr, "%s", message_0);
    ptr += strlen(message_0);

    sprintf((char *)ptr, "%s", message_1);
    ptr += strlen(message_1);

    return 0;
}
