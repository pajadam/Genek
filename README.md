# What is it?

This is Voxdung world generator written in 6 days for [Warsztat.GD](http://warsztat.gd/) compo.

[![screenshot1](https://blog.pajadam.me/data/posts/genek/genek_1.PNG)](https://blog.pajadam.me/posts/Genek-Voxdung-world-generator/)

# How to use?

You can simply double click Genek.exe. It'll start in graphical mode.

[![screenshot2](https://blog.pajadam.me/data/posts/genek/genek_2.PNG)](https://blog.pajadam.me/posts/Genek-Voxdung-world-generator/)

If you wanna use command line, just use `Genek (seed)` from command line.
It'll generate map with default options using given seed.

##### You need copy data from `data/VOXDUNG_DATA/` to your Voxdung Data Folder.

# What am I using to build this?

I'm using following software to build my project:
- Code::Blocks 16 IDE
- GCC 5.1 (TDM-1 32 bit)
- NANA C++ library Static

also useful:
- GIMP
- GVIM

# How can I build this one?

##### First of all you need to get some dependencies:
- Nana library in `/lib/Windows/`
- GCC compiler
- Make

##### You can also get some cool tools that will make this build even better!
You just need put path to them into global variables of your OS.
- UPX Packer
- OptiPNG
- CBP2MAKE

##### You dont need any of these, but it's useful piece of software :D 
It'll pack your executable, optimize PNG files and create up-to-date Makefiles when building ( now only on Windows ) :D

NOTE: You can use Code::Blocks project instead of makefiles.

##### Then you should run `make`. 

##### Built application will apear in `/release` directory.

# What is in project's directories?

- /src     - Code
- /data    - Application data
- /bin     - Binaries
- /obj     - Build objects
- /scripts - build scripts
- /lib     - library folder
