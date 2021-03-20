## Esp-WebServer-and-test-selenium

layout

## :rocket: Tecnologias
- PYTHON 3
- C++ para microcontrolador ( Arduino, Esp8266 )

## :computer: Funcionamento
- Sistema integrado com de uma placa chamada ESP8266, onde ela consegui fazer a criação de um servirdor web, a partir do Wi-Fi local (LOCAL IP). 
- O python com o selenium vai acessar o servidor web, gerado pela placa, que no caso será uma página HTML, onde tem dois botões um para ligar e desligar. Assim, o python está para automatizar esse processo ( ligar/desligar led ).

### Instalações necessárias
- Python:
   - [Download Python 3](https://python.org)
   - Bibliotecas utilizadas:
      - `pip install selenium`
      - `pip install webdriver_manager`

- ESP8266 (Primeiro comprar a placa, led's, resistores e cabos jumpers):
   - Para programa-la use:
      - [IDE arduino](https://arduino.cc)
      - [Biblioteca para o esp8266m, incluir em preferências na IDE](http://arduino.esp8266.com/stable/package_esp8266com_index.json) 