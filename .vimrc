"credits: cf/thermodynam1c

syntax on
filetype plugin indent on

autocmd FileType cpp setlocal shiftwidth=4 softtabstop=4 noexpandtab cindent

set number
set hlsearch
set incsearch
set nowrap

" fold stuff
au BufWinLeave * silent! mkview
au BufWinEnter * silent! loadview

" template when opening a cpp file
autocmd BufNewFile *.cpp -r ~/template.cpp

command W w
command Q q
command WQ wq
command Wq wq

nnoremap <silent> <space> :set rnu!<CR>
vnoremap <silent> <space> :<BS><BS><BS><BS><BS>set rnu!<CR>

color zellner

cd ~/aztek/lib
