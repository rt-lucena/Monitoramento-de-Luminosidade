# Sistema de Monitoramento de Luminosidade com Arduino

## Descrição do Projeto

Este projeto é um sistema de monitoramento de luminosidade para a Vinheria Agnello. O sistema utiliza um Arduino e um sensor LDR (Light Dependent Resistor) para monitorar a luminosidade do ambiente onde os vinhos são armazenados. Além disso, o sistema possui um alarme com LEDs e um buzzer para indicar quando a luminosidade está OK, em nível de alerta ou quando há algum problema.

## Dependências

- Arduino Uno
- Sensor LDR
- Resistores
- LEDs (verde, amarelo e vermelho)
- Buzzer
- Cabos jumper

## Como Reproduzir

1. **Montagem do Circuito**: Monte o circuito de acordo com o esquema fornecido. Conecte o sensor LDR ao pino analógico A0 do Arduino. Conecte os LEDs aos pinos digitais 3 (verde), 4 (amarelo) e 5 (vermelho). Conecte o buzzer ao pino digital 6.

2. **Carregamento do Código**: Abra a IDE do Arduino e carregue o código fornecido para o Arduino.

3. **Monitoramento da Luminosidade**: Após o carregamento do código, o sistema começará a monitorar a luminosidade do ambiente. Os LEDs indicarão o estado da luminosidade e o buzzer será acionado quando a luminosidade estiver em nível de alerta.

## Suporte

Se você tiver alguma dúvida ou encontrar algum problema, por favor, abra uma issue neste repositório.

## Licença

Este projeto está licenciado sob a licença MIT.
