CPPFLAGG = g++ -g -Wall
OFILE = src/*.cpp -Iinclude/ -o $(basename filename).o
DEBUG = src/*.cpp -Iinclude/ -o bin/DebugMain.exe
REALEASE = -mwindows src/*.cpp -Iinclude/ -o bin/FunctionGraph.exe #Give file name, remove -m if no separate window
SDL = -IC:/Soft/SDL3-3.2.4/x86_64-w64-mingw32/include/ -LC:/Soft/SDL3-3.2.4/x86_64-w64-mingw32/lib/ -lSDL3.dll
SDLIMAGE = -IC:/Soft/SDL3_image-3.2.0/x86_64-w64-mingw32/include/ -LC:/Soft/SDL3_image-3.2.0/x86_64-w64-mingw32/lib/ -lSDL3_image.dll
SDLTTF = -IC:/Soft/SDL3_ttf-3.2.0/x86_64-w64-mingw32/include/ -LC:/Soft/SDL3_ttf-3.2.0/x86_64-w64-mingw32/lib/ -lSDL3_ttf.dll

ARGS:=""

standard:
	$(CPPFLAGG) $(DEBUG) $(SDL)

Realease: Clean
	$(CPPFLAGG) $(REALEASE) $(SDL)


Vic:
	$(CPPFLAGG) ./src/Vic/Vic.cpp -o ./bin/utils/vic.exe

VicExe:
	./bin/utils/vic.exe $(ARGS)


Test: 
	./bin/DebugMain.exe $(ARGS)

Gdb: 
	gdb ./bin/DebugMain.exe


Clean:
	rm -f bin/*.exe
	rm -f src/*.o


Update: Realease VicExe
	git add -A
	git commit

GitPush: Update
	git push