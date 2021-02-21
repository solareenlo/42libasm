# Makefile for libasm, updated Sun Feb 21 14:35:20 JST 2021

SRC := ft_strlen.s

OBJ := ft_strlen.o

HDR := libasm.h

# DO NOT ADD OR MODIFY ANY LINES ABOVE THIS -- run 'make source' to add files

NAME := libasm.a

AR := ar -rcs
NASM := nasm -fmacho64
RM := rm -fr

.PHONY:	all clean fclean re source

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
