/*****************************************************************************
 *Author:Diego Silva
 *Date:29/03/2021
 *Description:Code active led to using pull up resistor
 *****************************************************************************/
#define F_CPU 16000000
#define ATIVADO 1
#define ESPERA 2000

#include <avr/io.h>
#include <util/delay.h>



//prototipação de metodos
void incializa_portas(void);
int checa_chave(void);
void libera_acesso(void);

int main(){
    
    //Inicializando portas
    incializa_portas();

    while(1){
    

    //estado alto da porta
    PORTB |= (1<<PORTB5);

    //checa se a chave foi acionada
    if( checa_chave() == ATIVADO){
            libera_acesso();
        }
    }
   

    return 0;
}


/***************************************************************
 *
 * DD5 - porta digital como OUTPUT
 * DD4 - porta digital como INPUT
 * DD0 - porta digital como OUTPUT  
 * *************************************************************/

void incializa_portas(void){
    DDRB |= (1<<DDB5);
    DDRB |=(1<<DDB4);
    DDRB &=~ (1<<DDB0);
}

/**********************************
 * Pegar valor de entrada
 * *******************************/
int checa_chave(void){
    return (PINB&(1<<PINB0));
}

/***********************************************
 * Desativa porta DDB5
 * Ativa Porta DDB0
 * *********************************************/

void libera_acesso(void){
    //desativa porta
     _delay_ms(ESPERA);
    PORTB &=~ (1<<PORTB5);
    _delay_ms(ESPERA);
    PORTB |= (1<<PORTB4);
    _delay_ms(ESPERA);
    PORTB &=~ (1<<PORTB4);
    _delay_ms(ESPERA);

}