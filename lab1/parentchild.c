#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>

#define TERMINAL  1
#define BUF_SZ    50

int
main(int argc, char *argv[])
{
  pid_t pid;

  if ((pid = fork()) < 0) {
    exit(EXIT_FAILURE);
  } else if (pid == 0) { /* 자식 프로세스 */
    char *msg = "자식 프로세스의 우선순위는 ";
    char *child_prio = calloc(BUF_SZ, sizeof(*child_prio));
    
    strncat(child_prio, msg, strlen(msg));
    sprintf(child_prio + strlen(child_prio), "%d", getpriority(PRIO_PROCESS, getpid()));
    strncat(child_prio, "\n", 1);

    write(TERMINAL, child_prio, strlen(child_prio));
    free(child_prio);
  } else { /* 부모 프로세스 */
    waitpid(pid, NULL, 0);

    char *msg = "부모 프로세스의 우선순위는 ";
    char *parent_prio = calloc(BUF_SZ, sizeof(parent_prio));
    
    strncat(parent_prio, msg, strlen(msg));
    sprintf(parent_prio + strlen(parent_prio), "%d", getpriority(PRIO_PROCESS, getpid()));
    strncat(parent_prio, "\n", 1);

    write(TERMINAL, parent_prio, strlen(parent_prio));
    free(parent_prio);
  }

  exit(EXIT_SUCCESS);
}