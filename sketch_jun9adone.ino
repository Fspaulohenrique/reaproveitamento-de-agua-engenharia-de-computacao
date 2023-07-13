#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

int boia1 = 0; // Boia 1 baixa caixa 1
int boia2 = 0; // Boia 2 alta caixa 1
int boia3 = 0; // Boia 3 alta caixa 2
int boia4 = 0; // Boia 4 alta caixa 2
int boia5 = 0; // Boia 5 alta caixa 3

// Definições dos pinos do Arduino ligados à entrada da Ponte H
int IN1 = 10;
int IN2 = 11;
int IN3 = 12;
int IN4 = 13;

int SEL1 = 7; // Pino para o solenoide
int temp = 8; // Pino para acionar o relé

void setup()
{
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 0);    
  lcd.print("Start");
  
  pinMode(2, INPUT); // Boia 1 baixa caixa 1 porta 2 do arduino 
  pinMode(3, INPUT); // Boia 2 alta caixa 1 porta 3 do arduino 

  pinMode(4, INPUT); // Boia 3 baixa caixa 2 porta 4 do arduino
  pinMode(5, INPUT); // Boia 4 alta caixa 2 porta 5 do arduino

  pinMode(6, INPUT); // Boia 5 alta caixa 3 porta 6 do arduino

  pinMode(IN1, OUTPUT); // Ponte H que liga as bombas de acordo com as boias de baixo
  pinMode(IN2, OUTPUT); // Ponte H que liga as bombas de acordo com as boias de baixo
  pinMode(IN3, OUTPUT); // Ponte H que liga as bombas de acordo com as boias de baixo
  pinMode(IN4, OUTPUT); // Ponte H que liga as bombas de acordo com as boias de baixo

  pinMode(SEL1, OUTPUT); // Configurar pino do solenoide como saída
  digitalWrite(SEL1, HIGH); // Ligar a solenoide

  pinMode(temp, OUTPUT); // Configurar pino para acionar o relé
  digitalWrite(temp, LOW); // Inicialmente, relé desligado
}

void loop()
{
  lcd.setCursor(0, 1);
  boia1 = digitalRead(2);
  boia2 = digitalRead(3);
  boia3 = digitalRead(4);
  boia4 = digitalRead(5);
  boia5 = digitalRead(6);

  if (boia2 == HIGH)
  {
    digitalWrite(SEL1, LOW); // Desligar a solenoide
    lcd.clear();
    lcd.print("Enchendo caixa 1");
  }
  else if (boia2 == LOW)
  {
    digitalWrite(SEL1, HIGH); // Ligar a solenoide
    lcd.clear();
    lcd.print("Enchendo caixa 2");
  }

  if (boia5 == HIGH)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    lcd.clear();
    lcd.print("Ligando bomba 1");
  }
  else
  {
    if (boia1 == HIGH)
    {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    }
    else if (boia1 == LOW)
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
    }
  }

  if (boia4 == HIGH) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } 
  else if (boia4 == LOW)
  {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  if (boia3 == HIGH){
    lcd.clear();
    lcd.print("Enchendo caixa 2");
  }
}
