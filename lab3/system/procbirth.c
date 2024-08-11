#include <xinu.h>

/*--------------------------------------------------------------------------
 *  procbirth  -  프로세스 아이디에 속하는 프로세스의 생성 시간을 밀리초 단위로 반환한다.
 *--------------------------------------------------------------------------
 */
uint32 procbirth(pid32 pid)
{
  intmask mask;
  uint32  birthday;
  struct procent *prptr;

  mask = disable();
  if (isbadpid(pid)) {
    restore(mask);
		return (pri16)SYSERR;
  }

  prptr = &proctab[pid];
  birthday = prptr->prbirth;

  restore(mask);

  return birthday;
}