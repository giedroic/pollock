CFLAGS = -Wall -Wextra -Werror -g -I minilibx-linux -I /usr/include -I include -O3

LDFLAGS = -L minilibx-linux -L /usr/lib

LDLIBS = -l mlx -l Xext -l X11 -l m -l z

MKDIR = mkdir -p
RMDIR = rm -rf

NAME = pollock
NAME := $(addprefix bin/,$(NAME))

BIN_DIR = bin/
OBJ_DIR = obj/

POLLOCK_OBJ = obj/pollock.o

.PHONY : all minilibx-linux clean fclean re

all : minilibx-linux $(OBJ_DIR) $(BIN_DIR) $(NAME)

bin/pollock: $(POLLOCK_OBJ)
	$(CC) $< $(LDFLAGS) -o $@ $(LDLIBS)

obj/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

minilibx-linux :
	$(MAKE) -C minilibx-linux

$(OBJ_DIR) :
	$(MKDIR) $@	

$(BIN_DIR) :
	$(MKDIR) $@

clean :
	$(MAKE) -C minilibx-linux clean
	$(RM) $(POLLOCK_OBJ)
	$(RMDIR) $(OBJ_DIR)

fclean :
	$(MAKE) -C minilibx-linux clean
	$(RM) $(POLLOCK_OBJ) $(NAME)
	$(RMDIR) $(OBJ_DIR) $(BIN_DIR)

re : fclean all
