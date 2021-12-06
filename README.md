# Dice 3D 2.0

# Desenvolvedores
Héber Camacho Desterro RA: 11069416

## Projeto de Computação Gráfica - UFABC - 2021.3.
O projeto consiste num melhoramento da [primeira versão do jogo de dado em 3D](https://hebercamacho.github.io/dice-3D/dice), que já contava com a possibilidade de jogar um dado várias vezes e ter resultados aleatórios.
Nesta versão, a visualização é imersa num espaço tridimensional, utilizando a **Câmera LookAt**, e podemos ver os dados sendo jogados num cubo invisível de 5x5, sendo possível movimentar o cubo e a fonte de luz utilizando as funções do **Trackball Virtual**.
Clicando com o botão esquerdo do mouse em cada dado individual, é possível jogar apenas aquele dado, e pressionando o botão "Jogar todos!", é possível jogar todos os dados de uma única vez.
Além do botão de jogar todos, o menu inferior conta com uma Combo Box que te permite escolher quantos dados devem ser renderizados na tela, e um Slider que permite escolher ao mesmo tempo a velocidade de rotação e de translação (o que é muito conveniente pois dois monitores diferente podem aparentar ter velocidades diferentes com o mesmo valor selecionado).
As técnicas utilizadas para criar efeitos de melhor aparência e jogabilidade serão listadas abaixo.


Para renderização, foi utilizada as biblioteca [ABCg](https://github.com/hbatagelo/abcg) e suas dependências.

[Clique aqui para jogar](https://hebercamacho.github.io/dicetrack-3D/dicetrack)

## Técnicas Utilizadas
- [x] Rotação tridimensional em torno de cada um dos três eixos de forma independente, utilizando a função ``glm::rotate``
- [x] Translação para qualquer das três direções dentro da janela, utilizando a função ``glm::translate``
- [x] Carregamento de arquivo .obj para modelo do dado, na função ``Dices::loadObj``
- [x] Diferença de propriedades de reflexão entre diferentes materiais, usando arquivo .mtl (Material Template Library)
- [x] Texturização da superfície do dado, utilizando função ``Dices::loadDiffuseTexture`` com arquivo *laminado-cumaru.jpg* e utilizando **mapeamento planar** no fragment shader
    
![Textura de madeira laminado cumaru](./assets/maps/laminado-cumaru.jpg?raw=true)

- [x] Iluminação utilizando **modelo de reflexão de Blinn-Phong**, implementado no fragment shader
- [x] Utilização da função ``glm::distance`` para checar colisões dos dados com as paredes e entre os dados, evitando sobreposição e criando efeito e cubo invisível
- [x] Utilização da função ``glm::distance``, combinada com o cálculo da posição transformada de cada dado, e da posição transformada do clique do mouse, para girar apenas os dados clicados
- [x] Uso de números aleatórios para: 
    - resultado do dado, 
    - posição inicial, 
    - direção de translação, 
    - eixo a ser rotacionado,
    - tempo em que o dado permanecerá girando.
- [x] Botão da biblioteca ImGui para jogar todos os dados simultaneamente
- [x] Separação da classe Dice para gerar vários dados
- [x] Combo da biblioteca ImGui para decidir quantos dados gerar
- [x] Slider da biblioteca ImGui para decidir qual a velocidade de rotação e translação

