:- discontiguous progenitor/2.
:- discontiguous filho/2.
:- discontiguous mãe/2.
:- discontiguous pai/2.
:- discontiguous avó/2.
:- discontiguous avô/2.
:- discontiguous irmã/2.


% Predicados de fato
progenitor(maria, jose).
progenitor(joao, jose).
progenitor(joao, ana).
progenitor(jose, julia).
progenitor(jose, iris).
progenitor(iris, jorge).

masculino(joao).
masculino(jose).
masculino(jorge).

feminino(maria).
feminino(julia).
feminino(ana).
feminino(iris).

% Regra para filho
filho(Y, X) :-
    progenitor(X, Y).

% Regra para mãe
mãe(X, Y) :-
    progenitor(X, Y),
    feminino(X).

% Regra para pai
pai(X, Y) :-
    progenitor(X, Y),
    masculino(X).

% Regra para avó
avó(X, Y) :-
    progenitor(X, Z),
    progenitor(Z, Y),
    feminino(X).

% Regra para avô
avô(X, Y) :-
    progenitor(X, Z),
    progenitor(Z, Y),
    masculino(X).

% Regra para irmã
irmã(X, Y) :-
    progenitor(Z, X),
    progenitor(Z, Y),
    feminino(X),
    X \= Y.

%Consultas a serem utilizdas
%filho(Y, jose).
%filho(Y, maria).
%filho(Y, joao).
%filho(Y, ana).

%mãe(X, julia).
%pai(X, joao).
%avó(X, maria).
%avô(X, jorge).
%irmã(X, iris).
