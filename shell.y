goal: command_list;

arg_list:
        arg_list WORD
        | /*empty*/
        ;

cmd_and_args:
        WORD arg_list
        ;

pipe_list:
        pipe_list PIPE cmd_and_args
        | cmd_and_args
        ;

io_modifier:
        GREATGREAT WORD
        | GREAT WORD
        | GREATGREATAMPERSAND WORD
        | GREATAMPERSAND WORD
        | LESS WORD
        ;

io_modifer_list:
        io_modifer_list io_modifier
        | /*empty*/
        ;

background_optional:
        AMPERSAND
        | /*empty*/
        ;

command_line:
        pipe_list io_modifer_list background_optional NEWLINE
        | NEWLINE /*accepts empty cmd line*/
        | error NEWLINE{yyerrork;}
                /*error recovery*/

command_list:
        command_list command_line
        ; /*command loop*/