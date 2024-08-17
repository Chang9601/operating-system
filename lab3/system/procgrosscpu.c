#include <xinu.h>

/*--------------------------------------------------------------------------
 *  procgrosscpu  -  프로세스의 총 CPU 사용량을 반환한다.
 *--------------------------------------------------------------------------
 */
uint32 procgrosscpu(pid32 pid)
{
  intmask mask;
  uint32 prgrosscpu;
  struct procent *prptr;

  mask = disable();
  if (isbadpid(pid)) {
    restore(mask);
		return (pri16)SYSERR;
  }

  prptr = &proctab[pid];
  prgrosscpu = prptr->prgrosscpu;

  restore(mask);

  return prgrosscpu;
}