int red = 255;
int green = 0;
int blue = 0;

void setup() {
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  if(red>0&&blue==0){
    if(green==255){
      red--;
    }else{
      green++;
    }
  }
  if(green>0 && red==0){
    if(blue == 255){
      green--;
    }else{
      blue++;
    }
  }
  if(blue>0 && green==0){
    if(red == 255){
      blue--;
    }else{
      red++;
    }
  }
  analogWrite(9,red);
  analogWrite(10,blue);
  analogWrite(11,green);
  delay(10);
}
