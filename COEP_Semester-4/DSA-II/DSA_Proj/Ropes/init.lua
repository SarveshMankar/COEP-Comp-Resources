require('base')
require('highlights')
require('maps')
require('plugins')

require'lspconfig'.pyright.setup{}
local has = function(x)
  return vim.fn.has(x) == 1
end
local is_mac = has "macunix"
local is_win = has "win32"

vim.g.dir = '/tmp'
vim.g.backupdir = '/tmp'
vim.g.undodir = '/tmp'
vim.g.viewdir = '/tmp'
if is_mac then
  require('craftzdog.macos')
end
if is_win then
  require('craftzdog.windows')
end
-- Lua
require("gruvbox").setup({
  undercurl = true,
  underline = true,
  bold = true,
  italic = true,
  strikethrough = true,
  invert_selection = false,
  invert_signs = false,
  invert_tabline = false,
  invert_intend_guides = false,
  inverse = true, -- invert background for search, diffs, statuslines and errors
  contrast = "", -- can be "hard", "soft" or empty string
  palette_overrides = {},
  overrides = {},
  dim_inactive = true,
  transparent_mode = true,
})

vim.cmd("colorscheme gruvbox")
require("startup").setup({theme = "dashboard"})




vim.cmd([[ autocmd BufWritePost * call rpcnotify(0, "saved", expand('%:p')) ]])
vim.cmd([[autocmd FileType * nnoremap <silent> <buffer> t call rpcnotify(0, "concatclip",  expand('%:p')]])



vim.cmd([[ autocmd TextYankPost * let yanked_text = getreg('"') | call rpcnotify(0, "yanked", expand('<afile>'), line('.'), col('.'), expand('<sfile>'), line("'<"), col("'<"), yanked_text) ]])

vim.cmd([[ 
augroup MyAutocmds
  autocmd!
  autocmd TextChanged,TextChangedI <buffer> call CheckBufferLength()
augroup END

let g:previous_buffer_length = line('$')

function! CheckBufferLength() abort
  let current_buffer_length = line('$')
  if current_buffer_length > g:previous_buffer_length
    let line_number = line('.')
    call rpcnotify(0, 'addedline', line_number, current_buffer_length - g:previous_buffer_length, expand("%:p"))
  endif

  if current_buffer_length < g:previous_buffer_length
    let line_number = line('.')
    call rpcnotify(0, 'rmedline', line_number, g:previous_buffer_length - current_buffer_length)
  endif
  let g:previous_buffer_length = current_buffer_length
endfunction

 ]])

