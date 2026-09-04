#include <MD_Parola.h>
#include <MD_MAX72XX.h>
#include <SPI.h>

// Definição do hardware para módulos encadeados no Wokwi
#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW

// Total de módulos 8x8 (32x16 possui 4 colunas x 2 linhas = 8 módulos)
#define MAX_DEVICES 8 

// Definição dos pinos digitais conforme o circuito
#define CLK_PIN   10
#define DATA_PIN  12
#define CS_PIN    11

// Inicializa a biblioteca MD_Parola
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup() {
  myDisplay.begin();
  myDisplay.setIntensity(5); // Ajusta o brilho (0 a 15)
  myDisplay.displayClear();  // Limpa o display
  
  // Exibe o texto "OLA" centralizado sem animação de rolagem
  myDisplay.displayText("OLA", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
}

void loop() {
  // Mantém a execução da biblioteca
  if (myDisplay.displayAnimate()) {
    myDisplay.displayReset();
  }
}
