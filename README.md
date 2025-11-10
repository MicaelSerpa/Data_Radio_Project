# Data_Radio_Project

🧠 **Sistema de Aquisição e Comunicação Industrial**

📘 **Introdução**

Este projeto tem como objetivo o desenvolvimento de um sistema embarcado robusto para aquisição de dados, processamento local e comunicação industrial confiável.
O sistema é projetado para operar em ambientes industriais, garantindo alta precisão, baixa latência e resistência a ruídos eletromagnéticos.

⚙️ **Requisitos de Hardware**

O projeto requer um hardware robusto, capaz de operar de forma autônoma e com fonte de alimentação própria, fornecendo tensões intermediárias para os circuitos internos.

**Componentes Principais**

🔹 **STM32 (Microcontrolador Principal):**
Responsável pela aquisição e processamento de dados, leitura de sensores e controle das saídas digitais e analógicas.

Alta precisão nas entradas e saídas (I/O)

Baixo consumo de energia

Suporte a cálculos em tempo real

🔹 **ESP32 (Módulo de Comunicação):**
Utilizado para comunicação serial e sem fio, integrando-se com o módulo de rádio e o barramento RS485.

Alto desempenho de processamento

Conectividade Wi-Fi e Bluetooth

Flexibilidade de programação

🔹 **RS485 (Canal de Comunicação Serial Industrial):**
Empregado para comunicação confiável entre duas placas — a placa interna do painel e a placa externa conectada à antena.

Alta imunidade a ruídos industriais

Comunicação em longas distâncias

Protocolo diferencial balanceado

💻 **Software e Programação**

Linguagem: C / C++

Ambiente de Desenvolvimento: Arduino IDE

O firmware de cada microcontrolador é responsável por:

Leitura dos sensores via portas digitais e analógicas;

Processamento local dos dados (cálculos e filtragem);

Montagem e envio de pacotes de dados através dos canais seriais (UART/RS485);

Implementação dos protocolos de comunicação entre módulos.

🔧 **Estrutura de Comunicação**

O sistema opera em arquitetura mestre-escravo, onde:

O STM32 atua como módulo de aquisição e controle local;

O ESP32 realiza a ponte de comunicação com o mundo externo (rádio/RS485);

O canal RS485 garante a transmissão confiável entre os módulos, mesmo em ambientes com alto ruído eletromagnético.

🚀 **Próximos Passos**

 Implementar o firmware base para o STM32

 Integrar o ESP32 com o módulo RS485

 Testar o protocolo de comunicação serial

 Validar a precisão dos sensores em ambiente industrial

 Documentar o protocolo de troca de dados

🧩 **Contribuições**

Sinta-se à vontade para abrir issues, pull requests ou sugerir melhorias.
Toda contribuição é bem-vinda!

📄 **Licença**

Este projeto é distribuído sob a licença MIT. Consulte o arquivo LICENSE para mais detalhes.

## 🔄 Fluxograma de Comunicação do Sistema

```mermaid
flowchart LR
    subgraph TRANSMISSOR[📡 Lado Transmissor]
        A[Entradas Digitais e Analógicas] --> B[Placa de Leitura (STM32/ESP32)]
        B -->|Leituras| C[RS485 - Comunicação Serial]
        C --> D[Placa Intermediária]
        D -->|Pacote de Dados| E[Módulo de Rádio Transmissor]
    end

    subgraph RECEPTOR[🛰️ Lado Receptor]
        F[Módulo de Rádio Receptor] -->|Dados Recebidos| G[Placa Intermediária]
        G -->|RS485| H[Placa de Escrita (STM32/ESP32)]
        H --> I[Saídas Digitais e Analógicas]
    end

    style TRANSMISSOR fill:#e6f3ff,stroke:#0077cc,stroke-width:1px
    style RECEPTOR fill:#fff3e6,stroke:#cc7700,stroke-width:1px
