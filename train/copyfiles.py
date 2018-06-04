#!/usr/bin/env python

from os import system

dest="~/Workspace/prophet/crawler"
files = ["extract-feature.py", "learn.py", "flist-php.txt"]
copy_cmd = "cp -i"

for f in files:
    system(copy_cmd + " " + f + " " + dest)

system("cp -i inspace-revs/*  ~/Workspace/prophet/crawler/train/inspace-revs")
system("cp -i  -r raw-src/*  ~/Workspace/prophet/crawler/train/raw-src/")
system("cp -i  profile_localization.res ~/Workspace/prophet/build/tests/php-case-ecb9d80/php-ecb9d80-workdir")


system("~/Workspace/prophet/crawler/learn.py php")

