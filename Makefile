export CC=x86_64-w64-mingw32-g++
NULL_DEV=/dev/null
CFLAGS=-fno-exceptions -std=c++11 -static -DUNICODE -municode

containerutility.exe: argumentstream.cpp commands.cpp containerutility.cpp identity.cpp version.cpp argumentstream.h commands.h containerutility.h identity.h version.h Makefile
	@$(CC) $(CFLAGS) -O3 -s -o containerutility.exe argumentstream.cpp commands.cpp containerutility.cpp identity.cpp version.cpp

clean:
	-@rm containerutility.exe 2>$(NULL_DEV)

