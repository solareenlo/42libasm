# Makefile for libasm, updated Mon Feb 22 16:08:46 JST 2021

SRC := ft_list_size.s ft_read.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_strlen.s ft_write.s

OBJ := ft_list_size.o ft_read.o ft_strcmp.o ft_strcpy.o ft_strdup.o ft_strlen.o ft_write.o

HDR := libasm.h

# DO NOT ADD OR MODIFY ANY LINES ABOVE THIS -- run 'make source' to add files

NAME := libasm.a

CC := gcc -Wall -Wextra -Werror -g -fsanitize=address
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
	$(RM) Makefile.bak $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: re
	$(CC) $(NAME) main.c
	./a.out

bonus: all

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
