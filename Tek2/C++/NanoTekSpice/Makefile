##
## Makefile for  in /home/hubert_i/Shared/C++_2016/cpp_nanotekspice
##
## Made by Leo HUBERT
## Login   <leo.hubert@epitech.eu>
##
## Started on  Wed Feb  1 17:41:09 2017 Leo HUBERT
## Last update Mon Feb 13 14:33:18 2017 Loic Lopez
##

CFLAGS	+=	-W -Wall -Werror -I./include

CC	=	g++

LIB	=	-L./ -l$(NAME)

NAME    =	nanotekspice
LIBNAME	=	libnanotekspice.a

ARRC	=	ar rc

SRC	=	sources/main.cpp
SRCS	=	sources/class/Parser.cpp
SRCS	+=	sources/class/Exception.cpp
SRCS	+=	sources/class/Component.cpp

##
##	COMPONENTS SECTION
##

SRCS	+=	sources/class/component/4001.cpp
SRCS	+=	sources/class/component/4081.cpp
SRCS	+=	sources/class/component/4011.cpp
SRCS	+=	sources/class/component/4030.cpp
SRCS	+=	sources/class/component/4069.cpp
SRCS	+=	sources/class/component/4071.cpp

ECHO	=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"
YELLOW  =	"\033[1;33m"
FINISH  =       "\033[5;1;35m"

OBJ	=	$(SRC:.cpp=.o)
OBJS	=	$(SRCS:.cpp=.o)

all:		$(NAME)

clean:
		@rm -f $(OBJ) $(OBJS) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(OBJ) $(OBJS) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(OBJ) $(OBJS) $(DEFAULT)

fclean:		clean
		@rm -f $(NAME) $(LIBNAME) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(LIBNAME) $(NAME) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(LIBNAME) $(NAME) $(DEFAULT)

re:	 encore fclean all


## Sound ----------------------------------------------------------------------

encore:
		@paplay include/sound/encore.ogg &
blague:
		@paplay include/sound/humour.ogg &

## Compilation -----------------------------------------------------------------

$(NAME): $(OBJS) $(OBJ)

		@$(ARRC) $(LIBNAME) $(OBJS) && \
		$(ECHO) $(GREEN) "[AR]" $(TEAL) $(LIBNAME) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR]" $(TEAL) $(OBJS) $(DEFAULT)
		@ranlib $(LIBNAME) && \
		$(ECHO) $(GREEN) "[OK]" $(TEAL) $(LIBNAME) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR]" $(TEAL) $(LIBNAME) $(DEFAULT)


		@$(CC) $(OBJ) $(LIB) $(CFLAGS) -o $(NAME) && \
		$(ECHO) $(GREEN) "[OK] g++" $(TEAL) $(SRC) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] g++" $(TEAL) $(SRC) $(DEFAULT)
		@$(ECHO) $(FINISH) "\nCompilation Succesfully of "$(NAME) $(DEFAULT)
		@paplay include/sound/end.ogg &

%.o:		%.cpp
		@$(CC) -c $^ -o $@ $(CFLAGS) && \
		$(ECHO) $(GREEN) "[OK] g++" $(TEAL) $^ $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] g++" $(TEAL) $^ $(DEFAULT)

.PHONY: 	all encore clean fclean re
