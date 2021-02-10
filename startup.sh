#!/bin/sh

## AUTOSTARTS ##
picom &
xwallpaper --zoom ~/Pictures/arch.jpg &

## BAR/STATUS SCRIPT ##


LOC=$(readlink -f "$0")
DIR=$(dirname "~/.config/dwm-bar/bar-functions/")

export IDENTIFIER="unicode"
export SEP1=" | "
export SEP2=""

# Import the modules
. "$DIR/bar-functions/dwm_battery.sh"
. "$DIR/bar-functions/dwm_alsa.sh"
. "$DIR/bar-functions/dwm_date.sh"

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
