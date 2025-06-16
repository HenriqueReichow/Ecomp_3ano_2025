passaro(tweety).
peixe(goldie).
minhoca(molie).

gato(silvester).
amigo(silvester, eu).
amigo(eu, silvester).

gosta(X, Y) :- passaro(Y), gato(X).
gosta(X, Y) :- peixe(Y), gato(X).
gosta(X, Y) :- minhoca(Y), passaro(X).
gosta(X, Y) :- amigo(X, Y).
gosta(X, Y) :- amigo(Y, X).

come(X, Y) :- gosta(X, Y).

% resposta seria: ?- come(silvester, Oque).