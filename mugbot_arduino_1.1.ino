#include <Servo.h>
//Mugbot Project Tokyo City University Koike Lab. 2016
//Mugbot System ver. 1.1

Servo eye_servo;
Servo head_servo;

static int pos = 0; //Arduinoのサーボの回転角度
static int g = 0; //Webのスライダーの位置
char ch = 0;

int mouse = 8; //口LED（３個）

int l_eye = 11; //左目（正面から見て）
int r_eye = 6; //右目（正面から見て）UNOに対応するために1.0.0の13ピンから６ピンに変更

int eye_default = 90; //目の正面位置を設定
int eye_min = 75; //目の最小位置を設定
int eye_max = 105; //目の最大位置を設定

int head_default = 90; //首の正面位置を設定
int head_min = 0; //首の最小角度を設定
int head_max = 180; //首の最大角度を設定

int eye_light_default = 50; //目の明るさの通常値を設定

void setup()
{
  Serial.begin(9600);

  eye_servo.attach(2); //サーボ　　目の上下
  head_servo.attach(4); //サーボ　 首の左右

  //目、首、目の明るさの初期設定
  pinMode(l_eye, OUTPUT);
  pinMode(r_eye, OUTPUT);
  pinMode(mouse, OUTPUT);
  
  analogWrite(l_eye, eye_light_default);
  analogWrite(r_eye, eye_light_default);
  digitalWrite(mouse, LOW);
  eye_servo.write(eye_default);
  head_servo.write(head_default );
}

void loop() {
  if (Serial.available() > 0) {
    ch = Serial.read();

    switch (ch) {
      case '0'...'9':
        g = g * 10 + ch - '0';
        //例えば100Xの文字がRaspberry Piから来ると1文字ずつ読み込む
        //1、0、0を順に読み込んで数字の100にして変数に格納する。

        break;

      case 'x':
        //Rasberry Piからｘを受け取ると首を左右に運動。
        head_servo.write( g );
        //次にxを読み込むと変数gに入った100でサーボの角度を変える。
        delay( 15 );
        g = 0;
        //gを0にして初期化
        break;

      case 'y': //Rasberry Piからyを受け取ると目を上下に運動。
        eye_servo.write( g );
        delay( 15 );
        g = 0;
        break;

      case 'z': //Rasberry Piからzを受け取ると目の明るさを変調。
        analogWrite(l_eye, g);
        analogWrite(r_eye, g);
        delay( 15 );
        g = 0;
        break;

      case 't': //Rasberry Piからtを受け取ると口が点滅し、発話時の動作を行う。
        delay( 2000 );
        digitalWrite(mouse, HIGH);

        for ( pos = eye_default; pos < 110; pos += 1 ) {
          eye_servo.write( pos );
          delay( 15 );
        } ;

        for ( pos = 110; pos > 80; pos -= 1 ) {
          eye_servo.write( pos );
          delay( 15 );
        } ;

        for ( pos = 80; pos < eye_default; pos += 1 ) {
          eye_servo.write( pos );
          delay( 15 );
        } ;
        break;

      case 'n': //Rasberry Piからnを受け取ると首、目の標準位置に戻す。
        analogWrite(l_eye, eye_light_default);
        analogWrite(r_eye, eye_light_default);
        digitalWrite(mouse, LOW);

        eye_servo.write(eye_default);
        head_servo.write(head_default);
        break;

      case 'l': //Rasberry Piからlを受け取ると「笑う」のアクションを行う。
        analogWrite(l_eye, eye_light_default);
        analogWrite(r_eye, eye_light_default);
        digitalWrite(mouse, HIGH);

        eye_servo.write( 120 );
        delay(100 );
        eye_servo.write( 100 );
        delay(100 );
        eye_servo.write( 120 );
        delay(100 );
        eye_servo.write( 100 );
        delay(100 );
        eye_servo.write( 120 );
        delay(100 );
        eye_servo.write( 100 );
        delay(100 );
        eye_servo.write( 120 );
        delay(100 );
        eye_servo.write( 100 );
        delay(100 );
        eye_servo.write( 120 );
        delay(100 );
        eye_servo.write( 100 );
        delay(100 );
        eye_servo.write( 120 );
        delay(100 );
        eye_servo.write( 100 );
        delay(100 );
        eye_servo.write( 120 );
        delay(100 );
        eye_servo.write( 100 );
        delay(100 );
        eye_servo.write( 120 );
        delay(100 );
        eye_servo.write( eye_default );
        delay(100 );
        digitalWrite(mouse, LOW);
        break;

      case 's': //Rasberry Piからsを受け取ると「悲しい」のアクションを行う。
        for ( pos = eye_default; pos > 70; pos -= 1 ) {
          eye_servo.write( pos );
          delay( 15 );
        } ;

        for ( pos = eye_light_default; pos > 20; pos -= 1 ) {
          analogWrite(l_eye, pos);
          analogWrite(r_eye, pos);
          delay( 10);
        } ;
        eye_servo.write(eye_default);
        head_servo.write(head_default);

        analogWrite(l_eye, eye_light_default);
        analogWrite(r_eye, eye_light_default);
        digitalWrite(mouse, LOW);

        break;

      case 'h': //Rasberry Piからhを受け取ると「はい」のアクションを行う。
        analogWrite(l_eye, eye_light_default);
        analogWrite(r_eye, eye_light_default);

        for ( pos = eye_default; pos > 70; pos -= 1 ) {
          eye_servo.write( pos );
          delay( 15 );
        } ;

        for ( pos = 70; pos < eye_default; pos += 1 ) {
          eye_servo.write( pos );
          delay( 15 );
          eye_servo.write( pos );
          delay( 15 );
        } ;

        for ( pos = eye_default; pos > 70; pos -= 1 ) {
          eye_servo.write( pos );
          delay( 15 );
        } ;

        for ( pos = 70; pos < eye_default; pos += 1 ) {
          eye_servo.write( pos );
          delay( 15 );
          eye_servo.write( pos );
          delay( 15 );
        } ;
        break;

      case 'f': //Rasberry Piからfを受け取ると「いいえ」のアクションを行う。
        analogWrite(l_eye, eye_light_default);
        analogWrite(r_eye, eye_light_default);

        for ( pos = 85; pos < 135; pos += 1 ) {
          head_servo.write( pos );
          delay( 15 );
        } ;

        for ( pos = 135; pos > 55; pos -= 1 ) {
          head_servo.write( pos );
          delay( 15 );
        } ;

        for ( pos = 55; pos < 85; pos += 1 ) {
          head_servo.write( pos );
          delay( 15 );
        } ;
        break;

      case 'w': //Rasberry Piからwを受け取ると「ウインク」　のアクションを行う。
        analogWrite(l_eye, eye_light_default);
        digitalWrite(r_eye, LOW);
        delay( 500 );
        analogWrite(l_eye, eye_light_default);
        analogWrite(r_eye, eye_light_default);
        delay( 500 );
        digitalWrite(l_eye, LOW);
        analogWrite(r_eye, eye_light_default);
        delay( 500 );
        analogWrite(l_eye, eye_light_default);
        analogWrite(r_eye, eye_light_default);
        break;

      case 'b': //Rasberry Piからwを受け取ると「びっくり」のアクションを行う。
        for ( pos = eye_default; pos < 105; pos += 1 ) {
          eye_servo.write( pos );
          delay( 15 );
        } ;
        analogWrite(l_eye, 250);
        analogWrite(r_eye, 250);
        delay( 350 );
        analogWrite(l_eye, eye_light_default);
        analogWrite(r_eye, eye_light_default);
        delay( 100 );
        eye_servo.write(eye_default);
        delay( 100 );
        break;

      case 'e': //Rasberry Piからeを受け取ると「ハイテンション」のアクションを行う。
        for ( ch = 0; ch < 5; ch += 1 ) {
          digitalWrite(mouse, HIGH);
          analogWrite(l_eye, eye_light_default);
          digitalWrite(r_eye, LOW);
          delay( 100 );
          digitalWrite(l_eye, LOW);
          analogWrite(r_eye, eye_light_default);
          delay( 100 );
          eye_servo.write(random(eye_default, 110) );
          head_servo.write(random(25, 135) );
          delay( 100 );
          analogWrite(l_eye, eye_light_default);
          analogWrite(r_eye, eye_light_default);
          delay( 100 );
          digitalWrite(mouse, LOW);
          delay( 100 );
        }

        eye_servo.write(eye_default);
        head_servo.write(head_default);

        analogWrite(l_eye, eye_light_default);
        analogWrite(r_eye, eye_light_default);
        digitalWrite(mouse, LOW);
        break;

      case 'k': //Rasberry Piからkを受け取ると口のLEDのみを消灯
        digitalWrite(mouse, LOW);
        break;

      default:
        eye_servo.write(eye_default);
        head_servo.write(head_default);

        analogWrite(l_eye, eye_light_default);
        analogWrite(r_eye, eye_light_default);
        digitalWrite(mouse, LOW);
        break;
    }
  }
}
