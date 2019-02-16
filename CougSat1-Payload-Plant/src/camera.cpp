#include <main.h>
#include <ArduCAM.h>

uint8_t start_capture = 0;

ArduCAM myCAM(OV2640,PIN_CS);

void setup_camera() {
  Serial.begin(115200);
  Wire.begin(); 

  pinMode(PIN_CS, OUTPUT);

  // initialize SPI
  SPI.begin(); 
  myCAM.write_reg(ARDUCHIP_MODE, 0x00);

  // camera parameters
  myCAM.set_format(JPEG);
  myCAM.InitCAM();
  myCAM.OV2640_set_JPEG_size(OV2640_800x600); // 1600x1200 max

  start_capture = 1;
}

void single_camera() // can be looped for continuous capture
{
  uint8_t image_data,image_data_last;
  
  if(start_capture)
  {
    // clear the capture done flag 
    myCAM.clear_fifo_flag();   
    // start capture
    myCAM.start_capture();   
  }
  
  if(myCAM.read_reg(ARDUCHIP_TRIG) & CAP_DONE_MASK)
  {
    while( (image_data != 0xD9) | (image_data_last != 0xFF) )
    {
      image_data_last = image_data;
      image_data = myCAM.read_fifo();
      Serial.write(image_data);
    }
  
    // clear the capture done flag 
    myCAM.clear_fifo_flag();
    start_capture = 0;
  }
}