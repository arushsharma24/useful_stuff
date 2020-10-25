#!/bin/bash

git add --all
echo "Enter commit message: "
read commit
git commit -m "$commit"
git push -u origin master
