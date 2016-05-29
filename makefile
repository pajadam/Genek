#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = %cd%

CC = gcc.exe
CXX = g++.exe
AR = ar.exe
LD = g++.exe
WINDRES = windres.exe

INC = 
CFLAGS = -fexpensive-optimizations -O3 -Wall -std=c++14
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = -s

INC_WINDOWS = $(INC) -Ilib\Windows\include
CFLAGS_WINDOWS = $(CFLAGS)
RESINC_WINDOWS = $(RESINC)
RCFLAGS_WINDOWS = $(RCFLAGS)
LIBDIR_WINDOWS = $(LIBDIR) -Llib\Windows\lib
LIB_WINDOWS = $(LIB)-lnana -lgdi32 -lcomdlg32
LDFLAGS_WINDOWS = $(LDFLAGS)
OBJDIR_WINDOWS = obj\\Windows
DEP_WINDOWS = 
OUT_WINDOWS = bin\\Windows\\Genek.exe

OBJ_WINDOWS = $(OBJDIR_WINDOWS)\\src\\res\\icon.o $(OBJDIR_WINDOWS)\\src\\noise\\ppm.o $(OBJDIR_WINDOWS)\\src\\noise\\PerlinNoise.o $(OBJDIR_WINDOWS)\\src\\main.o $(OBJDIR_WINDOWS)\\src\\logger\\time.o $(OBJDIR_WINDOWS)\\src\\logger\\logger.o $(OBJDIR_WINDOWS)\\src\\gui\\gui.o $(OBJDIR_WINDOWS)\\src\\core\\generatorSurface.o $(OBJDIR_WINDOWS)\\src\\core\\generatorPlayerSpawn.o $(OBJDIR_WINDOWS)\\src\\core\\generatorMaterials.o $(OBJDIR_WINDOWS)\\src\\core\\generatorHeightMap.o $(OBJDIR_WINDOWS)\\src\\core\\generatorBridge.o $(OBJDIR_WINDOWS)\\src\\core\\generatorBorder.o $(OBJDIR_WINDOWS)\\src\\core\\export.o $(OBJDIR_WINDOWS)\\src\\core\\core.o

all: windows

clean: clean_windows

before_windows: 
	cmd /c if not exist bin\\Windows md bin\\Windows
	cmd /c if not exist $(OBJDIR_WINDOWS)\\src\\res md $(OBJDIR_WINDOWS)\\src\\res
	cmd /c if not exist $(OBJDIR_WINDOWS)\\src\\noise md $(OBJDIR_WINDOWS)\\src\\noise
	cmd /c if not exist $(OBJDIR_WINDOWS)\\src md $(OBJDIR_WINDOWS)\\src
	cmd /c if not exist $(OBJDIR_WINDOWS)\\src\\logger md $(OBJDIR_WINDOWS)\\src\\logger
	cmd /c if not exist $(OBJDIR_WINDOWS)\\src\\gui md $(OBJDIR_WINDOWS)\\src\\gui
	cmd /c if not exist $(OBJDIR_WINDOWS)\\src\\core md $(OBJDIR_WINDOWS)\\src\\core

after_windows: 
	scripts\release_windows.bat

windows: before_windows out_windows after_windows

out_windows: before_windows $(OBJ_WINDOWS) $(DEP_WINDOWS)
	$(LD) $(LIBDIR_WINDOWS) -o $(OUT_WINDOWS) $(OBJ_WINDOWS)  $(LDFLAGS_WINDOWS) $(LIB_WINDOWS)

$(OBJDIR_WINDOWS)\\src\\res\\icon.o: src\\res\\icon.rc
	$(WINDRES) -i src\\res\\icon.rc -J rc -o $(OBJDIR_WINDOWS)\\src\\res\\icon.o -O coff $(INC_WINDOWS)

$(OBJDIR_WINDOWS)\\src\\noise\\ppm.o: src\\noise\\ppm.cpp
	$(CXX) $(CFLAGS_WINDOWS) $(INC_WINDOWS) -c src\\noise\\ppm.cpp -o $(OBJDIR_WINDOWS)\\src\\noise\\ppm.o

$(OBJDIR_WINDOWS)\\src\\noise\\PerlinNoise.o: src\\noise\\PerlinNoise.cpp
	$(CXX) $(CFLAGS_WINDOWS) $(INC_WINDOWS) -c src\\noise\\PerlinNoise.cpp -o $(OBJDIR_WINDOWS)\\src\\noise\\PerlinNoise.o

$(OBJDIR_WINDOWS)\\src\\main.o: src\\main.cpp
	$(CXX) $(CFLAGS_WINDOWS) $(INC_WINDOWS) -c src\\main.cpp -o $(OBJDIR_WINDOWS)\\src\\main.o

$(OBJDIR_WINDOWS)\\src\\logger\\time.o: src\\logger\\time.cpp
	$(CXX) $(CFLAGS_WINDOWS) $(INC_WINDOWS) -c src\\logger\\time.cpp -o $(OBJDIR_WINDOWS)\\src\\logger\\time.o

$(OBJDIR_WINDOWS)\\src\\logger\\logger.o: src\\logger\\logger.cpp
	$(CXX) $(CFLAGS_WINDOWS) $(INC_WINDOWS) -c src\\logger\\logger.cpp -o $(OBJDIR_WINDOWS)\\src\\logger\\logger.o

$(OBJDIR_WINDOWS)\\src\\gui\\gui.o: src\\gui\\gui.cpp
	$(CXX) $(CFLAGS_WINDOWS) $(INC_WINDOWS) -c src\\gui\\gui.cpp -o $(OBJDIR_WINDOWS)\\src\\gui\\gui.o

$(OBJDIR_WINDOWS)\\src\\core\\generatorSurface.o: src\\core\\generatorSurface.cpp
	$(CXX) $(CFLAGS_WINDOWS) $(INC_WINDOWS) -c src\\core\\generatorSurface.cpp -o $(OBJDIR_WINDOWS)\\src\\core\\generatorSurface.o

$(OBJDIR_WINDOWS)\\src\\core\\generatorPlayerSpawn.o: src\\core\\generatorPlayerSpawn.cpp
	$(CXX) $(CFLAGS_WINDOWS) $(INC_WINDOWS) -c src\\core\\generatorPlayerSpawn.cpp -o $(OBJDIR_WINDOWS)\\src\\core\\generatorPlayerSpawn.o

$(OBJDIR_WINDOWS)\\src\\core\\generatorMaterials.o: src\\core\\generatorMaterials.cpp
	$(CXX) $(CFLAGS_WINDOWS) $(INC_WINDOWS) -c src\\core\\generatorMaterials.cpp -o $(OBJDIR_WINDOWS)\\src\\core\\generatorMaterials.o

$(OBJDIR_WINDOWS)\\src\\core\\generatorHeightMap.o: src\\core\\generatorHeightMap.cpp
	$(CXX) $(CFLAGS_WINDOWS) $(INC_WINDOWS) -c src\\core\\generatorHeightMap.cpp -o $(OBJDIR_WINDOWS)\\src\\core\\generatorHeightMap.o

$(OBJDIR_WINDOWS)\\src\\core\\generatorBridge.o: src\\core\\generatorBridge.cpp
	$(CXX) $(CFLAGS_WINDOWS) $(INC_WINDOWS) -c src\\core\\generatorBridge.cpp -o $(OBJDIR_WINDOWS)\\src\\core\\generatorBridge.o

$(OBJDIR_WINDOWS)\\src\\core\\generatorBorder.o: src\\core\\generatorBorder.cpp
	$(CXX) $(CFLAGS_WINDOWS) $(INC_WINDOWS) -c src\\core\\generatorBorder.cpp -o $(OBJDIR_WINDOWS)\\src\\core\\generatorBorder.o

$(OBJDIR_WINDOWS)\\src\\core\\export.o: src\\core\\export.cpp
	$(CXX) $(CFLAGS_WINDOWS) $(INC_WINDOWS) -c src\\core\\export.cpp -o $(OBJDIR_WINDOWS)\\src\\core\\export.o

$(OBJDIR_WINDOWS)\\src\\core\\core.o: src\\core\\core.cpp
	$(CXX) $(CFLAGS_WINDOWS) $(INC_WINDOWS) -c src\\core\\core.cpp -o $(OBJDIR_WINDOWS)\\src\\core\\core.o

clean_windows: 
	cmd /c del /f $(OBJ_WINDOWS) $(OUT_WINDOWS)
	cmd /c rd bin\\Windows
	cmd /c rd $(OBJDIR_WINDOWS)\\src\\res
	cmd /c rd $(OBJDIR_WINDOWS)\\src\\noise
	cmd /c rd $(OBJDIR_WINDOWS)\\src
	cmd /c rd $(OBJDIR_WINDOWS)\\src\\logger
	cmd /c rd $(OBJDIR_WINDOWS)\\src\\gui
	cmd /c rd $(OBJDIR_WINDOWS)\\src\\core

.PHONY: before_windows after_windows clean_windows

