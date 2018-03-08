set shiftwidth=4
set number
set tabstop=4
set syntax 
set autoread
set cindent
set showcmd
set ruler
set mouse=a
filetype plugin indent on
map <F5> :w<CR> :!gdb %< -q <CR>
nmap <F9> :w<CR> :!g++ % -o %< -g -Wall<CR>
imap <F9> :w<CR> :!g++ % -o %< -g -Wall<CR>
nmap <F10> :w<CR> :!time ./%< <CR>
imap <F10> :w<CR> :!time ./%< <CR>

