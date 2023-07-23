#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

extern char **environ;

void print_env(char *args);
void do_exit(char *args);
char *seperte(char *buffer, char *token);

#endif
