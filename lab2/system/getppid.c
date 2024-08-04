#include <xinu.h>

/*------------------------------------------------------------------------
 *  getppid  -  현재 실행 중인 프로세스의 부모 프로세스의 아이디를 반환한다.
 *------------------------------------------------------------------------
 */
pid32	getppid(pid32 pid)
{	
  intmask mask;
  struct	procent	*prptr;
  pid32 ppid;

  mask = disable();
  if (isbadpid(pid) || pid < 1) {
		restore(mask);
		return (pri16)SYSERR;
	}

  prptr = &proctab[pid];
  ppid = prptr->prparent;

	restore(mask);

	return (ppid);
}
