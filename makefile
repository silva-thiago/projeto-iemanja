# Makefile for "Projeto IEMANJA EDB1"
# Created by Bruno César
# 			 David Flanklin
#			 Eliaquin
#			 Thiago Silva
#			 Willian Talles
# Data: 25/06/2018
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
CPPFLAGS = -Wall -pedantic -ansi -std=c++11 -I$(INC)

# Lista dos arquivos objeto (.o) que formam o binario/executavel final
OBJS = $(OBJ)/expressao.o $(OBJ)/processa.o $(OBJ)/main.o

all: diretorios $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)

diretorios:
	$(MKDIR_P) $(DIR_CRT)

$(OBJ)/expressao.o: $(INC)/expressao.h
	$(CC) $(CPPFLAGS) -c $(SRC)/expressao.cpp -o $@

$(OBJ)/processa.o: $(OBJ)/expressao.o $(INC)/processa.h
	$(CC) $(CPPFLAGS) -c $(SRC)/processa.cpp -o $@

$(OBJ)/main.o: $(OBJ)/processa.o
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@

#########

# Alvo para a criação do arquivo Doxyfile.
doxy:
	doxygen -g

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doc:
	$(RM) $(DOC)/*
	doxygen ./Doxyfile

# Alvo para a compilação com informações de debug
# Altera a flag CPPFLAGS, incluindo as opções -g -O0 e recompila todo o projeto
debug: CPPFLAGS += -g -O0 
debug: all

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	@echo "Removendo arquivos objetos e executáveis contidos nas pastas ./build e ./bin, respectivamente... "
	$(RM) $(BIN)/* $(OBJ)/*
