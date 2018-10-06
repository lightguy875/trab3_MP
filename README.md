# Contador de linhas de código c/c++ com framework de teste gtest

# Observação
O arquivo Principal apenas roda o programa.cpp que está na pasta Sample que serve como teste para a aplicação principal

## Como compilar o software e o arquivo de teste

Para compilar o software e necessário estar na pasta Source e usar o seguinte comando:

```
$ make
```

Para compilar o arquivo de teste do software é necessário rodar o seguinte comando:

```
$make test
```

##Como rodar o programa principal

```
$make run
```

## Como rodar os testes e analisar a cobertura

Ainda na pasta de Source e necessário executar o seguinte código:

```
$ make run_test
```
Para ver a cobertura de testes

```
$ make gcov
```

## Como limpar o programa depois da execução
Para limpar a compilação é necessário rodar o seguinte comando:

```
$ make clean
```

Para limpar o arquivo de cobertura de testes:
```
$ make clean_coverage
```
Para limpar todos os arquivos compilados juntamente com os de cobertura
```
$ make clean_all
```

# Arquivos de documentação

## Site html
Para acessar o site contendo as informações do programa basta acessar o arquivo index.html a abri-lo com um navegador da pasta html contida dentro de cada pasta:


```
$ html/index.html
```

## Arquivo pdf
Para acessar o arquivo pdf basta entrar na pasta latex e abrir o arquivo refman contendo toda a documentação em arquivo latex:

```
$ latex/refman.pdf
```



