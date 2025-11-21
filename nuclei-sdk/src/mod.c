#include "gd32vw55x.h"

// FIXME: We're not using nesting interrupt handling at present.
static void init_swi() { eclic_irq_enable(CLIC_INT_SFT, 0, 0); }

static void init_timer()
{
  SysTimer_SetControlValue(SysTimer_MTIMECTL_CMPCLREN_Msk);
  SysTimer_SetCompareValue(SystemCoreClock / 4000);
  __ECLIC_SetTrigIRQ(CLIC_INT_TMR, ECLIC_POSTIVE_EDGE_TRIGGER);
  eclic_irq_enable(CLIC_INT_TMR, 0, 0);
}

void init_soc()
{
  SystemInit();
  EnableICache();
  init_swi();
  init_timer();
  rcu_periph_clock_enable(RCU_GPIOB);
  rcu_periph_clock_enable(RCU_GPIOA);

  /* enable USART clock */
  rcu_periph_clock_enable(RCU_USART0);
}
