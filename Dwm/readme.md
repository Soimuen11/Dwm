# DWM - DYNAMIC WINDOW MANAGER - Phil Wayne's build
Dwm is an extremely fast, small, and dynamic window manager for X.

## Basic Instructions

### Requirements

In order to build dwm you need the Xlib header files.


### Installation

I recommend you create a .local/ directory in your /home.
So:
+ mkdir /home/$USER/.local 
+ cd /home/$USER/.local
+ mkdir repos
+ git clone https://github.com/Soimuen11/phil-wayne-dwm.git
+ cd phil-wayne-dwm
+ sudo make clean install

### Running dwm

Add the following line to your .xinitrc to start dwm using startx:

    exec dwm

In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:

    DISPLAY=foo.bar:1 exec dwm

(This will start dwm on display :1 of the host foo.bar.)

In order to display status info in the bar, you can do something
like this in your .xinitrc:

    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm

You may also do as I did and install SLSTATUS, which is another suckless
program.

### Configuration

The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.

### Keybindings

#### Custom

+ Super + v: vifm
+ Super + p: mocp
+ Super + t: thunderbird
+ Super + t: brave
+ Super + d: dmenu
+ Super + a: anki
+ Super + n: newsboat
+ Super + s: pavucontrol
+ Super + o: libreoffice
+ Super + c: calcurse

#### System

+ Super + w: close a window
+ Super + Enter: open a window
+ Super + Control + Q: Quit dwm
+ Super + [number]: Switch workspace
+ Super + shift + [number]: move a window to another workspace
+ Super h/j/k/l: move from one window to another

#### Modes

+ Super + shift + o: floating center mode
+ Super + shift + u: awesome mode
+ Super + shift + t: tile mode
+ Super + shift + m: monocle mode
