#!/bin/bash

SIGN="SIGHUP SIGQUIT SIGABRT SIGSTOP SIGTSTP SIGTTOU SIGTERM SIGINT SIGKILL"

ft_push() {
    cd /nfs/homes/btani/Desktop/42cursus && git add .
    cd /nfs/homes/btani/Desktop/42cursus && git commit -m "Push (log off): $(date)"
    cd /nfs/homes/btani/Desktop/42cursus && git push
    exit 0
}

for SIGNAL in $SIGN;
do
     trap "ft_push $SIGNAL" $SIGNAL
done
 
while true; do
    sleep 1
done
