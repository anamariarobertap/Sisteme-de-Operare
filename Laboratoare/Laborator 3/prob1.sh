#!/bin/bash
ps -ef | awk '{ count[$1]++ } END { for (user in count) print user, count[user]}' | sort -k 2 -n -r

