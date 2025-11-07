PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
OBJ_DIR=$(PROJ_DIR)/obj
INC_DIR=$(PROJ_DIR)/include
LIB_DIR=$(PROJ_DIR)/lib
BIN_DIR=$(PROJ_DIR)/bin

CC = gcc
ar = AR

.PHONY: clean basic all

all: $(BIN_DIR)/myapp

basic: $(LIB_DIR)/libmybasic.a

$(BIN_DIR)/myapp: $(OBJ_DIR)/myapp.o $(LIB_DIR)/libmybasic.a
	$(CC) $(OBJ_DIR)/myapp.o -L$(LIB_DIR) -lmybasic -o $(BIN_DIR)/myapp

$(LIB_DIR)/libmybasic.a: $(OBJ_DIR)/add.o $(OBJ_DIR)/sub.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/div.o
	$(AR) -rv $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

clean: 
	rm -rf $(OBJ_DIR)/*.o $(LIB_DIR)/* $(BIN_DIR)/*