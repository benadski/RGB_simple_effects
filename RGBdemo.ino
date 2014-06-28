void setup()
{
  // put your setup code here, to run once:
  randomSeed(analogRead(0));

}

void showRGB(uint8_t r, uint8_t g, uint8_t b)
{
  analogWrite(3, 255 - b);
  analogWrite(5, 255 - g);
  analogWrite(6, 255 - r);  
}

void loop()
{
  volatile uint8_t R, Rt;
  volatile uint8_t G, Gt;
  volatile uint8_t B, Bt;
  uint16_t R16;
  uint16_t G16;
  uint16_t B16;

  uint8_t test, puls, pauze;
  while(1)
  {        
    //Green laz0rs!
    test = 40 + random(100);
    for (uint8_t a=0; a < test; a++)
    {
      for (uint8_t b = 0; b < 32; b++)
      {
        G = b << 3;
        if (b > 24) B = (b - 24) << 5; else B = 0;
        if (b > 28) R = (b - 28) << 6; else R = 0;
        showRGB(R, G, B);
        delay(4);
      }
      showRGB(0,0,0);
      delay(30 + random(300));
    }
    
    //Dark for a second
    showRGB(0,0,0);
    delay(1000);
    
    //Colorshifter with pastels!
    test = 8 + random(30);
    for (uint8_t a=0; a < test; a++)
    {
      uint16_t c_wheel = random(768);
      if (c_wheel < 256)
      {
        Rt = 255 - c_wheel;
        Gt = c_wheel;
        Bt = 0;
      }else if (c_wheel < 512)
      { 
        Rt = 0;
        Gt = 511 - c_wheel;
        Bt = c_wheel - 256;
      }else
      {
        Rt = c_wheel - 512;
        Gt = 0;
        Bt = 767 - c_wheel;
      }      
      
      for (uint8_t b = 1; b < 65; b++)
      {
        R16 = b * Rt + (64 - b) * R;
        G16 = b * Gt + (64 - b) * G;
        B16 = b * Bt + (64 - b) * B;
        
        R16 >>= 6;
        G16 >>= 6;
        B16 >>= 6;
        
        showRGB(R16 % 256,G16 % 256,B16 % 256);
        
        delay(20);
      }
      R = Rt;
      G = Gt;
      B = Bt;
    }
    
    //Dark for a second
    showRGB(0,0,0);
    delay(1000);
    
    //Welding like  
    test = 8 + random(24);
    for (uint8_t a=0; a < test; a++)
    {
      puls = 25 + random(150);
      for (uint8_t b = 0; b < puls; b++)
      {
        B = random(240) + 25;
        G = (random(B) >> 2) + 10;
        R = G - 10;
  
        showRGB(R,G,B);
        delay(25);   
      }
      
      showRGB(0,0,0);
      pauze = 10 + random(200);
      delay(pauze * 10);
    }

    //Dark for a second
    showRGB(0,0,0);
    delay(1000);

    //Orange beacon
    R = 12;
    G = 3;
    test = 8 + random(12);
    for (uint8_t a=0; a < test; a++)
    {
      for (uint8_t b = 0; b < 64; b++)
      {
        if (b < 32)
        {
          R += 4;  
          G++;
          if (R > 128) 
          {
            R += 32;
            G += 8;
          }
        }else
        {
          R -= 4;
          G--;
          if (R > 128) 
          {
            R -= 32;
            G -= 8;
          }
        }
        showRGB(R, G, 0);
        delay(20);
      }
    }

    //Dark for a second
    showRGB(0,0,0);
    delay(1000);

    //Candle simulation
    test = 50 + random(100);
    for (uint8_t a=0; a < test; a++)
    {
      R16 = 100 + random(155);
      while (R != R16)
      {
        if (R < R16) R++; else R--;
        G = R >> 1;
        B = R >> 4;
        showRGB(R, G, B);
        delay(3);
      }
    }

    //Dark for a second
    showRGB(0,0,0);
    delay(1000);

    //Police light (to show a very simple effect without difficult loops and fades).
    test = 8 + random(30);
    for (uint8_t a=0; a < test; a++)
    {
      showRGB(255,0,0);
      delay(80);
      showRGB(0,0,0);
      delay(80);
      showRGB(255,0,0);
      delay(80);
      showRGB(0,0,0);
      delay(80);
      showRGB(255,0,0);
      delay(80);
      showRGB(0,0,0);
      delay(80);
      showRGB(0,0,255);
      delay(80);
      showRGB(0,0,0);
      delay(80);
      showRGB(0,0,255);
      delay(80);
      showRGB(0,0,0);
      delay(80);
      showRGB(0,0,255);
      delay(80);
      showRGB(0,0,0);
      delay(80);
      showRGB(255,0,0);
      delay(80);
      showRGB(0,0,0);
      delay(80);
      showRGB(255,0,0);
      delay(80);
      showRGB(0,0,0);
      delay(80);
      showRGB(255,0,0);
      delay(80);
      showRGB(0,0,0);
      delay(80);
      showRGB(0,0,255);
      delay(80);
      showRGB(0,0,0);
      delay(80);
      showRGB(0,0,255);
      delay(80);
      showRGB(0,0,0);
      delay(80);
      showRGB(0,0,255);
      delay(80);
      showRGB(0,0,0);
      delay(80);
      showRGB(255,0,0);
      delay(80);
      showRGB(0,0,0);
      delay(80);
      showRGB(0,0,255);
      delay(80);
      showRGB(0,0,0);
      delay(80);
      showRGB(255,0,0);
      delay(80);
      showRGB(0,0,0);
      delay(80);
      showRGB(0,0,255);
      delay(80);
      showRGB(0,0,0);
      delay(80);
    }

  }
}


