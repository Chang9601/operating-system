#include <xinu.h>

/*------------------------------------------------------------------------
 *  gettmslice  -  타임 슬라이스에서 남은 시간(밀리초 단위)을 반환한다.
 *------------------------------------------------------------------------
 */
uint32 gettmslice(void)
{
  intmask mask;
  uint32  tm_slice;

  mask = disable();

  tm_slice = preempt;

  restore(mask);

	return tm_slice;
}
