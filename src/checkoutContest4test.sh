#!/bin/bash
# course_ketsugouブランチの Contest.cpp とStartUp.cppを持ってくる
# ./checkoutContest4test.sh [-r]
# -r をつけると元に戻す

if [ "$1" = "-r" ]; then
    echo "RESET"
    git checkout  -- contest/Contest.cpp contest/StartUp.cpp
else
    git checkout remotes/origin/course_ketsugou -- contest/Contest.cpp contest/StartUp.cpp
    git reset HEAD  contest/Contest.cpp contest/StartUp.cpp     # unstage
fi

git status