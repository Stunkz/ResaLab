#ifndef SCREENOUTPUT_H
#define SCREENOUTPUT_H

#define ENABLE_GxEPD2_GFX 0

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>

class ScreenOutput {

    private:
        static int SS = 5;
        static int DC = 1;
        static int RES = 2;
        static int BUSY = 3;
        GxEPD2_BW<GxEPD2_290_BS, GxEPD2_290_BS::HEIGHT> display{GxEPD2_290_BS(SS ,DC ,RES ,BUSY)};
    
    public:
        
}


#endif // SCREENOUTPUT_H