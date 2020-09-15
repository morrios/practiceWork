#!/bin/bash
function git.branch {
  br=`git branch | grep "*"`
  echo ${br/* /}
}

find . -type f -name '*.o' | xargs rm
find . -type f -name '*.o.dSYM' | xargs rm

branch=$(git.branch)
echo "当前分支： $branch "
git add .
if [[ $# > 0 ]]
then
git commit -m $1
else
git commit -m "save"
fi
git push origin $(git.branch)

