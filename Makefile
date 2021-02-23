# Makefile for libasm, updated Tue Feb 23 12:34:27 JST 2021

SRC := ft_read.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_strlen.s ft_write.s

OBJ := ft_read.o ft_strcmp.o ft_strcpy.o ft_strdup.o ft_strlen.o ft_write.o

HDR := libasm.h

# DO NOT ADD OR MODIFY ANY LINES ABOVE THIS -- run 'make source' to add files

SRC_BONUS := ft_list_size.s
OBJ_BONUS := ft_list_size.o
HDR := libasm_bonus.h

NAME := libasm.a

CC := gcc -g -fsanitize=address
CC += -Wall -Wextra -Werror
AR := ar -rcs
RM := rm -fr
ifeq ($(shell uname), Darwin)
	NASM := nasm -fmacho64 -DMACOS
else
	NASM := nasm -felf64
endif

.PHONY:	all clean fclean re source test bonus

all: $(NAME)

# Compiling
%.o: %.s
	$(NASM) $< -o $@

# Linking
$(NAME): $(OBJ)
	$(AR) $@ $^

clean:
	$(RM) Makefile.bak $(OBJ) $(OBJ_BONUS) a.out

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: re
	$(CC) main.c $(NAME)
	./a.out

test_bonus: bonus
	$(CC) main_bonus.c $(NAME)
	./a.out

bonus: $(NAME) $(OBJ_BONUS)
	$(AR) $(NAME) $(OBJ_BONUS)

source:
	@mv Makefile Makefile.bak
	@echo "# Makefile for libasm, updated `date`" > Makefile
	@echo '' >> Makefile
	@echo SRC := `ls *.s` >> Makefile
	@echo '' >> Makefile
	@echo OBJ := `ls *.s | sed s/s$$/o/` >> Makefile
	@echo '' >> Makefile
	@echo HDR := `ls *.h` >> Makefile
	@echo '' >> Makefile
	@sed -n -e '/^# DO NOT ADD OR MODIFY/,$$p' < Makefile.bak >> Makefile
