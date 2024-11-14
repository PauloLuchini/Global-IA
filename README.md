# Projeto ESP32 com MQTT, DHT22 e Potenciômetro

Este projeto envolve o uso de um ESP32 para enviar dados de temperatura, umidade e consumo de energia via MQTT. O código foi desenvolvido para gerar valores simulados de temperatura e umidade a cada ciclo, utilizando o sensor DHT22 e um potenciômetro.

### Funcionalidades

- Leitura de temperatura e umidade (simulada).
- Leitura do valor do potenciômetro para calcular o consumo de energia.
- Envio dos dados via MQTT para um broker público.
- Monitoramento e visualização dos dados no Node-RED ou qualquer outro cliente MQTT.

---

## Requisitos

Antes de rodar o projeto, verifique se você tem as seguintes ferramentas e dependências instaladas:

- **Visual Studio Code (VSCode)**: Para editar e gerenciar o código.
  - [Download VSCode](https://code.visualstudio.com/)

- **PlatformIO**: Extensão para o VSCode que facilita o desenvolvimento de projetos embarcados com ESP32.
  - [Instalar PlatformIO](https://platformio.org/install/ide?install=vscode)

- **Wokwi Simulator**: Usado para simular os circuitos e o comportamento do ESP32.
  - [Wokwi - Simulador de Circuitos](https://wokwi.com/)

- **Bibliotecas do Projeto**:
  - **WiFi**: Para conectar o ESP32 à rede Wi-Fi.
  - **PubSubClient**: Para comunicação MQTT.
  - **DHT**: Para utilizar o sensor DHT22.

### Instalação das Bibliotecas

- Para instalar as bibliotecas no **PlatformIO**:
  
  1. Abra o VSCode.
  2. Vá para o painel do **PlatformIO** (ícone de "cog" no canto inferior esquerdo).
  3. Em **PIO Home**, clique em **Libraries** e procure pelas bibliotecas:
      - **WiFi** (já incluída no pacote do ESP32)
      - **PubSubClient** (para MQTT)
      - **DHT sensor library** (para trabalhar com o DHT22).
  
  Alternativamente, você pode adicionar as dependências diretamente no `platformio.ini`:
  
  ```ini
  [env:esp32dev]
  platform = espressif32
  board = esp32dev
  framework = arduino
  
  lib_deps = 
    WiFi
    PubSubClient
    DHT sensor library

## Como Rodar

### 1. Baixar o Repositório

Clone este repositório para o seu computador:

git clone https://github.com/SEU_USUARIO/SEU_REPOSITORIO.git

### 2. Abrir o Projeto no VSCode com PlatformIO

- Abra o VSCode e, no menu File > Open Folder, selecione a pasta do projeto que você acabou de clonar.
- Certifique-se de que o PlatformIO está instalado no VSCode.
- Abra o arquivo src/main.cpp para editar o código do ESP32.

### 3. Compilar e Carregar no ESP32
- No VSCode, com o PlatformIO, clique no ícone de seta para a direita (Build) para compilar o projeto.
- Após a compilação ser concluída, clique na seta para a direita (Upload) para carregar o código no ESP32.


## MQTT e Node-RED
O projeto está configurado para publicar dados nos seguintes tópicos MQTT:

- **empresa/sensor/temperatura**
- **empresa/sensor/umidade**
- **empresa/sensor/consumoenergia**

### 1. Utilizando o MQTT Explorer
- Abra o MQTT Explorer ou qualquer outro cliente MQTT.
- Conecte-se ao broker público test.mosquitto.org (ou use o broker de sua escolha).
- Inscreva-se nos tópicos mencionados acima para visualizar os dados em tempo real.
### 2. Criando um Dashboard no Node-RED
- Instale o Node-RED seguindo as instruções em node-red.org.
- Após a instalação, abra o Node-RED em localhost:1880.
- Crie flows para assinar os tópicos MQTT e visualizar os dados.
- Use nodes de Dashboard no Node-RED para criar gráficos e indicadores.

### 3.Flow node-red:
![image](https://github.com/user-attachments/assets/4e687d81-0dbe-47d2-b1eb-70ea2b1627be)


## Estrutura de Diretórios
O repositório contém os seguintes arquivos:


/
├── src/
│   └── main.cpp           # Código C++ para ESP32
├── platformio.ini         # Arquivo de configuração do PlatformIO
├── README.md              # Este arquivo



