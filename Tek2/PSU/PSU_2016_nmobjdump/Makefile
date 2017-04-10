
## Makefile for PSU_2016_nmNM_OBJdump in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_nmNM_OBJdump
##
## Made by Leo HUBERT
## Login   <leo.hubert@epitech.eu>
##
## Started on  Wed Feb 15 21:58:39 2017 Leo HUBERT
## Last update Wed Feb 15 21:58:39 2017 Leo HUBERT
##

CFLAGS	=	-W -Wall -Werror -Wextra -I./inc/nm/ -I./inc/objdump/ -I./inc/

NMFLAGS =

OBJDUMPFLAGS =

CC	=	gcc

MY_NM    =	my_nm

NM_DIR	=	./src/nm

NM_SRC	=	$(NM_DIR)/main.c	\
					$(NM_DIR)/symboles.c	\
					$(NM_DIR)/x64/symboles.c	\
					$(NM_DIR)/x32/symboles.c	\
					$(NM_DIR)/lib/lib_myputnbrbase.c \
					$(NM_DIR)/checker/base.c	\
					$(NM_DIR)/checker/header1.c \
					$(NM_DIR)/errors.c

MY_OBJDUMP    =	my_objdump

OBJDUMP_DIR	=	./src/objdump

OBJDUMP_SRC	=	$(OBJDUMP_DIR)/main.c \
							$(OBJDUMP_DIR)/lib.c \
							$(OBJDUMP_DIR)/x32/format.c \
 							$(OBJDUMP_DIR)/x64/format.c \
							$(OBJDUMP_DIR)/checker/base.c	\
							$(NM_DIR)/errors.c	\
							$(NM_DIR)/checker/base.c	\
							$(NM_DIR)/checker/header1.c

ECHO	=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"
YELLOW  =	"\033[1;33m"
FINISH  =       "\033[5;1;35m"

NM_OBJ	=	$(NM_SRC:.c=.o)
OBJDUMP_OBJ	=	$(OBJDUMP_SRC:.c=.o)

all: $(MY_NM)	$(MY_OBJDUMP)

nm: $(MY_NM)

objdump: $(MY_OBJDUMP)

clean:
		@rm -f $(NM_OBJ) $(OBJDUMP_OBJ) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(NM_OBJ) $(OBJDUMP_OBJ) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(NM_OBJ) $(OBJDUMP_OBJ) $(DEFAULT)

fclean:	clean
		@rm -f $(MY_NM) $(MY_OBJDUMP) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(MY_NM) $(MY_OBJDUMP) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(MY_NM) $(MY_OBJDUMP) $(DEFAULT)

re:	 fclean all


## Sound ----------------------------------------------------------------------

encore:
		@paplay include/sound/encore.ogg
blague:
		@paplay include/sound/humour.ogg &

## Compilation -----------------------------------------------------------------

$(MY_NM): $(NM_OBJ)
		@$(ECHO) $(YELLOW) "\nStart nm Compilation\n" $(DEFAULT)
		@$(CC) $(NM_OBJ) $(CFLAGS) $(NMFLAGS) -o $(MY_NM) && \
		$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $(NM_OBJ) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $(NM_OBJ) $(DEFAULT)
		@$(ECHO) $(FINISH) "\nCompilation Succesfully of "$(MY_NM) $(DEFAULT)

$(MY_OBJDUMP): $(OBJDUMP_OBJ)
		@$(ECHO) $(YELLOW) "\nStart objdump Compilation\n" $(DEFAULT)
		@$(CC) $(OBJDUMP_OBJ) $(CFLAGS) $(OBJDUMPFLAGS) -o $(MY_OBJDUMP) && \
		$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $(OBJDUMP_OBJ) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $(OBJDUMP_OBJ) $(DEFAULT)
		@$(ECHO) $(FINISH) "\nCompilation Succesfully of "$(MY_OBJDUMP) $(DEFAULT)

.PHONY: 	all nm objdump encore clean fclean re
