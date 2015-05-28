#include <stdio.m>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

wzl* utworz(wzl* up)
{
  wzl* nowy=malloc(sizeof(wzl));
  int wybor=0;
  if(nowy==NULL) return NULL;
  (*nowy).up=up;
  (*nowy).left=NULL;
  (*nowy).right=NULL;
  printf("Podaj imie: ");
  fgets((*nowy).imie,20,stdin);
  printf("Podaj nazwisko: ");
  fgets((*nowy).nazwisko,20,stdin);
  printf("Podaj numer telefonu komorkowego: ");
  scanf("%ld",&(*nowy).nr1);
  printf("Czy chcesz dodac numer telefonu domowego? (1-Tak,0-Nie): ");
  scanf("%d",&wybor);
  if(wybor==1)
  {
    printf("Podaj numer telefonu domowego: ");
    scanf("%ld",&(*nowy).nr2);
  }
  else (*nowy).nr2=0;
  return nowy;
}

void wypisz1(wzl* wezel)
{
  printf("Imie:     %s",(*wezel).imie);
  printf("Nazwisko: %s",(*wezel).nazwisko);
  printf("Numer komorkowy:  %ld",(*wezel).nr1);
  if((*wezel).nr2!=0) printf("\nNumer domowy:  %ld\n",(*wezel).nr2);
  else printf("\n");
}

int porownaj(char input1[20],char input2[20])
{
  int i,wynik;
  char wyraz1[20];
  char wyraz2[20];
  for(i=0; i<20; i++)
  {
    wyraz1[i]=tolower(input1[i]);
    wyraz2[i]=tolower(input2[i]);
    if(wyraz1[i]=='\n') wyraz1[i]='\0';
    if(wyraz2[i]=='\n') wyraz2[i]='\0';
  }
  wynik=strcmp(wyraz1,wyraz2);
  return wynik;
}

void insert(wzl* nowy, wzl* root)
{
  wzl* wezel=root;
  int dzialanie;
  int koniec=1;
  do
  {
    dzialanie=porownaj((*nowy).imie,(*wezel).imie);
    if(dzialanie==0);
    {
      dzialanie=porownaj((*nowy).nazwisko,(*wezel).nazwisko);
    }
    if(dzialanie<=0)
    {
      if((*wezel).left==NULL)
      {
	(*wezel).left=nowy;
	(*nowy).up=wezel;
	koniec=0;
      }
      else
      {
	wezel=(*wezel).left;
      }
    }
    if(dzialanie>0)
    {
      if((*wezel).right==NULL)
      {
	(*wezel).right=nowy;
	(*nowy).up=wezel;
	koniec=0;
      }
      else
      {
	wezel=(*wezel).right;
      }
}
}while(koniec!=0);
}

void wyszukajminimum(wzl* wezel)
{
  if((*wezel).left==NULL)
  {
    wypisz1(wezel);
    return;
  }
  else
  {
    wyszukajminimum((*wezel).left);
  }
}

void wyszukajmaksimum(wzl* wezel)
{
  if((*wezel).right==NULL)
  {
    wypisz1(wezel);
    return;
  }
  else
  {
    wyszukajmaksimum((*wezel).right);
  }
}

void InOrder(wzl* root)
{
  if(root==NULL) return;
  InOrder((*root).left);
  wypisz1(root);
  printf("\n");
  InOrder((*root).right);
  return;
}

int szukaj(wzl* root,char input[20])
{
  wzl* wsk=root;
  int wynik=1;
  int end=0;
  do
  {
    if(wsk==NULL)
    {
      end=1;
    }
    else
    {
      wynik=porownaj(input,(*wsk).nazwisko);
      if(wynik==0) end=1;
      if(wynik<0)
      {
	wsk=(*wsk).left;
      }
      if(wynik>0)
      {
	wsk=(*wsk).right;
      }
    }
  }while(end!=1);
if(wynik==0)
  {
    printf("Osoba o podanym nazwisku istnieje i ma dane:\n");
    wypisz1(wsk);
  }
else printf("Osoba o podanym nazwisku nie istnieje.\n");
return wynik;
}

int zlicz(wzl* root)
{
  if(root==NULL) return 0;
  else
  {
    int iloscl=zlicz((*root).left);
    int iloscp=zlicz((*root).right);
    return iloscl+iloscp+1;
  }
}

int wysokosc(wzl* root)
{
  if(root==NULL) return 0;
  else
  {
    int wysokoscl=wysokosc((*root).left);
    int wysokoscp=wysokosc((*root).right);
    if(wysokoscl>wysokoscp) return (wysokoscl+1);
    else return (wysokoscp+1);
  }
}
