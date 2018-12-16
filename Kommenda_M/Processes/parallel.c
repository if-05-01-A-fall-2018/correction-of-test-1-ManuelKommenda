#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char* arguments[] = {"ls", "df", "ps", "pwd", NULL};
int status;

int main(int argc, char const *argv[]) {
  pid_t pid_ls = fork();
  if (pid_ls == 0) {
    execl(arguments[0], arguments[0]);
    printf("ERROR\n");
  }
  else{
    waitpid(-1, &status, 0);
  }
  pid_t pid_df = fork();
  if (pid_df == 0) {
    execl(arguments[1], arguments[1]);
    printf("ERROR\n");
  }
  else{
    waitpid(-1, &status, 0);
  }
  pid_t pid_ps = fork();
  if (pid_ps == 0) {
    execl(arguments[2], arguments[2]);
    printf("ERROR\n");
  }
  else{
    waitpid(-1, &status, 0);
  }
  pid_t pid_pwd = fork();
  if (pid_pwd == 0) {
    execl(arguments[3], arguments[3]);
    printf("ERROR\n");
  }
  else{
    waitpid(-1, &status, 0);
  }

  printf("Done\n");

  return 0;
}
