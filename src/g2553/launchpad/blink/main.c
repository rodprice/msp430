#include "main.h"

#define BLINK_PIN p1_6

// blink function declaration
void blink(msp_pin_t pin);
void main (void)
{
  // Stop watchdog timer
  WDTCTL = WDTPW | WDTHOLD;
  // Initialize the clock to 16MHz
  clockInit();

  // Blink the blink pin
  blink(BLINK_PIN);
}

void blink(msp_pin_t pin)
{
  // Enable the blink pin as an output
  pinOutput(pin);
  // Now blink,
  for (;;) //ever
  {
    pinToggle(pin);
    _delay_ms(1000);
  }
}