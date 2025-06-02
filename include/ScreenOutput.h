#ifndef SCREENOUTPUT_H
#define SCREENOUTPUT_H

#define ENABLE_GxEPD2_GFX 0

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>

#include <SPI.h>

class ScreenOutput {

    private:
        static const int SS = 10; // Chip Select pin for SPI
        static const int DC = 8;  // Data/Command pin for SPI
        static const int RES = 3; 
        static const int BUSY = 2;

        static const int SCK = 6;
        static const int MISO = -1;
        static const int MOSI = 7;
        static const int SPI_BUS = HSPI;
        static const int SPI_SPEED = 4000000; // 4 MHz
        static const int SPI_MODE = SPI_MODE0;
        static const int SPI_BIT_ORDER = MSBFIRST;

        SPIClass SPIn = SPIClass(SPI_BUS);
        GxEPD2_BW<GxEPD2_290_BS, GxEPD2_290_BS::HEIGHT> display;

        void initDisplay() {
            display.setRotation(1); // Set rotation if needed
            display.setFont(&FreeMonoBold9pt7b);
            display.setTextColor(GxEPD_BLACK);
            display.setFullWindow();
            display.fillScreen(GxEPD_WHITE);
            display.setCursor(0, 20);
            display.print("ResaLab");
            display.update();
        }

    public:
        ScreenOutput() : display(GxEPD2_290_BS(SS, DC, RES, BUSY)) {
            SPIn.begin(SCK, MISO, MOSI, SS);
            display.init(SPI_SPEED, true, 10, fals, SPIn, SPISettings(SPI_SPEED, SPI_BIT_ORDER, SPI_MODE));
        }

};


#endif // SCREENOUTPUT_H