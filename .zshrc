run () { time g++ $@.cpp && ./a.out && rm a.out}
runf () { time g++ -fsanitize=address -fsanitize=undefined -Wall -Wextra -Wshadow -std=c++17 $@ && ./a.out && rm a.out }
rund () { time g++ -D_GLIBCXX_DEBUG -Wall -D_GLIBCXX_ASSERTIONS -DLIME -ggdb3 -fmax-errors=2 -std=c++17 $@ && ./a.out && rm a.out }
clion() { ~/Clion/clion-2020.3.2/bin/clion.sh }

cf(){ cd ~/aztek/cf }
cses() { cd ~/aztek/cses }
rip() {cd ~/aztek/other }
#kekW
prepare() { cp ~/aztek/cftemp/A.cpp $PWD && cp ~/aztek/cftemp/B.cpp $PWD && cp ~/aztek/cftemp/C.cpp $PWD && cp ~/aztek/cftemp/D.cpp $PWD && cp ~/aztek/cftemp/E.cpp $PWD && cp ~/aztek/cftemp/F.cpp $PWD}
