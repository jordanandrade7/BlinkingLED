/*
* blink.c  -- Blink a red LED when one button is pressed, a green LED when another button is pressed,
           -- and both the red and green LED when a third button is pressed all at a 5 Hz rate. When 
           -- two buttons are pressed simutaniously nothing happens.
* Date          Author              Revision
*3/2/22         Jordan Andrade      initial code creation
*/

#include <avr/io.h>
#include <util/delay.h>

int main(void){
    DDRD = 1<<DDD6|1<<DDD7;     // set D6 and D7 as outputs
    PORTD = 1<<PORTD2|1<<PORTD3|1<<PORTD4;      // set the pull up on D2, D3, D4

    while(1){       // always true 
        
        if (((PIND & (1<<PIND2)) == 0) & ((PIND & (1<<PIND3)) == 0)){   // if buttons connected to D2 and D3 are on
            PORTD &= ~(1<<PORTD6);      // turn green LED off
            PORTD &= ~(1<<PORTD7);      // turn red LED off
        }

        else if (((PIND & (1<<PIND2)) == 0) & ((PIND & (1<<PIND4)) == 0)){  // if buttons connected to D2 and D4 are on
            PORTD &= ~(1<<PORTD6);      // turn green LED off
            PORTD &= ~(1<<PORTD7);      // turn red LED off
        }

        else if (((PIND & (1<<PIND3)) == 0) & ((PIND & (1<<PIND4)) == 0)){  // if buttons connected to D3 and D4 are on
            PORTD &= ~(1<<PORTD6);      // turn green LED off
            PORTD &= ~(1<<PORTD7);      // turn red LED on
        }

        else if ((PIND & (1<<PIND2)) == 0){     // if button connected to D2 is on 
            PORTD |= (1<<PORTD7);       // turn red LED on        
            _delay_ms(100);             // delay 100 ms
            PORTD &= ~(1<<PORTD7);      // turn red LED off
            _delay_ms(100);
        }

        else if ((PIND & (1<<PIND3)) == 0){     // if button connected to D3 is on 
            PORTD |= (1<<PORTD6);       // turn green LED on 
            _delay_ms(100);             // delay 100 ms 
            PORTD &= ~(1<<PORTD6);      // turn green LED off
            _delay_ms(100);
        }

        else if ((PIND & (1<<PIND4)) == 0){     // if button connected to D4 is on 
            PORTD |= (1<<PORTD6);       // turn green LED on
            PORTD |= (1<<PORTD7);       // turn red LED on 
            _delay_ms(100);             // delay 100 ms 
            PORTD &= ~(1<<PORTD6);      // turn green LED off
            PORTD &= ~(1<<PORTD7);      // turn red LED off
            _delay_ms(100);
        }
    }
    return(0);
}