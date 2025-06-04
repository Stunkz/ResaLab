#ifndef SCREENOUTPUT_H
#define SCREENOUTPUT_H

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>

#include <SPI.h>

class ScreenOutput {

    private:
        const int SS = 10; // Chip Select pin for SPI
        const int DC = 8;  // Data/Command pin for SPI
        const int RES = 3;
        const int BUSY = 2;

        static const int SCK = 6;
        static const int MISO = -1;
        static const int MOSI = 7;
        static const int SPI_BUS = HSPI;
        static const int SPI_SPEED = 4000000; // 4 MHz
        static const int SPI_MODE = SPI_MODE0;
        static const int SPI_BIT_ORDER = MSBFIRST;

        SPIClass SPIn;
        GxEPD2_BW<GxEPD2_290_BS, GxEPD2_290_BS::HEIGHT> display;

        void initDisplay() {
            display.setRotation(1); // Set rotation if needed
            display.setFont(&FreeMonoBold9pt7b);
            display.setTextColor(GxEPD_BLACK);
            display.setFullWindow();
            display.fillScreen(GxEPD_WHITE);
            display.setCursor(0, 20);
            display.print("ResaLab");
        }

    public:
        ScreenOutput()
            : SPIn(SPI_BUS),
              display(GxEPD2_290_BS(SS, DC, RES, BUSY))
        {
            SPIn.begin(SCK, MISO, MOSI, SS);
            display.init(SPI_SPEED, true, 10, false, SPIn, SPISettings(SPI_SPEED, SPI_BIT_ORDER, SPI_MODE));
            initDisplay();
        }

        void showHour(int hour, int minute) {
            // TODO
        }

        void showInternetState(bool connected) {
            // TODO
        }

        void 
};


#endif // SCREENOUTPUT_H