int c[8] = {13,3,4,10,6,11,15,16};
int r[8] = {9,14,8,12,1,7,2,5};
int Mdisp[8][8];
unsigned long time;
 
void matrixPrint(){
      for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
          if(Mdisp[i][j] ==  1){
            digitalWrite(r[i], HIGH);
            digitalWrite(c[j], LOW);
            digitalWrite(r[i], LOW);
            digitalWrite(c[j], HIGH);
          }else{
            digitalWrite(r[i], LOW);
            digitalWrite(c[j], HIGH);
            digitalWrite(r[i], LOW);
            digitalWrite(c[j], HIGH);
         
          }
    //    }
      }
  }
}
 
void setup() {
  for(int i = 0; i < 8; i++){
    pinMode(r[i], OUTPUT);
    pinMode(c[i], OUTPUT);
  }

  pinMode(18, INPUT);

  pinMode(19, INPUT);

}
 
 
int x1=0;
int x2=7;
int bx=2;
int by=4;
int bdx=1;
int bdy=1;

int dir1=1;
int dir2=-1;
int frame=0;
// the loop function runs over and over again forever
void loop() {
    if(digitalRead(19)==HIGH){
      dir1=-1;
    }else{
      dir1=1;
    }
    if(digitalRead(18)==HIGH){
      dir2=1;
    }else{
      dir2=-1;
    }
    if(millis()%300<10 and !frame){
      x1=x1+dir1;
      x2=x2+dir2;
      if(bx>=7) bdx=-1;
      if(bx<=0) bdx=1;
     
      if(by>=6){
        if(abs(x2-bx)>1){
          fill(1);
          while(1) matrixPrint();
        }else{
          bdy=-1;
        }
      }
      if(by<=1){
        if(abs(x1-bx)>1){
          fill(1);
          while(1) matrixPrint();
        }else{
          bdy=1;
        }
      }
     
      bx=(bx+bdx);
      by=(by+bdy);
      frame=1;
    }
    if(millis()%300>290){
      frame=0;
    }
  
    if(x1>7){
        x1=7;
    }
    if(x1<0){
        x1=0;
    }
    if(x2>7){
        x2=7;
    }
    if(x2<0){
        x2=0;
    }
   
    if(millis()%20<5){
      fill(0);
      Mdisp[x1][0]=1;
      Mdisp[x2][7]=1;
      Mdisp[bx][by]=1;
      matrixPrint();
    }
}


void fill(int b){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      Mdisp[j][i]=b;
    }
  }
}
