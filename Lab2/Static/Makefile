CC=g++

SRCDIR=./src/
OBJDIR=./obj/
LIBDIR=./lib/

EXEC=out


# ar cr -c ompile static library

$(EXEC): $(addprefix $(OBJDIR),main.o  UserInterface.o) $(addprefix $(LIBDIR),libOwnerView.a libCarView.a libTaxiCompany.a)
	$(CC) -o $@ $(OBJDIR)main.o $(OBJDIR)UserInterface.o -L$(LIBDIR) -lOwnerView -lCarView -lTaxiCompany
	

$(LIBDIR)libOwnerView.a: $(addprefix $(OBJDIR),Owner.o OwnerView.o)
	ar cr $@ $^
	

$(LIBDIR)libCarView.a: $(addprefix $(OBJDIR), Owner.o Car.o CarView.o)
	ar cr $@ $^


$(LIBDIR)libTaxiCompany.a: $(addprefix $(OBJDIR), Car.o Owner.o TaxiCompany.o)
	ar cr $@ $^


$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CC) -c -o $@ $^


clean:
	rm -rf $(EXEC) $(OBJDIR)*.o $(LIBDIR)*.a
