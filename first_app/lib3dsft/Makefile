NAME = lib3dsft

SRCS =  ./clear_image.c ./draw_ellipse.c ./draw_rect.c ./put_pixel.c

OBJS = $(SRCS:c=.o)

CC = clang

HEAD = ./include/

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -c $(SRCS) -I $(HEAD)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c $(HEAD)
	$(CC) -c $(FLAG) $< -o $@

clean:
	@rm -fr $(OBJS)

fclean: clean
	@rm -fr $(NAME)
