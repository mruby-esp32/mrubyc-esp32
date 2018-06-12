mruby/c application template for ESP32
============

Before you get started you will need to follow the setup documentation from
the [esp-idf](https://github.com/espressif/esp-idf/tree/master/docs) project
for your specific operating system.

I have only tested this on macOS and using the most recent version of
[esp-idf](https://github.com/espressif/esp-idf/tree/94ec3c8e53e7f48133f17ae6c6e905fa5a856fd2).

You will need to recursively clone this project with the recursive flag
because it includes mruby as a submodule:

```
git clone --recursive https://github.com/mruby-esp32/mrubyc-esp32.git
```

The main ruby program can be found in the `main/resource/hello.rb` file. The
makefile configuration in `main/component.mk` and the main entry point source
file `main.c` will also be of interest if you want to change the name of
the ruby script. The examples included are very simple scripts that only print
to the ESP32's debug console.

You need the mrbc command to generate mruby bytecode from .rb file.
Please define `MRUBY_PATH` for environment variable.

```
export MRUBY_PATH=/path/to/mruby-install-dir
```


I'm assuming you have followed all the steps in the install documentation and
are at least somewhat familiar with the building steps. With that in mind you
can do something like the following and see the example running:

```
make menuconfig
make MRUBY_SCRIPT=hello.rb
make MRUBY_SCRIPT=hello.rb flash monitor
```

The flag `MRUBY_SCRIPT` can be replaced with your ruby code.
It's found from the `main/resource` directory.

---

The clean command will clean both the ESP32 build and the mruby/c build:

```
make clean
```

## License

```
Copyright (c) 2018 YAMAMOTO Masaya

Permission is hereby granted, free of charge, to any person obtaining a 
copy of this software and associated documentation files (the "Software"), 
to deal in the Software without restriction, including without limitation 
the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Software, and to permit persons to whom the 
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in 
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
DEALINGS IN THE SOFTWARE.
```
