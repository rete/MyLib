CC          = g++
LDFLAGS      = -Wall -W
CXXFLAGS     = -Wall -W
EXEC         = example

SRC          = menu.C \
			   Option.C \
			   OptionLayout.C \
			   main.C

HEADERS      = menu.h \
			   Option.h \
			   OptionLayout.h

OBJ          = $(SRC:.C=.o)

all          : $(EXEC)

main.o       : $(HEADERS)

$(EXEC)      : $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(LDFLAGS)

%.o          : %.C
	$(CC) -o $@ -c  $< $(CXXFLAGS)

clean        :
	rm -f *.o

mrproper     : clean
	rm -f $(EXEC)