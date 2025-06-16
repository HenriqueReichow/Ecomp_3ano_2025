:- discontiguous pai/2.
:- discontiguous mae/2.

mulher(mona).
mulher(jackie).
mulher(maggie).
mulher(marge).
mulher(liza).
mulher(patty).
mulher(selma).
mulher(ling).

homem(abraham).
homem(clancy).
homem(herb).
homem(homer).
homem(bart).

pai(abraham, herb).
pai(abraham, homer).
pai(homer, bart).
pai(homer, liza).
pai(homer, maggie).
pai(clancy, marge).
pai(clancy, patty).
pai(clancy, selma).

mae(mona, homer).
mae(jackie, marge).
mae(jackie, patty).
mae(jackie, selma).
mae(selma, ling).

irmao(X, Y) :-
    pai(P, X), pai(P, Y),
    mae(M, X), mae(M, Y),
    X \= Y.

tias_pai(X, Y) :-
    pai(P, Y),
    irmao(X, P),
    mulher(X).

tios_pai(X, Y) :-
    pai(P, Y),
    irmao(X, P),
    homem(X).

tias_mae(X, Y) :-
    mae(M, Y),
    irmao(X, M),
    mulher(X).

tios_mae(X, Y) :-
    mae(M, Y),
    irmao(X, M),
    homem(X).

primos_mae(X, Y) :-
    mae(M, Y),
    irmao(Tio, M),
    (pai(Tio, X); mae(Tio, X)).

primos_pai(X, Y) :-
    pai(P, Y),
    irmao(Tio, P),
    (pai(Tio, X); mae(Tio, X)).
