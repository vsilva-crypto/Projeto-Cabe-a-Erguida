const int trigger = 8;
const int echo = 3;
const int motorVibracall = 10;
const int pinoBotao = 2;

float duracao;
float dist;

// Variáveis de controle do botão (Toggle)
bool sistemaAtivo = false;      // Começa desligado
int ultimoEstadoBotao = HIGH;   // Em pull-up, solto = HIGH

void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(motorVibracall, OUTPUT);
  pinMode(pinoBotao, INPUT_PULLUP); // Pull-up externo (botão no GND + resistor 10k nos 5V)
}

void loop() {
  int estadoAtualBotao = digitalRead(pinoBotao);

  // Detecta o momento em que o botão é pressionado (HIGH -> LOW)
  if (ultimoEstadoBotao == HIGH && estadoAtualBotao == LOW) {
    sistemaAtivo = !sistemaAtivo; // Inverte entre ligado e desligado

    if (sistemaAtivo) {
      Serial.println(">>> SISTEMA INICIADO <<<");
    } else {
      Serial.println(">>> SISTEMA FINALIZADO <<<");
      analogWrite(motorVibracall, 0); // Desliga o motor imediatamente
    }

    delay(200); // Debounce para evitar leitura dupla ao apertar
  }
  ultimoEstadoBotao = estadoAtualBotao;

  // Executa o sensor e o motor apenas quando estiver ativo
  if (sistemaAtivo) {
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
    if (dist < 50 && dist > 0) {
      analogWrite(motorVibracall, 100);
    }
    else if (dist >= 50 && dist < 80) {
      analogWrite(motorVibracall, 80);
    }
    else if (dist >= 80 && dist < 100) {
      analogWrite(motorVibracall, 65);
    }
    else {
      analogWrite(motorVibracall, 0);
    }

    delay(1000); // Atraso original de 1 segundo entre medições
  }
}
