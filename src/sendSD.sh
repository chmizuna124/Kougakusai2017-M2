#!/bin/sh
# SDカードの名前
vols=("HIYOKO" "KOTORI" "KAKERUN" "SELAB")

# 第一引数のSDカードにselabをコピーする
function sendSD () {
     if  [ -e /Volumes/$1/ev3rt/apps ]; then
        if  [ -w /Volumes/$1/ev3rt/apps ]; then
            cp -f  $(PWD)/selab /Volumes/$1/ev3rt/apps/selab
            echo "\033[01;34mSuccess\033[0;39m"
            diskutil unmount /Volumes/$1/
        else
            echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
            echo "!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
            echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
            echo "\033[01;31mRead-only file system\033[0;39m"
            echo "\033[01;31mplz check SDCard「▼Lock」\033[0;39m"
            #echo "=====SDCard Information=================================="
            #ls -l /Volumes/$1/ev3rt/apps/
            #echo "========================================================="
        fi
    else
        echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
        echo "ERROR, /Volumes/$1/ev3rt/apps  not found."
        echo "Volumes:"
        ls -G /Volumes/
        echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
    fi
}

# 引数が1つあるとき
# 引数の名前のSDカードにコピー
if [ $# -eq 1 ]; then
  sendSD $1

# 引数が1つでないとき
# vols の中から存在するものを探し、そこにコピー
else
    volume=""
    for  v in ${vols[@]}; do
         if  [ -e /Volumes/$v/ev3rt/apps ]; then
            volume=$v
        fi
    done

    if  [ $volume ]; then
        echo "Copy to "$volume
       sendSD $volume
    else
        echo "Volume not found"
        echo "Volumes:"
        ls -G /Volumes/
    fi
fi