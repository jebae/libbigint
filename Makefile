# utils
KRED=\033[0;31m
KGRN=\033[0;32m
KYEL=\033[0;33m
KNRM=\033[0m
COUNTER = 0

define compile_obj
	printf "$(KGRN)[bigint]$(KNRM) compile $(1)\n"
	$(CC) $(CFLAGS) $(INCLUDES) -c $(1) -o $(2)
	$(eval COUNTER=$(shell echo $$(($(COUNTER) + 1))))
endef

# compiler
CC = gcc

# lib name
NAME = libbigint.a

# path
SRCDIR = srcs

OBJDIR = objs

INCDIR = includes

LIBFT_PATH = ../libft

# compiler options
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./$(INCDIR)\
	-I $(LIBFT_PATH)/includes\

LIBS = -L . -lbigint\
	-L $(LIBFT_PATH) -lft\

# srcs
SRCS = bi_new.c\
	bi_init.c\

# objs
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

# compile objs
HEADERS = $(INCDIR)/bigint.h\
	$(LIBFT_PATH)/includes/libft.h\

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

# build
all : $(NAME)

$(NAME) : pre_build $(OBJDIR) $(OBJS) post_build
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

pre_build :
	@printf "$(KGRN)[bigint] $(KYEL)build $(NAME)\n$(KNRM)"

post_build :
	@printf "$(KGRN)[bigint] $(KYEL)$(COUNTER) files compiled\n$(KNRM)"

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

# commands
test : all
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(SRCDIR)/__tests__/*.c test_main.c -o test

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all pre_build post_build clean fclean re