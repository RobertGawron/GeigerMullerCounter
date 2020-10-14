#include "ssd1306.h"
#include "ssd1306_i2c_sim.h"

uint8_t SSD1306_Buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];

// TODO correct and not hardcoded values
#define SSD1306I2CSIM_DisplayLength 128u
#define SSD1306I2CSIM_DisplayHeight 48u+16u

uint8_t SSD1306I2CSIM_Display[SSD1306I2CSIM_DisplayLength][SSD1306I2CSIM_DisplayHeight];

typedef enum GMDisplaySIM_PixelState_t
{
    GMDISPLAY_SIM_PIXEL_OFF = 0
    , GMDISPLAY_SIM_PIXEL_ON = 1
} GMDisplaySIM_PixelState_t;


uint8_t SSD1306_Init() 
{
    const size_t length = SSD1306I2CSIM_DisplayLength * SSD1306I2CSIM_DisplayHeight *sizeof(SSD1306I2CSIM_Display[0][0]);
    memset(&SSD1306I2CSIM_Display[0][0], GMDISPLAY_SIM_PIXEL_OFF, length);

    return 0u;
}

void ssd1306_I2C_WriteMulti(uint8_t address, uint8_t reg, uint8_t* data, uint16_t count) 
{
}


void ssd1306_I2C_Write(uint8_t address, uint8_t reg, uint8_t data) 
{
}



uint8_t SSD1306I2CSIM_GetDisplayLength()
{
    return SSD1306I2CSIM_DisplayLength;
}

uint8_t SSD1306I2CSIM_GetDisplayHeight()
{
    return SSD1306I2CSIM_DisplayHeight;
}

uint8_t* SSD1306I2CSIM_GetDisplayContent()
{
   return &SSD1306_Buffer[0];
}
