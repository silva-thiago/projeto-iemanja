# Makefile for "Projeto IEMANJA EDB1"
# Created by Bruno César
# 			 David Flanklin
#			 Eliaquin
#			 Thiago José
#			 Willian Talles
# Data:17/06/2018
#
# Makefile completo separando os diferentes elementos da aplicacao como codigo (src),
# cabecalhos (include), executáveis (build), bibliotecas (lib), etc.
# Cada elemento é alocado em uma pasta especifica, organizando melhor o codigo fonte.
#
# Algumas variáveis são usadas com significado especial:
#
# $@ nome do alvo (target)
# $^ lista com os nomes de todos os pre-requisitos sem duplicatas
# $< nome do primeiro pre-requisito
#

# Comandos do sistema operacional
# Linux: rm -rf 
# Windows: cmd //C del 
RM = rm -rf 

# Compilador
CC = g++

# Gerador de blibliotecas
# estáticas
AR = ar

# Variaveis para os subdiretorios
SRC = ./src
INC = ./include
BIN = ./bin
OBJ = ./build
LIB = ./lib
DOC = ./doc

# Criando estruturas de diretórios
MKDIR_P = mkdir -p

# Todos os diretórios da aplicação
DIR_CRT = $(BIN) $(OBJ) $(DOC) $(LIB)

# Define o nome do binario/executavel final
PROG = $(BIN)/iemanja

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean debug doxy doc

# Opcoes de compilacao
CPPFLAGS = -Wall -pedantic -std=c++11 -ansi -I$(INC)

# Alvo para a compilação com informações de debug
# Altera a flag CPPFLAGS, incluindo as opções -g -O0 e recompila todo o projeto
debug: CPPFLAGS += -g -O0 
debug: all

all: diretorios linux

diretorios:
	$(MKDIR_P) $(DIR_CRT)

#libs .a e .so para gerar bibliotecas para o linux
linux: expressao.a expressao.so iemanja_estatico iemanja_dinamico

windows: #libs .lib e .dll para gerar bibliotecas do windows

# LINUX

expressao.a: $(SRC)/expressao.cpp $(INC)/expressao.h
	$(CC) $(CPPFLAGS) -c $(SRC)/expressao.cpp -o $(OBJ)/expressao.o
	$(AR) rcs $(LIB)/$@ $(OBJ)/expressao.o
	@echo "+++ [Biblioteca estática criada em $(LIB)/$@] +++"

expressao.so: $(SRC)/expressao.cpp $(INC)/expressao.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/expressao.cpp -o $(OBJ)/expressao.o
	$(CC) -shared -fPIC -o $(LIB)/$@ $(OBJ)/expressao.o
	@echo "+++ [Biblioteca dinâmica criada em $(LIB)/$@] +++"

iemanja_estatico:
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp $(LIB)/expressao.a -o $(BIN)/$@

iemanja_dinamico:
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp $(LIB)/expressao.so -o $(BIN)/$@

#########

# WINDOWS

expressao.lib: $(SRC)/expressao.cpp $(INC)/expressao.h
	$(CC) $(CPPFLAGS) -c $(SRC)/expressao.cpp -o $(OBJ)/expressao.o
	$(AR) rcs $(LIB)/$@ $(OBJ)/expressao.o
	@echo "+++ [Biblioteca estática criada em $(LIB)/$@] +++"

expressao.dll: $(SRC)/expressao.cpp $(INC)/expressao.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/expressao.cpp -o $(OBJ)/expressao.o
	$(CC) -shared -fPIC -o $(LIB)/$@ $(OBJ)/expressao.o
	@echo "+++ [Biblioteca dinâmica criada em $(LIB)/$@] +++"

iemanja_estatico.exe:
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp $(LIB)/expressao.a -o $(BIN)/$@

iemanja_dinamico.exe:
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp $(LIB)/expressao.so -o $(BIN)/$@

########

# Alvo para a criação do arquivo Doxyfile.
doxy:
	doxygen -g

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doc:
	$(RM) $(DOC)/*
	doxygen ./Doxyfile

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	@echo "Removendo arquivos objetos e executáveis contidos nas pastas ./build e ./bin, respectivamente... "
	$(RM) $(BIN)/* $(OBJ)/*
