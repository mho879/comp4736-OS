#### Copying a local file into Ubuntu ####
## CD into the directory
## Copy target file
## Compile program using gcc
```sh
cd /mnt/c/Class/COMP\ 4736\ OS/comp4736-repo/labs/3/
cp warmup.c ~/
cd --
gcc -g warmup.c -o warmup -Wall
```

### Run warmup ###
```sh
gdb warmup
```