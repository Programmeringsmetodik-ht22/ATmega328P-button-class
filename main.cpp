/********************************************************************************
* main.cpp: Demonstration av klass f�r implementering av tryckknappar med 
*           PCI-avbrott. I detta fall sker avl�sning av en tryckknapp f�r
*           toggling av en lysdiod via en avbrottsrutin. F�r att g�ra motsvarande
*           objekt synliga i avbrottsrutinen s� anv�nds globala datamedlemmar.
********************************************************************************/
#include "led.hpp"
#include "button.hpp"

/* Globala datamedlemmar: */
led l1(8);     /* Lysdiod ansluten till pin 8 / PORTB0. */
button b1(13); /* Tryckknapp ansluten till pin 13 / PORTB5. */

/********************************************************************************
* ISR (PCINT0_vect): Avbrottsrutin f�r PCI-avbrott p� I/O-port B, som i detta
*                    program anropas vid nedtryckning eller uppsl�ppning av
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
*       / PORTB5, med PCI-avbrott aktiverat f�r toggling av lysdioden.
********************************************************************************/
int main(void)
{
   b1.enable_interrupt();

   while (1)
   {

   }

   return 0;
}

