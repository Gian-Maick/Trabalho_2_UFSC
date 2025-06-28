CC = gcc
TARGET = trabalho_time_v2
SOURCE = ./src
INCLUDE = ./include
OBJETOS = ./objs

all: obj
	$(CC) $(OBJETOS)/utils.o $(OBJETOS)/menus.o $(OBJETOS)/files.o $(OBJETOS)/cadastros.o $(OBJETOS)/relatorios.o $(OBJETOS)/buscas.o $(OBJETOS)/trabalho_time_fut_V2.o -o $(TARGET)


obj:
	$(CC) -c $(SOURCE)/utils.c -o $(OBJETOS)/utils.o
	$(CC) -c $(SOURCE)/menus.c -o $(OBJETOS)/menus.o
	$(CC) -c $(SOURCE)/files.c -o $(OBJETOS)/files.o
	$(CC) -c $(SOURCE)/cadastros.c -o $(OBJETOS)/cadastros.o
	$(CC) -c $(SOURCE)/relatorios.c -o $(OBJETOS)/relatorios.o
	$(CC) -c $(SOURCE)/buscas.c -o $(OBJETOS)/buscas.o
	$(CC) -c trabalho_time_fut_V2.c -o $(OBJETOS)/trabalho_time_fut_V2.o


clear:
	rm $(TARGET)
	rm $(OBJETOS)/*.o