# Persona 3 FES memory writer 
This is a copy of PCSX2 Trainer made by github user desukuran. 
A lot of the current features are based on said project.
However, this project was written using wxwidgets. This means you could compile this on any platform that supports it
... provided your platforms supports some linux functions.
And just as that project, it is limited to USA version of the game.

## Caution 
I only ran this until I was able to see changes on the game. However, I don't know if the
changes stay after a save or if it corrupts anything else in the process. 
As I said, I was only able to see changes onscreen. 

## Features

current features:

* Ability to edit your persona
* Ability to edit persona's stats and magic
* Ability to edit the main character's stat and mood.
* Ability to run in Linux
* Ability to edit number of items in your inventory



###### Now the tricky part
To run on windows you should be able to do so using the distributed windows vS redistrubtable c++ libraries?
In the relase folder there exists the wxwidget libraries needed to run this program

to run on a linux machine you might be able to do so by compiling using your system's libraries
for example: build-essentials for a Linux system like Ubuntu Linux
but you will also need to download wxwidgets libraries like it says here:
https://docs.codelite.org/wxWidgets/repo320/
mostly the following libraries:

apt-get install libwxbase3.2-0-unofficial \
                libwxbase3.2unofficial-dev \
                libwxgtk3.2-0-unofficial \
                libwxgtk3.2unofficial-dev \
                wx3.2-headers \
                wx-common 
                
Now assuming all that worked, then you could then run this command: (where -o specifies the output where the example is named persona3feswriter)
g++ P3fMem.cpp wx_persona3fespcsx2.cpp wxbinaryresource.cpp `wx-config --cxxflags --libs` -o persona3feswriter




good luck. happy persona 2 fes modding
