set number
call plug#begin()
Plug 'cohama/lexima.vim'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'catppuccin/vim', {'as': 'catppuccin'}
call plug#end()

colorscheme catppuccin_mocha
let g:airline_theme = 'catppuccin_mocha'
