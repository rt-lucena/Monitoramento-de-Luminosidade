// Definindo as variáveis e pinos
int ValorLDR; // Variável para armazenar a leitura do sensor LDR
int IntensidadeLuz; // Variável para armazenar a intensidade da luz em uma escala de 0 a 100
int pinoLDR = A0; // Pino analógico onde o LDR está conectado
int LED_VERDE = 3; // Pino onde o LED verde está conectado
int LED_AMARELO = 4; // Pino onde o LED amarelo está conectado
int LED_VERMELHO = 5; // Pino onde o LED vermelho está conectado
int BUZZER = 6; // Pino onde o buzzer está conectado

void setup() {
  Serial.begin(9600); // Inicia a comunicação serial a uma velocidade de 9600 bits por segundo
  pinMode(pinoLDR, INPUT); // Define o pino do LDR como entrada
  pinMode(LED_VERDE, OUTPUT); // Define o pino do LED verde como saída
  pinMode(LED_AMARELO, OUTPUT); // Define o pino do LED amarelo como saída
  pinMode(LED_VERMELHO, OUTPUT); // Define o pino do LED vermelho como saída
  pinMode(BUZZER, OUTPUT); // Define o pino do buzzer como saída
}

void loop() {
  ValorLDR = analogRead(pinoLDR); // Lê o valor do sensor LDR, que pode variar de 0 a 1023
  IntensidadeLuz = map(ValorLDR, 0, 1023, 0, 100); // Converte o valor lido para uma escala de 0 a 100

  // Imprime a intensidade da luz na porta serial
  Serial.print("Intensidade de Luz 0 - 1023 = ");
  Serial.println(ValorLDR);
  Serial.print("Intensidade de Luz 0 - 100% = ");
  Serial.println(IntensidadeLuz);

  // Verifica a intensidade da luz e acende o LED correspondente
  if(IntensidadeLuz < 45) {
    digitalWrite(LED_VERDE, HIGH); // Acende o LED verde
    digitalWrite(LED_AMARELO, LOW); // Apaga o LED amarelo
    digitalWrite(LED_VERMELHO, LOW); // Apaga o LED vermelho
  } else if(IntensidadeLuz >= 45 && IntensidadeLuz < 70) {
    digitalWrite(LED_VERDE, LOW); // Apaga o LED verde
    digitalWrite(LED_AMARELO, HIGH); // Acende o LED amarelo
    digitalWrite(LED_VERMELHO, LOW); // Apaga o LED vermelho
    tone(BUZZER, 500); // Liga o buzzer com uma frequência de 500 Hz
    delay(3000); // Espera 3 segundos
    noTone(BUZZER); // Desliga o buzzer
  } else if(IntensidadeLuz >= 70) {
    digitalWrite(LED_VERDE, LOW); // Apaga o LED verde
    digitalWrite(LED_AMARELO, LOW); // Apaga o LED amarelo
    digitalWrite(LED_VERMELHO, HIGH); // Acende o LED vermelho
    tone(BUZZER, 2000); // Liga o buzzer com uma frequência de 2000 Hz
    delay(3000); // Espera 3 segundos
    noTone(BUZZER); // Desliga o buzzer
  }
  delay(300); // Aguarda 300 milissegundos antes da próxima leitura
}
