#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char* arguments[] = {"ls", "df", "ps", "pwd", NULL};
int status;

int main(int argc, char const *argv[]) {

for (size_t i = 0; i < 3; i++) {                                       //Added for()

  char* current[] = {arguments[i], arguments[4]};                      //Added current
  pid_t pid_ls = fork();
  if (pid_ls == 0) {
    execvp(current[0], current);

    printf("ERROR\n");
  }
  else{
    waitpid(-1, &status, 0);
  }
}
                                                                       //Deleted unnecessary ifs
  printf("Done\n");

  return 0;
}
