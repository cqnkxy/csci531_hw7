OBJS = utility.o hw7.o rc4.o x1.o x2.o x3.o
CXXFLAGS = -g -Wall
CXX = g++

hw7: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o hw7 -lssl -lcrypto -L/usr/local/opt/openssl/lib

x1.o: x1.h x1.cpp
	$(CXX) $(CXXFLAGS) -c x1.cpp
x2.o: x2.h x2.cpp
	$(CXX) $(CXXFLAGS) -c x2.cpp
x3.o: x3.h x3.cpp
	$(CXX) $(CXXFLAGS) -c x3.cpp
rc4.o: rc4.h rc4.cpp
	$(CXX) $(CXXFLAGS) -c rc4.cpp -I/usr/local/opt/openssl/include
utility.o: utility.h utility.cpp
	$(CXX) $(CXXFLAGS) -c utility.cpp
hw7.o: hw7.cpp
	$(CXX) $(CXXFLAGS) -c hw7.cpp

clean:
	rm -f *.o *.gch hw7
