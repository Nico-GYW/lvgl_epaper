#include <GxEPD2_BW.h>  // Pour les écrans noir et blanc
#include <Fonts/FreeMonoBold9pt7b.h>  // Police utilisée pour l’affichage

// Déclaration des pins SPI et de l’écran e-paper
#define EPD_SCK_PIN  5     // SPI Clock
#define EPD_MOSI_PIN 6     // SPI MOSI
#define EPD_CS_PIN   4     // Chip Select de l’e-paper
#define EPD_RST_PIN  2     // Reset de l’e-paper
#define EPD_DC_PIN   3     // Data/Command (DC)
#define EPD_BUSY_PIN 1     // Busy de l’e-paper

GxEPD2_BW<GxEPD2_370_TC1, GxEPD2_370_TC1::HEIGHT> display(GxEPD2_370_TC1(/*CS=*/ EPD_CS_PIN, /*DC=*/ EPD_DC_PIN, /*RST=*/ EPD_RST_PIN, /*BUSY=*/ EPD_BUSY_PIN));

// Texte à afficher
const char HelloWorld[] = "Hello World!";

void helloWorld() {
  // Prépare l’affichage et calcule les coordonnées centrées
  display.setRotation(1);  // Orientation de l’écran
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
  
  uint16_t x = ((display.width() - tbw) / 2) - tbx;
  uint16_t y = ((display.height() - tbh) / 2) - tby;

  // Prépare la fenêtre d’affichage complète
  display.setFullWindow();
  display.firstPage();
  
  // Affichage progressif sur chaque page de l’écran e-paper
  do {
    display.fillScreen(GxEPD_WHITE);  // Efface l’écran
    display.setCursor(x, y);  // Position du texte
    display.print(HelloWorld);
  } while (display.nextPage());
}

void setup() {
  // Initialisation du SPI et de l’écran
  SPI.begin(EPD_SCK_PIN, -1, EPD_MOSI_PIN);  // -1 signifie qu'on ne lit pas MISO
  display.init(115200, true, 2, false);  // Utilise un reset court adapté aux cartes Waveshare

  // Affiche le texte "Hello World" au centre de l’écran
  helloWorld();

  // Met l’écran en veille pour économiser de l’énergie
  display.hibernate();
}

void loop() {
  // Boucle vide, car tout est fait dans setup()
}