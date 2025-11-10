# zzz-optimizer

an zzz related optimizer that also happens to be ~~an Electron application with React~~ a ~~PyQt~~ normal Qt project

i made this because i suck at programming and wanted to get better, also theres no (good) zzz optimizer i think

## project Setup

you clone the repo as you do, and then i have no clue how you are supposed to generically compile this. i add it as a project in qt creator, and i am too lazy to figure out a different way

oh yeah, i remembered that you also need kimageformats cuz im using jxl for assets since this guy in dawn winery convinced me to

## building

i think this is how you do it, if it doesnt work, go back to qt creator and press run i guess:

```bash
cmake -G Ninja -S . -B build
cd build
ninja
```
