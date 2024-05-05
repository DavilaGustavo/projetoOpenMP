             ,----------------, 
        ,-----------------------, 
      ,"                      ,"|   
     +-----------------------+  | 
     |  .-----------------.  |  | 
     |  |                 |  |  | 
     |  |                 |  |  |  
     |  |   Version 1.0   |  |  |
     |  |                 |  |  | 
     |  |                 |  |  |
     |  `-----------------'  |,"
     +-----------------------+ 
        /_)______________(_/ 

> [!IMPORTANT]
> O projeto não possui nenhum indicativo de loops recomendados por hardware, **utilize com cautela!**

# Instruções para Executar o Código:

Este código foi desenvolvido em C para testar a utilidade do multithreading, utilizando a biblioteca OpenMP para implementação paralela. Além disso, o projeto inclui um código em Python para gerar gráficos. Para executar o código e avaliar seu desempenho, siga as instruções abaixo:

## Compilador C:

Certifique-se de ter um compilador C instalado em sua máquina. Recomenda-se o uso de compiladores como o GCC (Linux), Clang (macOS), ou MinGW (Windows).

## Ambiente de Desenvolvimento Integrado (IDE):

Você pode usar qualquer ambiente de desenvolvimento integrado (IDE) de sua preferência que suporte desenvolvimento em C e Python, como Visual Studio Code, Code::Blocks, ou Eclipse.

## Bibliotecas Necessárias:

Certifique-se de que seu compilador C suporta a biblioteca OpenMP. A maioria dos compiladores modernos oferece suporte a OpenMP, mas pode ser necessário habilitar explicitamente a opção de compilação.
O código Python para gerar imagens utiliza as bibliotecas NumPy e Matplotlib. Certifique-se de ter essas bibliotecas instaladas em seu ambiente Python. Você pode instalar as bibliotecas usando pip:

> pip install numpy

> pip install matplotlib

## Compilação:

Abra um terminal ou prompt de comando no diretório onde o código-fonte C está localizado.

> cd "caminho/dos/arquivo"

Compile o código C usando o seguinte comando, habilitando a opção de compilação OpenMP:

### Para GCC (Linux):
> gcc exampleOpenMP.c -o example -fopenmp
> gcc finalOpenMP.c -o final -fopenmp

### Para Clang (macOS):
> clang exampleOpenMP.c -o example -fopenmp
> clang finalOpenMP.c -o final -fopenmp

### Para MinGW (Windows):
> gcc exampleOpenMP.c -o example -fopenmp
> gcc finalOpenMP.c -o final -fopenmp

## Execução:

Após a compilação bem-sucedida, execute o programa C com o seguinte comando:

> ./NomeDoExecutavel

## Observação:

Este projeto inclui um código em Python para gerar imagens, embora não seja o foco principal do estudo em multithreading. Certifique-se de ajustar os parâmetros e as operações conforme necessário para atender aos requisitos do seu teste de desempenho em Python.

Se encontrar algum problema durante a execução, verifique mensagens de erro específicas e ajuste conforme necessário.