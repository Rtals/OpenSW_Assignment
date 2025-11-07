.PHONY: all clean

PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
OBJ_DIR=$(PROJ_DIR)/obj
LIB_DIR=$(PROJ_DIR)/lib
INC_DIR=$(PROJ_DIR)/include
BIN_DIR=$(PROJ_DIR)/bin

OBJS=$(OBJ_DIR)/myadd.o $(OBJ_DIR)/mysub.o $(OBJ_DIR)/mymul.o $(OBJ_DIR)/mydiv.o $(OBJ_DIR)/mymod.o $(OBJ_DIR)/mypow.o

LIB_NAME=libmyops
LIB_REAL=$(LIB_NAME).so.1.0
LIB_SONAME=$(LIB_NAME).so.1
LIB_LINK=$(LIB_NAME).so

CC = gcc
CFLAGS = -fPIC
SHARED = -shared
MATH_LIB = -lm

$(BIN_DIR)/myapp: $(SRC_DIR)/myapp.c $(LIB_DIR)/$(LIB_LINK)
	$(CC) $< -L$(LIB_DIR) -lmyops -o $@ -I$(INC_DIR)

$(LIB_DIR)/$(LIB_REAL): $(OBJS)
	$(CC) $(CFLAGS) $(SHARED) $^ -Wl,-soname=$(LIB_SONAME) -o $@ $(MATH_LIB)

$(LIB_DIR)/$(LIB_SONAME): $(LIB_DIR)/$(LIB_REAL)
	ln -s $(LIB_REAL) $@

$(LIB_DIR)/$(LIB_LINK): $(LIB_DIR)/$(LIB_SONAME)
	ln -s $(LIB_SONAME) $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -rf $(OBJ_DIR)/* $(LIB_DIR)/* $(BIN_DIR)/*