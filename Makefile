#
# Compiler
#
CC = gcc

ALGDIR = ./Algorithms
COMMDIR = ./Common

CFLAGS = -I$(ALGDIR) -I$(COMMDIR) -Wall -Werror -Wextra
RELCFLAGS = -O3 -DNDEBUG

#
# Project files
#
SRCS = main.c \
       $(ALGDIR)/medianFilter.c \
       $(COMMDIR)/noiseGen.c

OBJS = $(SRCS:.c=.o)

EXE = ImageProcessing

#
# Release directory
#
RELDIR = release
RELEXE = $(RELDIR)/$(EXE)
RELOBJS = $(addprefix $(RELDIR)/,$(notdir $(OBJS)))


.PHONY: all clean remake prep

#
# Default
#
all: prep $(RELEXE)


#
# Link release executable
#
$(RELEXE): $(RELOBJS)
	$(CC) $(CFLAGS) $(RELCFLAGS) -o $@ $^


#
# Compile sources
#
$(RELDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(RELCFLAGS) $< -o $@

$(RELDIR)/%.o: $(ALGDIR)/%.c
	$(CC) -c $(CFLAGS) $(RELCFLAGS) $< -o $@
	
$(RELDIR)/%.o: $(COMMDIR)/%.c
	$(CC) -c $(CFLAGS) $(RELCFLAGS) $< -o $@

#
# Create release directory
#
prep:
	mkdir -p $(RELDIR)


#
# Cleanup
#
clean:
	rm -rf $(RELDIR)


#
# Rebuild
#
remake: clean all