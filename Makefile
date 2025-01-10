# Compiler and Flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Executable Names
SERVER_NAME = server
CLIENT_NAME = client

# Directories
SRCDIR = src
OBJDIR = obj

LIBFTDIR = libs/libft
FTPRINTF_DIR = libs/libftprintf

# Source Files
SERVER_SRC = server.c
CLIENT_SRC = client.c

# Object Files
SERVER_OBJ = $(SERVER_SRC:%.c=$(OBJDIR)/%.o)
CLIENT_OBJ = $(CLIENT_SRC:%.c=$(OBJDIR)/%.o)

# Libraries
LIBFT = $(LIBFTDIR)/libft.a
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a

# Rules for Building
all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJ) $(LIBFT) $(FTPRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -L$(LIBFTDIR) -lft -L$(FTPRINTF_DIR) -lftprintf -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJ) $(LIBFT) $(FTPRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -L$(LIBFTDIR) -lft -L$(FTPRINTF_DIR) -lftprintf -o $(CLIENT_NAME)

# Rule for Compiling Source Files to Object Files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(LIBFTDIR) -I$(FTPRINTF_DIR) -c $< -o $@

# Ensure Object Directory Exists
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Build Libraries
$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(FTPRINTF):
	$(MAKE) -C $(FTPRINTF_DIR)

# Clean Up
clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(FTPRINTF_DIR) clean

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(FTPRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
