 
#include <Wtv020sd16p.h>

int resetPin = 4;  //Pino Reset
int clockPin = 5;  //Pino clock
int dataPin = 6;   //Pino data (DI)
int busyPin = 7;   //Pino busy
 
//Variavel que armazena os caracteres recebidos
char buf;

Wtv020sd16p wtv020sd16p(resetPin,clockPin,dataPin,busyPin);
 
void setup()
{
  //Inicializa a serial
  Serial.begin(9600);
  //Inicializa o modulo WTV020
  wtv020sd16p.reset();
  //Informacoes iniciais 
  menu_inicial();
}
 
void loop()
{
  //Aguarda os dados da serial
  while(Serial.available() > 0)
  {
    buf = Serial.read();
    //Caso seja recebido o numero 1, reproduz o arquivo 0001.ad4
    if (buf == '1')
    {
      Serial.println("Reproduzindo 0001.ad4");
      wtv020sd16p.playVoice(0);
      //Reproduz o arquivo 1
      wtv020sd16p.asyncPlayVoice(1);
      delay(3000); 
      wtv020sd16p.stopVoice();
      delay(2000);
      menu_inicial();  
    }
     
    //Caso seja recebido o numero 2, reproduz o arquivo 0002.ad4
    if (buf == '2')
    {
      Serial.println("Reproduzindo 0002.ad4");
      wtv020sd16p.playVoice(0);
      //Reproduz o arquivo 2
      wtv020sd16p.asyncPlayVoice(2);
      delay(3000);
      wtv020sd16p.stopVoice();
      delay(2000);
      menu_inicial();
    }
  }
}
 
//Mostra menu de opcoes
void menu_inicial()
{
  Serial.println("\nDigite : ");
  Serial.println("1 - Reproduz o arquivo 0001.ad4");
  Serial.println("2 - Reproduz o arquivo 0002.ad4");
  Serial.println();
}
