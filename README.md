# OpenGL Experimenting - Boilerplate Code for Starting OpenGL

This repository is just a basic OpenGL experimentation repo, and is written with C++. As of now (June 2021), the project includes basic window and input handling.

## Dependencies

The dependencies in this project are:

* GLFW - For window and input handling
* glad - OpenGL loader
* cmake - to generate the Makefile (necessary for building)

## Insatallation

### Windows
The project already includes the necessary header files for dependencies, and all you need to do is build [GLFW's source files (which is "source package") ](https://www.glfw.org/download.html) (which I recommend), or just download the binaries (which can be found in the same webpage, with the name X-bit OS Binaries). Note that you need the change the library file in CMakeLists.txt since it uses MacOS's .dylib file format. If you struggle, google the problem, since Windows sucks and I don't know how to deal with Windows.

### MacOS

You can download GLFW using a package manager (I recommend [brew](brew.sh)). Verify that the glfw file is under /usr/local/Cellar/ and it contains both the include and lib folders. Also check that the libglfw.3.3.dylib file is inside /usr/local/lib folder since CMakeLists.txt file assumes that it is there. 

### Linux
You can download the pre-built binaries or the source file same as the Windows process, but change the GLFW_LIB path in CMakeLists.txt according to where the library file is. If you have any errors, just google it since I am not familiar with Linux also.

## Build

If you have completed the Insatallation process successfully, all you need to do is:

```bash
cd cmake-build-debug
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
make
./COpenGLTest
```

## Contributing
This is a (very) small project, and I don't expect any contributions at all, but if you have one please do contribute.

Thanks for being interested in.
