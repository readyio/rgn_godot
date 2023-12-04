#!/bin/bash
if [[ "$1" == "3.x" ]];
then
    # TODO
    echo -e "Not implemented."
else
    if [[ "$2" == "debug" ]];
    then
        cd ./godot && \
            ./../scripts/timeout scons platform=iphone target=template_debug
    else
        cd ./godot && \
            ./../scripts/timeout scons platform=iphone target=template_release
    fi
fi