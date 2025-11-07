PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
OBJ_DIR=$(PROJ_DIR)/obj
INC_DIR=$(PROJ_DIR)/include
LIB_DIR=$(PROJ_DIR)/lib
BIN_DIR=$(PROJ_DIR)/bin
STATIC_LIBS=$(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a
LDFLAGS=-lmybasic -lmyadvanced
CC=gcc

.PHONY: basic_ops advanced_ops all clean

all: ./basic_ops ./advanced_ops $(BIN_DIR)/myapp

$(BIN_DIR)/%: $(SRC_DIR)/%.c $(STATIC_LIBS)
	$(CC) $< -I$(INC_DIR) -L$(LIB_DIR) $(LDFLAGS) -o $@

basic_ops: # lib/libmybasic.a 빌드
	$(MAKE) -C ./basic_ops

advanced_ops: # lib/libmyadvanced.a 빌드
	$(MAKE) -C ./advanced_ops

clean:
	rm -rf $(BIN_DIR)/* $(OBJ_DIR)/*
	$(MAKE) -C ./basic_ops clean
	$(MAKE) -C ./advanced_ops clean
