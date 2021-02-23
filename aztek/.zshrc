# Enable Powerlevel10k instant prompt. Should stay close to the top of ~/.zshrc.
# Initialization code that may require console input (password prompts, [y/n]
# confirmations, etc.) must go above this block; everything else may go below.
#if [[ -r "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh" ]]; then
#  source "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh"
#fi

run () { time g++ $@.cpp && ./a.out && rm a.out}
runf () { time g++ -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -Wfatal-errors -Wall -Wextra -Wshadow -std=c++17 $@ && ./a.out && rm a.out }
rund () { time g++ -D_GLIBCXX_DEBUG -Wall -D_GLIBCXX_ASSERTIONS -DLIME -ggdb3 -fmax-errors=2  -std=c++17 $@ && ./a.out && rm a.out }
clion() { ~/Clion/clion-2020.3.2/bin/clion.sh }

cf(){ cd ~/aztek/cf }
cses() { cd ~/aztek/cses }
uh() {cd ~/aztek/uh} 

#kekW
prepare() {
        cp ~/aztek/cftemp/A.cpp $PWD
        cp ~/aztek/cftemp/B.cpp $PWD
        cp ~/aztek/cftemp/C.cpp $PWD
        cp ~/aztek/cftemp/D.cpp $PWD
        cp ~/aztek/cftemp/E.cpp $PWD
        cp ~/aztek/cftemp/F.cpp $PWD
        cp ~/aztek/cftemp/G.cpp $PWD
}

open(){
        vim -p A.cpp B.cpp C.cpp D.cpp E.cpp F.cpp G.cpp
}

cr(){vim $@.cpp}

#source ~/powerlevel10k/powerlevel10k.zsh-theme
#source ~/powerlevel10k/powerlevel10k.zsh-theme
#source ~/powerlevel10k/powerlevel10k.zsh-theme

# To customize prompt, run `p10k configure` or edit ~/.p10k.zsh.
#[[ ! -f ~/.p10k.zsh ]] || source ~/.p10k.zsh

alias tmux='tmux -2'
