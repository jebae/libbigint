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
SRCS = bi_init.c\
	bi_del.c\
	bi_memalloc.c\
	bi_erase.c\
	bi_expand.c\
	bi_expand_at_least.c\
	bi_push.c\
	bi_copy.c\
	bi_abs_compare.c\
	bi_max_bit.c\
	bi_op_utils.c\
	bi_add_bi.c\
	bi_sub_bi.c\
	bi_update_occupied.c\
	bi_left_shift.c\
	bi_abs.c\
	bi_mod_n_pow_of_2_plus_1.c\
	bi_mod_n_pow_of_2_plus_1_utils.c\
	bi_array.c\
	bi_mul_bi.c\
	bi_right_shift.c\
	bi_strassen_mul_bi_utils.c\
	bi_strassen_mul_bi.c\
	bi_get_bit.c\
	bi_set_bit.c\
	bi_double_dabble.c\
	bi_rev_double_dabble.c\
	bcd_len.c\
	bcd_get_digit.c\
	bcd_set_digit.c\
	bcd_rm_trailing_zero.c\
	bcd_iter.c\
	bcd_round.c\
	bcd_add_digit.c\

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
