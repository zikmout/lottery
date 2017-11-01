all: loto.c
	gcc -o loto loto.c libft.a
clean:
	rm loto
