PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
OBJ_DIR=$(PROJ_DIR)/obj
INC_DIR=../include
LIB_DIR=../lib
CC=gcc
AR=ar

.PHONY: clean all

all: $(LIB_DIR)/libmybasic.a

$(LIB_DIR)/libmybasic.a: $(OBJ_DIR)/add.o $(OBJ_DIR)/sub.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/div.o
	$(AR) -rv $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

clean: 
	rm -rf $(LIB_DIR)/libmybasic.a $(OBJ_DIR)/*.o