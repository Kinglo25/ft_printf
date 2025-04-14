NAME			=	libftprintf.a

SRCS			=	fill_flags_struct.c ft_printf_utils.c printf_str.c \
					ft_printf_utils2.c ft_printf.c printf_char.c printf_ui.c \
					printf_dec_int.c printf_hexa.c printf_ptr.c printf_percent.c

OBJS			=	$(SRCS:c=o)

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

all:		$(OBJS) $(NAME)

%.o:		%.c
				@echo "Compiling $<"
				@$(CC) $(CFLAGS) -c -I. $< -o $(<:c=o)
				@echo "Compiling OK!"

$(NAME):
				@echo "Creating library..." 
				@ar -rcs $@ $(OBJS)
				@echo "Job's done!"

clean:
				@echo "Cleaning objects..."
				@rm -f $(OBJS) $(BONUS_OBJS)
				@echo "Cleaned up!"

fclean:		clean
				@echo "Cleaning library..."
				@rm -f $(NAME)
				@echo "Cleaned up!"

bonus: all

re:			fclean all

.PHONY:		all clean fclean re bonus 