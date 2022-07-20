TARGET=add-nbo
CXXFLAGS=-g

all: $(TARGET)

$(TARGET): add-nbo.cpp
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f $(TARGET)
	rm -f *.o

