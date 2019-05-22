# Geotree - Arvore genérica de figuras geométricas
Trabalho da disciplina Estruturas de Dados, PGG do IC-UFF.

## Enunciado

Trabalho Computacional: implementação das funções de árvores genéricas no número de filhos, árvores n-árias, 
e no tipo de informação armazenada, testando com as seguintes figuras geométricas: círculo, quadrado, retângulo, 
trapézio e triângulo:
* Deve ser permitido ao usuário do sistema: 
(a) buscar figuras geométricas, por meio de um código único; 
(b) imprimir informações relevantes, tanto da árvore, quanto das figuras, incluindo-se sua área; 
(c) inserir novas figuras; 
(d) retirar figuras, passando seus descendentes para outro pai; 
(e) destruir a árvore; 
(f) alterar as dimensões de figuras;
* Transformar a árvore genérica numa árvore binária de busca balanceada, baseando-se no código único;
* Converter a árvore genérica numa árvore B, baseando-se no código único;
* A entrada será fornecida por meio de arquivos texto. O arquivo texto será composto das seguintes informações, 
separadas por '/': código único, código único do pai (sendo que a raiz tem código do pai igual a zero) e as 
figuras geométricas, incluindo seu nome;
* as dimensões das figuras geométricas obedecerão ao seguinte padrão: 
(a) se a figura for um círculo ou um quadrado, uma única dimensão será informada (ou o raio, ou o lado, respectivamente); 
(b) se a figura for um triângulo ou um retângulo, as duas dimensões informadas serão a base e a altura;
(c) se a figura for um trapézio, três dimensões serão informadas, nessa ordem, base menor, base maior e altura;
* A estrutura deve ser totalmente destruída pelo seu programa antes da execução ser finalizada;

![Imagem da arvore genérica.](gentree.png)

Exemplo de entrada, dado por um arquivo:
```
1/0/TRI 3 2
2/1/RET 3 3
3/1/TRA 2 3 4
4/1/CIR 4
5/4/QUA 3
6/2/RET 2 2
7/5/TRA 1 2 3
8/5/CIR 2
9/4/QUA 1
10/1/TRI 1 2

```
PORÉM, SEU CÓDIGO DEVE FUNCIONAR COM QUALQUER ENTRADA QUE SEGUE O PADRÃO SUPRACITADO;
