#!/bin/sh


## AUTO-START/CONFIGURATION SCRIPT


picom &
feh --bg-max /home/sean/Pictures/arch.jpg &
eval $(/usr/bin/gnome-keyring-daemon --start --components=pkcs11,secrets,ssh) &


## BAR/STATUS SCRIPT


LOC=$(readlink -f "$0")
DIR=$(dirname "/home/sean/.config/dwm-bar/bar-functions/")

# Change the appearance of the module identifier. if this is set to "unicode", then symbols will be used as identifiers instead of text. E.g. [📪 0] instead of [MAIL 0].
# Requires a font with adequate unicode character support
export IDENTIFIER="unicode"

# Change the charachter(s) used to seperate modules. If two are used, they will be placed at the start and end.
export SEP1="["
export SEP2="]"

# Import the modules
. "$DIR/bar-functions/dwm_battery.sh"
. "$DIR/bar-functions/dwm_alsa.sh"
. "$DIR/bar-functions/dwm_date.sh"

# Update dwm status bar every second
while true
do
    # Append results of each func one by one to a string
    dispstr=""
    dispstr="$dispstr$(dwm_battery)"
    dispstr="$dispstr$(dwm_alsa)"
    dispstr="$dispstr$(dwm_date)"

    xsetroot -name "$dispstr"
    sleep 1
done
