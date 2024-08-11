#include <xinu.h>

/*--------------------------------------------------------------------------------------------------
 *  proclifetime  -  프로세스 아이디에 속하는 프로세스가 생성된 이후부터 현재까지의 수명을 밀리초 단위로 반환한다.
 *--------------------------------------------------------------------------------------------------
 */
uint32 proclifetime(pid32 pid)
{
  intmask mask; 
  uint32  birthday, lifetime;
  struct procent *prptr;

  mask = disable();
  if (isbadpid(pid)) {
    restore(mask);
		return (pri16)SYSERR;
  }

  prptr = &proctab[pid];
  birthday = prptr->prbirth;

  lifetime = clktimemilli - birthday;

  restore(mask);

  return lifetime;
}