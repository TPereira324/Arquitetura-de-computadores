# 🔒 Projeto Arduino - Sistema de Segurança com RFID

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![IoT](https://img.shields.io/badge/IoT-Enabled-green?style=for-the-badge&logo=iot)

Sistema de segurança baseado em Arduino que simula o funcionamento de um leitor RFID com controle de acesso.

## 📋 Índice

- [Sobre o Projeto](#sobre-o-projeto)
- [Autores](#autores)
- [Componentes](#componentes)
- [Esquema de Ligação](#esquema-de-ligação)
- [Código Fonte](#código-fonte)
- [Funcionamento](#funcionamento)
- [Testes e Validação](#testes-e-validação)
- [Conclusão](#conclusão)

## 🎯 Sobre o Projeto

Este projeto foi desenvolvido para integrar com a infraestrutura de redes simulada anteriormente, criando um **sistema de controle de acesso** que utiliza Arduino para verificar a validade de cartões RFID.

**Objetivo principal**: Demonstrar conceitos fundamentais de arquitetura de computadores através de um sistema prático de entrada e saída.

## 👥 Autores

| Nome | Número de Estudante |
|------|---------------------|
| Hugo Barber | 20241660 |
| Maria Vargas | 20240999 |
| Taha-Wur Pereira | 20241694 |
| Sávio Casimira | 20240896 |

**Docente**: Alexandre Pereira  
**Curso**: Licenciatura em Engenharia Informática (LEIFD02)  
**Ano Letivo**: 2024-2025  
**UC**: Arquitetura de Computadores

## 🔧 Componentes Utilizados

| Componente | Pino Arduino | Função |
|------------|--------------|--------|
| LED | 12 | Indicador visual de acesso |
| Buzzer | 13 | Emissor de sinais sonoros |
| Botão | 7 | Simulador de cartão RFID |
| Sensor Digital | 8 | Verificador de autenticidade |

## 🔌 Esquema de Ligação

```
ARDUINO UNO
│
├── Pino 12 → LED (com resistor 220Ω)
├── Pino 13 → Buzzer
├── Pino 7 → Botão (pull-down)
└── Pino 8 → Sensor Digital
```

**Nota**: O botão funciona como substituto do cartão RFID para fins de demonstração.

## 💻 Código Fonte

```cpp
#define LED_PIN 12    // Define o pino para o LED
#define SOUND_PIN 13  // Define o pino para o som
#define BUTTON_PIN 7  // Define o pino para o botão
#define SENSOR_PIN 8  // Define o pino para o sensor (Digital)

bool lastButtonState = LOW;
bool currentButtonState = LOW;
bool ledState = LOW;
bool soundState = LOW;
bool sensorState = LOW;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(SOUND_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
    pinMode(SENSOR_PIN, INPUT);
    Serial.begin(9600);
}

void loop() {
    currentButtonState = digitalRead(BUTTON_PIN);
    sensorState = digitalRead(SENSOR_PIN);
    Serial.print("Sensor State: ");
    Serial.println(sensorState);

    if (currentButtonState == HIGH && lastButtonState == LOW) {
        if(sensorState == HIGH) { // Sensor ativo - Cartão VÁLIDO
            tone(SOUND_PIN, 880, 1000); // Tom mais alto
            digitalWrite(LED_PIN, HIGH);
            delay(500); // LED pisca mais rápido
            digitalWrite(LED_PIN, LOW);
        } else { // Sensor inativo - Cartão INVÁLIDO
            tone(SOUND_PIN, 440, 1000); // Tom normal
            digitalWrite(LED_PIN, HIGH);
            delay(1000); // LED pisca mais lento
            digitalWrite(LED_PIN, LOW);
        }
    }
    lastButtonState = currentButtonState;
}
```

## ⚙️ Funcionamento do Sistema

### 🟢 Cartão Válido (Sensor Ativo)
- **Som**: Tom alto (880Hz)
- **LED**: Pisca rapidamente (500ms)
- **Indicação**: Acesso permitido

### 🔴 Cartão Inválido (Sensor Inativo)
- **Som**: Tom normal (440Hz)
- **LED**: Pisca lentamente (1000ms)
- **Indicação**: Acesso negado

### 🔘 Botão
- Simula a apresentação do cartão RFID
- Detecta transição LOW→HIGH para ativar a verificação

## 🧪 Testes e Validação

### Procedimento de Teste
1. **Configuração inicial**: Upload do código para Arduino
2. **Teste do sensor**: Verificar estados HIGH/LOW via Serial Monitor
3. **Teste do botão**: Pressionar botão com sensor ativo/inativo
4. **Validação de saídas**: Confirmar LED e buzzer funcionando corretamente

### Resultados Esperados
- **Sensor HIGH** → LED rápido + som agudo
- **Sensor LOW** → LED lento + som grave
- **Serial Monitor** → Exibe estado do sensor em tempo real

## ✅ Conclusão

O projeto foi **implementado e testado com sucesso**, atendendo a todos os requisitos estabelecidos:

### 🎓 Aprendizados
- Manipulação de pinos de entrada/saída do Arduino
- Controle temporal com função `delay()`
- Estruturação de código em C++ para microcontroladores
- Integração de sensores digitais e atuadores
- Lógica condicional para controle de acesso

### 🔄 Integração com Projeto de Redes
Este sistema simula o **controle de acesso RFID** implementado na infraestrutura de rede do Tesouro Nacional.

### 🚀 Aplicações Futuras
- Sistemas de segurança reais com RFID
- Controle de acesso para edifícios inteligentes
- Integração com redes IoT
- Projetos mais complexos de automação

---

<div align="center">

**Desenvolvido no âmbito da UC de Arquitetura de Computadores**  
**2024-2025** • **Licenciatura em Engenharia Informática**

</div>
