CC=g++

SRCDIR=./src/
OBJDIR=./obj/
LIBDIR=./lib/

EXEC=out


# fPIC computer instruction dependent of concrete memoty lines. Goto instruction bind no to memory cells but to shifts(+10 +100 etc..)
# -L points where libraries are located
# -lsmth connect to binary specific library
# -Wl enable weird type of parameters
# -rpath - indicates where our dynamic libraries are located when we start runtime. Withou this parameter yo can easely compile your binary but it will not work out properly
# -shared - compiles dynamic library

$(EXEC): $(addprefix $(OBJDIR),main.o  UserInterface.o) $(addprefix $(LIBDIR),libOwnerView.so libCarView.so libTaxiCompany.so)
	$(CC) -o $@ $(OBJDIR)main.o $(OBJDIR)UserInterface.o -L$(LIBDIR) -lOwnerView -lCarView -lTaxiCompany -Wl,-rpath=${LIBDIR} 
	

$(LIBDIR)libOwnerView.so: $(addprefix $(OBJDIR),Owner.o OwnerView.o)
	$(CC) -shared -o $@ $^
	

$(LIBDIR)libCarView.so: $(addprefix $(OBJDIR), Owner.o Car.o CarView.o)
	$(CC) -shared -o $@ $^


$(LIBDIR)libTaxiCompany.so: $(addprefix $(OBJDIR), Car.o Owner.o TaxiCompany.o)
	$(CC) -shared -o $@ $^


$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CC) -c -fPIC -o $@ $^


clean:
	rm -rf $(EXEC) $(OBJDIR)*.o $(LIBDIR)*.so
