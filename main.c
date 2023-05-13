#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char buffer[1024];
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    write(fd, "Hello, world!\n", 14);
    close(fd);
    fd = open("output.txt", O_RDONLY);
    if (fd == -1) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    int num_bytes = read(fd, buffer, 1024);
    buffer[num_bytes] = '\0';
    printf("Conteúdo do arquivo: %s", buffer);
    close(fd);
    return 0;
}
