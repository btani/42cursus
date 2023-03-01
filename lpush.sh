#!/bin/bash

cd /nfs/homes/btani/Desktop/42cursus && git add .
cd /nfs/homes/btani/Desktop/42cursus && git commit -m "Self Push: $(date)"
cd /nfs/homes/btani/Desktop/42cursus && git push
printf "\e[1;32mPush eseguito alle $(date | awk '{print substr($5, 1, 5), $6}')\e[0m"
