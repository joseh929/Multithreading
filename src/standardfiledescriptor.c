#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <assert.h>

int main(){
    printf("Standard Input :%d\n",STDIN_FILENO);
    printf("Staandard Output :%d\n",STDOUT_FILENO);
    printf("Standard Error :%d\n",STDERR_FILENO);

    int fd = open("students.txt",O_RDWR | O_CREAT, 0755);
    char *foo ="Student Programming practical";
    char buffer[1024] = {0};
    size_t bytes=read (fd,buffer,sizeof(buffer));
    printf("Read %zu bytes from file descriptor %d\n",bytes,fd); 
    return 0;
}