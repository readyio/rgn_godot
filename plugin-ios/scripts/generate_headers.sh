#!/bin/bash
if [[ "$1" == "3.x" ]];
then
    if [[ "$2" == "debug" ]];
    then
        cd ./godot && \
            ./../scripts/timeout scons platform=iphone target=debug
    else
        cd ./godot && \
            ./../scripts/timeout scons platform=iphone target=release
    fi
else
    if [[ "$2" == "debug" ]];
    then
        cd ./godot && \
            ./../scripts/timeout scons platform=ios target=template_debug
    else
        cd ./godot && \
            ./../scripts/timeout scons platform=ios target=template_release
    fi
fi