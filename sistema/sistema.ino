const int sensorPin = A0; // Pino analógico conectado ao sensor fotoluminescente
const int buzzerPin = 3; // Pino digital conectado ao buzzer
const int redLedPin = 5; // Pino digital conectado ao LED vermelho
const int yellowLedPin = 6; // Pino digital conectado ao LED amarelo
const int greenLedPin = 7; // Pino digital conectado ao LED verde

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);//Define o pino sensorPin como entrada
  pinMode(buzzerPin, OUTPUT);//Define o pino buzzer  como saida
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  // Lê o valor do sensor fotoluminescente
  int ldrValue = analogRead(sensorPin);
  
  // Calcula a porcentagem do valor lido
  int ldrIntenc = map(ldrValue, 49, 969, 0, 100);

  // Verifica a faixa de porcentagem e controla os LEDs e o buzzer
  if (ldrIntenc <= 40) {//Lê a intensidade do LDR
    digitalWrite(greenLedPin, HIGH); //ativa o led verde
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  } else if (ldrIntenc > 40 && ldrIntenc <= 60) {//Se a intensidade do LDR estiver entre 40 e 60% executar os comandos abaixo
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);//ativa o led amarelo
    digitalWrite(redLedPin, LOW);
    tone(buzzerPin, 1000); // Ativa o buzzer
    delay(500); // Mantém o buzzer ativo por 3 segundos
    noTone(buzzerPin); // Desativa o buzzer
  } else {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, HIGH);//ativa o led vermelho
    tone(buzzerPin, 1000); // Ativa o buzzer
    delay(3000); // Mantém o buzzer ativo por 10 segundos
    noTone(buzzerPin); // Desativa o buzzer
  }
delay(500);//Da um delay de meio segundo entre cada iteração do programa
}
