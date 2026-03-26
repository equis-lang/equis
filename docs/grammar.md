# Equis Grammar (EBNF)

The formal grammar of the Equis language is defined using Extended Backus-Naur Form (EBNF).

```ebnf
(*
  Equis Language (v0.1.0)
  Extended Backus-Naur Form (EBNF) Grammar Specification
*)

program         = { statement } ;

statement       = function_decl
                | extern_decl
                | variable_decl
                | struct_decl
                | interface_decl
                | agent_decl
                | resource_decl
                | event_decl
                | commitment_decl
                | policy_decl
                | valuator_decl
                | exchange_decl
                | transformation_decl
                | use_stmt
                | flow_stmt
                | execute_stmt
                | reverse_stmt
                | assert_stmt
                | print_stmt
                | if_stmt
                | for_stmt
                | while_stmt
                | break_stmt
                | continue_stmt
                | return_stmt
                | assign_stmt
                | block
                | expression_stmt ;

(* Declarations *)

function_decl   = "fn" identifier "(" [ param_list ] ")" [ "->" type ] block ;
extern_decl     = "extern" "fn" identifier "(" [ param_list ] ")" [ "->" type ] ";" ;
variable_decl   = "let" [ "mut" ] identifier [ ":" type ] [ "=" expression ] ";" ;
struct_decl     = "struct" identifier "{" { identifier ";" } "}" ;
interface_decl  = "interface" identifier "{" { function_sig } "}" ;
function_sig    = "fn" identifier "(" [ param_list ] ")" [ "->" type ] ";" ;

(* REA Primitives *)

agent_decl      = "Agent" identifier [ "roles" "{" { string [ "," ] } "}" ] [ agent_body ] ;
agent_body      = "{" { identifier [ ":" ( identifier | string ) ] ";" } "}" ;
resource_decl   = "Resource" identifier "{" { identifier ":" ( identifier | number ) ";" } "}" ;

commitment_decl = "Commitment" identifier [ "evaluated_by" identifier ] "{" [ logic_block ] "flow" "{" { flow_stmt } "}" [ "roles" "{" { string } "}" ] "}" ;
event_decl      = "Event" identifier [ "fulfills" identifier ] [ "evaluated_by" identifier ] "{" [ logic_block ] "flow" "{" { flow_stmt } "}" [ "roles" "{" { string } "}" ] "}" ;
logic_block     = "logic" block ;

policy_decl     = "Policy" identifier "{" "logic" block "}" ;
valuator_decl   = "Valuator" identifier [ "implements" identifier ] "{" { function_decl | statement } "}" ;

exchange_decl       = "exchange" identifier "{" { identifier ";" } "}" ;
transformation_decl = "transformation" identifier [ "evaluated_by" identifier ] "{" [ logic_block ] "flow" "{" { flow_stmt } "}" [ "roles" "{" { string } "}" ] "}" ;

(* REA Operations *)

flow_stmt       = ( "in" | "out" ) expression identifier "from" identifier "to" identifier ";" ;
execute_stmt    = "execute" identifier brace_init [ ";" ] ;
reverse_stmt    = "reverse" identifier brace_init [ ";" ] ;

(* Common Elements *)

type            = "i64" | "f64" | "bool" | "ptr" | identifier ;
param_list      = param { "," param } ;
param           = [ "mut" ] identifier [ ":" type ] ;
block           = "{" { statement } "}" ;

if_stmt         = "if" "(" expression ")" statement [ "else" statement ] ;
for_stmt        = "for" "(" [ statement ] expression ";" [ expression ] ")" statement ;
while_stmt      = "while" "(" expression ")" statement ;
break_stmt      = "break" ";" ;
continue_stmt   = "continue" ";" ;
return_stmt     = "return" [ expression ] ";" ;
assign_stmt     = ( identifier | index_expr ) "=" expression ";" ;
print_stmt      = "print" expression ";" ;
assert_stmt     = "assert" "(" expression ")" ";" ;
use_stmt        = "use" ( string | identifier { "::" identifier } ) ";" ;
expression_stmt = expression ";" ;

(* Expressions *)

expression      = binary_expr ;
binary_expr     = unary_expr { operator unary_expr } ;
unary_expr      = [ "-" | "!" | "*" | "&" ] call_expr ;
call_expr       = primary { "(" [ arg_list ] ")" | "[" expression "]" | "." identifier } ;
primary         = identifier | number | string | "true" | "false" | "(" expression ")" ;

arg_list        = expression { "," expression } ;
brace_init      = "{" [ kv_pair { "," kv_pair } ] "}" ;
kv_pair         = identifier : expression ;

(* Lexical Tokens *)

identifier      = letter { letter | digit | "_" } ;
number          = [ "-" ] digit { digit } [ "." { digit } ] (* Scaled to 64-bit fixed-point *) ;
string          = "\"" { any_char_except_quote } "\"" ;
operator        = "+" | "-" | "*" | "/" | "==" | "!=" | "<" | ">" | "<=" | ">=" | "&&" | "||" ;
letter          = "a"..."z" | "A"..."Z" ;
digit           = "0"..."9" ;
```
