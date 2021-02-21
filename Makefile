# Makefile for libasm, updated Sun Feb 21 16:55:39 JST 2021

SRC := ft_strcpy.s ft_strlen.s

OBJ := ft_strcpy.o ft_strlen.o

HDR := libasm.h

# DO NOT ADD OR MODIFY ANY LINES ABOVE THIS -- run 'make source' to add files

NAME := libasm.a

CC := gcc -g -fsanitize=address
AR := ar -rcs
NASM := nasm -fmacho64
RM := rm -fr

.PHONY:	all clean fclean re source test

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

test:
	$(CC) $(NAME) main.c
	./a.out

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
