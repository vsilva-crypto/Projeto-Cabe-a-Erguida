# Cabeça Erguida

Um boné com sensor de distância que vibra quando há um obstáculo na altura do rosto, feito para ajudar pessoas com deficiência visual a andar com mais segurança e autonomia.

Projeto da matéria PIC1.

Grupo: Eduardo Rinquier, João Victor, Luiz Miguel e Diogo Bazani.

## O problema

A bengala longa é a principal ferramenta de orientação de pessoas com deficiência visual, mas ela só detecta o que está perto do chão. Obstáculos suspensos, como placas, galhos e toldos, passam despercebidos e podem causar batidas no rosto, ferimentos e perda de confiança ao caminhar.

## A solução

Um boné estilo five panel, com aba curta, que tem um sensor de distância na frente, levemente inclinado para baixo, para monitorar a faixa do rosto. Uma placa Arduino lê o sensor e, quando há um obstáculo perto, aciona um motor de vibração.

A vibração é progressiva: quanto mais perto o obstáculo, mais rápida ela fica. Assim o usuário percebe a distância sem depender da visão.

## Como funciona

1. O sensor mede continuamente a distância até o que está à frente.
2. O Arduino compara essa distância com um limite de segurança.
3. Se houver obstáculo dentro do limite, o motor vibra.
4. Quanto mais perto o obstáculo, mais rápido é o ritmo da vibração.

## Componentes

- Placa Arduino Nano
- Sensor ultrassônico de distância
- Micro motor de vibração
- Transistor, resistores e diodo para acionar o motor com segurança
- Bateria de 9 V com chave liga/desliga
- Protoboard, jumpers e cabo USB

## Observações

- O motor é acionado por um transistor porque o Arduino não fornece corrente suficiente para ele.
- O ângulo do sensor deve ser ajustado em testes, para pegar a faixa do rosto sem detectar o chão.
- Os limites de distância e os ritmos da vibração também serão definidos nos testes.
