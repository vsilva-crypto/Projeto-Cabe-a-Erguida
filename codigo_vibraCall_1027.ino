const int trigger = 8;
const int echo = 3;
const int motorVibracall = 10;

float duracao;
float dist;

void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(motorVibracall, OUTPUT);
}

void loop() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
 
  // Timeout de 30ms para o Arduino Nano não travar se o sensor falhar
  duracao = pulseIn(echo, HIGH, 30000);
  dist = duracao * 0.0172;
 
  Serial.print("Distancia = ");
  Serial.print(dist);
  Serial.println(" cm");

  // --- LÓGICA DO MOTOR COM TETO SEGURO (MÁXIMO 120) ---
  if (dist < 30 && dist > 0) {
    // Menor que 0,5m: Intensidade Máxima Segura para o pino
    analogWrite(motorVibracall, 100);
  }
  else if (dist >= 30 && dist < 60) {
    // Entre 0,5m e 1m: Intensidade Média
    analogWrite(motorVibracall, 80);
  }
  else if (dist >= 60 && dist < 80) {
    // Entre 1m e 1,5m: Intensidade Baixa
    analogWrite(motorVibracall, 65); // Motores vibracall geralmente não giram abaixo de 50~60
  }
  else {
    // Maior que 1,5m ou erro: Desligado
    analogWrite(motorVibracall, 0);
  }

  delay(1000);
}