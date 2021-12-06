cmdtree
=======

cmdtree is a command launcher in the form of a tree. Commands are launched by a
sequence of keys that form a path in this tree.

Check [this](https://git.sr.ht/~jb55/cmdtree) for more informations and the original source.

Installing
----------

Adapt the Makefile to your system (mainly the prefix or the compiler).

libX11 and libXft are required. Once you have those installed, simply type:

    make && make install
