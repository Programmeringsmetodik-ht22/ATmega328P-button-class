/********************************************************************************
* main.cpp: Demonstration av klass för implementering av tryckknappar med 
*           PCI-avbrott. I detta fall sker avläsning av en tryckknapp för
*           toggling av en lysdiod via en avbrottsrutin. För att göra motsvarande
*           objekt synliga i avbrottsrutinen så används globala datamedlemmar.
********************************************************************************/
#include "led.hpp"
#include "button.hpp"

/* Globala datamedlemmar: */
led l1(8);     /* Lysdiod ansluten till pin 8 / PORTB0. */
button b1(13); /* Tryckknapp ansluten till pin 13 / PORTB5. */

/********************************************************************************
* ISR (PCINT0_vect): Avbrottsrutin för PCI-avbrott på I/O-port B, som i detta
*                    program anropas vid nedtryckning eller uppsläppning av
*                    tryckknapp b1. Vid nedtryckning av b1 togglas lysdiod l1.
********************************************************************************/
ISR (PCINT0_vect)
{
   if (b1.is_pressed())
   {
      l1.toggle();
   }

   return;
}

/********************************************************************************
* main: Ansluter en lysdiod till pin 8 / PORTB0 samt en tryckknapp till pin 13
*       / PORTB5, med PCI-avbrott aktiverat för toggling av lysdioden.
********************************************************************************/
int main(void)
{
   b1.enable_interrupt();

   while (1)
   {

   }

   return 0;
}

