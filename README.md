# Introdução: #

Este projeto tem como intenção implementar o jogo Keno que consiste em sortear 20 números aleatórios dentro do intervalo [1,80] e utiliza-los como um sorteio para com que o jogador (neste caso representado por um arquivo de entrada) possa apostar em um certo intervalo de números e receber uma pontuação (neste caso dinheiro) de acordo com sua quantidade de acertos.

# Implementação: #

O projeto conta com as classes **Gamemaneger, Keno, Player** e a biblioteca **tools** que contém algorítimos de ordenaçao, remoção de números repetidos e a função que irá ler o arquivo do jogador.

## Classe Gamemaneger: ##

Esta classe é responsável por guardar a tabela de reconpensa e o dinheiro apostado. <br />

Ela também realiza a verificação dos acertos e computa a bonificação que o jogador irá receber baseado em sua aposta.

## Classe Keno: ##

Esta classe é responsável por gerar os 20 valores aleatórios e armazená-los para a comparação do Gamemaneger.

## Classe Player: ##

Esta classe é responsável por guardar os dados do jogador (dinheiro e aposta) e modificá-los conforme as recompensas geradas pelo Gamemaneger.

# Compilação e execução: #

Para compilar o código basta digitar o comando **make** e logo após, basta digitar **./Keno arquivo-de-entrada** onde o arquivo de entrada segue o formato: <br />

M<br/>
NB<br/>
A B C D...<br/>

Onde **M** é o dinheiro inicial do jogador, **NB** é a quantidade de apostas e **A B C D...** são os números que o jogador deseja apostar

# Autoria: #

Todos os códigos aqui implementados foram desenvolvidos por [Kevin Wallacy de Souza Maciel](https://github.com/kevinwall) (Email de contato: <kevinwall@ufrn.edu.br>) e [Giovanne da Silva Santos](https://github.com/GSDante) (Email de contato: <giovannedssantos@gmail.com>) 

&copy; IMD/UFRN 2018-2019
