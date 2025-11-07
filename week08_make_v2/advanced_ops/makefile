PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
OBJ_DIR=$(PROJ_DIR)/obj
INC_DIR=../include
LIB_DIR=../lib
CC=gcc
AR=ar

.PHONY: clean all

all: $(LIB_DIR)/libmyadvanced.a

$(LIB_DIR)/libmyadvanced.a: $(OBJ_DIR)/mymod.o $(OBJ_DIR)/mypow.o
	$(AR) -rv $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

clean: 
	rm -rf $(LIB_DIR)/libmyadvanced.a $(OBJ_DIR)/*.o