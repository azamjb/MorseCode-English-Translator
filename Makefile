DEPS = message.h
OBJS = main.o message.o

# Build objects

%.o: %.cc $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Build executable

main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) 

# Clean up

clean:
	rm -f main $(OBJS)