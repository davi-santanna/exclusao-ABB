#### Problema 

Implemente a função TNoA *exclui(TNoA *raiz, int chave)  que recebe um ponteiro para a raiz de uma árvore binária de busca e uma chave a ser excluída da árvore, e retorna um ponteiro para a raiz da árvore modificada. 

Use o arquivo fornecido nesse exercício, pois ele já contém o tratamento de entrada e saída. 

#### Entrada: 
- Valores dos nós da árvore a ser percorrida. Os valores dos nós da árvore devem ser informados separados por traço, na ordem em que devem ser inseridos na árvore (o esqueleto fornecido já realiza a inserção). Na string de entrada, não pode haver espaço em branco entre o valor do nó e o traço que o separa do valor do próximo nó.
- Valor inteiro representando a chave do nó a ser excluído da árvore

#### Saída:
- árvore alterada

#### Exemplo1:

##### Entrada: 
100-200-20<BR/>
200

##### Saída:
```
100
--20
----vazio
----vazio
--vazio
```

#### Exemplo 2: 
##### Entrada:
400-300-500-150-200-450<BR/>
500

##### Saída:
```
400
--300
----150
------vazio
------200
--------vazio
--------vazio
----vazio
--450
----vazio
----vazio
```

#### Dicas Importantes:

- A entrada e a saída já são tratadas no arquivo fornecido para ler e imprimir os dados no formato esperado pela questão. Vocês devem APENAS implementar a função solicitada no problema
- Não use arquivos .h (coloque todas as definições de tipo no arquivo .c)
- Veja outras dicas em http://www.ic.uff.br/~vanessa/courses/runcodes.html
