#include "lista.h"





void inserta(Lista * lista,int pid, int prio, int idEntrada)
{
    
    if(encontrarPid(*lista,pid) == -1)
    {
        if(lista->primero == -1)
        {
            lista->primero = idEntrada;
            lista->ultimo = idEntrada;
        }else
        {
            
            lista->ultimo = idEntrada;
        }  
    }
}
/*
void elimina(Lista l)
{
    if(l->numeroElementos > 0)
    {
        Nodo elimina = l->primero;
        l->primero = elimina->sig;
        free(elimina);
        l->numeroElementos--;
    }
}



int getPrioridad(Lista l, int pid)
{
    Nodo nodoAux = encontrarPid(l,pid);
    if(nodoAux == NULL)
    {
        return -1;
    }
    else
    {
        return nodoAux->prio;
    }
}


void setPrioridad(Lista l, int pid, int prio)
{
    Nodo nodoAux = encontrarPid(l,pid);
    if(nodoAux != NULL)
    {
        nodoAux->prio = prio;
    }
}



int encontrarPid(Lista l, int pid)
{
    Nodo nodoAux = l->primero;
    while(nodoAux != NULL && nodoAux->pid != pid)
    {
        nodoAux = nodoAux->sig;
    }
    return nodoAux;
}*/

