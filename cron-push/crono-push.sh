#!/bin/bash

while true
do
    cd /nfs/homes/btani/Desktop/42cursus
    git add .
    cd /nfs/homes/btani/Desktop/42cursus
    git commit -m "Self Push: $(date)"
    cd /nfs/homes/btani/Desktop/42cursus
    git push
    sleep 3600
done
