OpenGL-Visual Studio 2017 ("OpenGL"-D:/Document/C++/OpenGL)

Steps:
1. File -> New -> Project Visual C++ -> Empty Project -> "OpenGL"
2. Right Click -> Add -> New Item -> C++ File(.cpp)
3. Right Click -> Properties -> Property Pages -> C/C++ -> General -> Additional Include Directories -> Edit
	(locate where the OpenGL source path is)
4. Property Pages -> Linker -> Input -> Additional Dependencies -> Edit
	(write "freeglut.lib" and "glew32.lib")
5. Property Pages -> Linker -> General -> Additional Library Directories -> Edit
	(locate where the OpenGL source freeglut.dll and glew32.dll path is)
6. Right Click -> Open Folder in File Explorer -> Copy Paste freeglut.dll and glew32.dll
