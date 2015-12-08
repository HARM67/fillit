NAME=fillit
FLAG=-Wall -Werror -Wextra
LIB=libft.a
SRC=base.c exploit_piece.c grille.c main.c prepare_piece.c resolution.c tetri.c vecteur.c fillit.c base2.c
OBJ=base.o exploit_piece.o grille.o main.o prepare_piece.o resolution.o tetri.o vecteur.o fillit.o base2.o

all : $(NAME)

$(NAME) : $(SRC)
	gcc -c $(SRC) $(FLAG)
	gcc $(OBJ) $(FLAG) $(LIB) -o $(NAME)
	
clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
