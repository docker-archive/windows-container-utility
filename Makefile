export CC=x86_64-w64-mingw32-g++
NULL_DEV=/dev/null
CFLAGS=-nostdinc -fno-exceptions -I/usr/x86_64-w64-mingw32/include -I/usr/lib/gcc/x86_64-w64-mingw32/8.3-win32/include -I/usr/lib/gcc/x86_64-w64-mingw32/6.3-win32/include -std=c++11 -static -DUNICODE -municode

containerutility.exe: argumentstream.cpp commands.cpp containerutility.cpp identity.cpp version.cpp argumentstream.h commands.h containerutility.h identity.h version.h Makefile
	@$(CC) $(CFLAGS) -O3 -s -o containerutility.exe argumentstream.cpp commands.cpp containerutility.cpp identity.cpp version.cpp

clean:
	-@rm containerutility.exe 2>$(NULL_DEV)

