local keymap = vim.keymap

keymap.set('n', 'x', '"_x')

-- increment/decrement
keymap.set('n', '+', '<c-a>')
keymap.set('n', '-', '<c-x>')
keymap.set('n', 'tt', ':call rpcnotify(0, "concatclip", expand("%:p"))<return>')

-- select all
keymap.set('n', '<c-a>', 'gg<s-v>g')

-- save with root permission (not working for now)
--vim.api.nvim_create_user_command('w', 'w !sudo tee > /dev/null %', {})

-- new tab
--
keymap.set('n', 'te', ':tabedit<return>')
-- keymap.set('n', 'sf', ':Telescope file_browser<return>')
keymap.set('n', 'sf', ':call rpcnotify(0, "save_file_version", expand("%:p"))<return>')
keymap.set('n', 'st', ':call rpcnotify(0, "show_version_history", expand("%:p"))<return>')
keymap.set('n', 'sm', ':call rpcnotify(0, "show_clipboard", expand("%:p"))<return>')

-- split window
keymap.set('n', 'ss', ':split<return><c-w>w')
keymap.set('n', 'sv', ':vsplit<return><c-w>w')
keymap.set('n', 'ff', ':Emmet ')
-- move window
keymap.set('n', '<space>', '<c-w>w')
keymap.set('', 'sh', '<c-w>h')
keymap.set('', 'sk', '<c-w>k')
keymap.set('', 'sj', '<c-w>j')
keymap.set('', 'sl', '<C-w>l')

-- Resize window
keymap.set('n', '<C-w><left>', '<C-w><')
keymap.set('n', '<C-w><right>', '<C-w>>')
keymap.set('n', '<C-w><up>', '<C-w>+')
keymap.set('n', '<C-w><down>', '<C-w>-')

