#include <stdio.h>
#include <stdlib.h>


// un element al listei
typedef struct elem{
 int n; // informatia utila
 struct elem *urm; // camp de inlantuire catre urmatorul element
 }elem;
 
 
// aloca un nou element si ii seteaza campurile corespunzatoare
elem *nou(int n,elem *urm)
{
 elem *e=(elem*)malloc(sizeof(elem));
 if(!e){
 printf("memorie insuficienta");
 exit(EXIT_FAILURE);
 }
 e->n=n;
 e->urm=urm;
 return e;
}


typedef struct{
 elem *prim; // primul element din lista
 elem *ultim; // ultimul element din lista
 }Lista;
 
 
void init(Lista *lista)
{
 lista->prim=NULL;
 lista->ultim=NULL;
}


// adauga un element la inceputul listei
void adaugaInceput(Lista *lista,int n)
{
 elem *prim=lista->prim;
 lista->prim=nou(n,prim);
 if(!prim){ // lista initiala vida - trebuie setat si ultim pe elementul adaugat
 lista->ultim=lista->prim;
 }
}


// adauga un element la sfarsitul listei
void adaugaSfarsit(Lista *lista,int n)
{
 elem *e=nou(n,NULL);
 if(lista->ultim){ // adaugare in lista nevida
 lista->ultim->urm=e;
 }else{ // adaugare in lista vida
 lista->prim=e;
 }
 lista->ultim=e;
}


void afisare(Lista *lista)
{
 elem *crt;
 for(crt=lista->prim;crt;crt=crt->urm){
 printf("%d ",crt->n);
 }
 putchar('\n');
}


// elibereaza memoria ocupata de o lista
void eliberare(Lista *lista)
{
 elem *p,*crt=lista->prim;
 while(crt){
 p=crt->urm;
 free(crt);
 crt=p;
 }
}

/*Aplicația 7.1: Să se scrie o funcție care primește două liste și returnează 1 dacă ele sunt identice, altfel 0*/

int identice(Lista *lista1, Lista *lista2)
{
    elem *crt1, *crt2;

    for (crt1 = lista1->prim, crt2 = lista2->prim; crt1==NULL || crt2==NULL; crt1 = crt1->urm, crt2 = crt2->urm)
    {
        if (crt1->n != crt2->n)
            return 0;
    }

    if (crt1 != NULL || crt2 != NULL)
        return 0;

    return 1;
}

/*Aplicația 7.3: Să se scrie o funcție care primește ca parametri două liste și returnează o listă care reprezintă
reuniunea elementelor lor, fiecare element apărând o singură dată, chiar dacă în listele originare el este duplicat.*/

Lista reuniune( Lista *l1, Lista *l2)
{
	Lista r;
	init(&r);
	elem *crt1=l1->prim;
	elem *crt2=l2->prim;
	while (crt1 != NULL && crt2 != NULL)
	{
		if(crt1->n < crt2->n)
		{
			adaugaSfarsit(&r, crt1->n);
			crt1=crt1->urm;
		}
		else if( crt1->n > crt2->n)
		{
			adaugaSfarsit(&r, crt2->n);
			crt2=crt2->urm;
		}
		else
		{
			adaugaSfarsit(&r, crt1->n);
			crt1=crt1->urm;
			crt2=crt2->urm;
		}
	}
	while( crt1 != NULL )
	{
			adaugaSfarsit(&r, crt1->n);
			crt1=crt1->urm;
	}
	while(crt2!=NULL)
	{
		
			adaugaSfarsit(&r, crt2->n);
			crt2=crt2->urm;
		
	}
	
	return r;
}

/*Aplicația 7.4: Pentru implementarea listei care memorează adresa ultimului element, să se scrie o funcție șterge,
care șterge din listă un element dat.*/

void stergere(Lista *l, int n)
{
    elem *crt = l->prim;
    elem *crt_last = NULL;

    while (crt != NULL)
    {
        if (crt->n == n)
            crt_last = crt;

        crt = crt->urm;
    }


    if (crt_last == NULL)
    {
        // Valoarea nu a fost găsită în listă
        return;
    }


    if (crt_last == l->prim)
    {
        // Elementul de șters este primul din listă
        l->prim = crt_last->urm;
    }
    else
    {
        elem *prev = l->prim;
        while (prev->urm != crt_last)
        {
            prev = prev->urm;
        }
        prev->urm = crt_last->urm;
    }

    if (crt_last == l->ultim)
    {
        // Elementul de șters este ultimul din listă
        l->ultim = crt_last;
    }

    free(crt_last);
}

/*Aplicația 7.6: Să se scrie o funcție care primește ca parametri o listă (posibil vidă) de elemente sortate și un
element. Funcția va insera în listă noul element, astfel încât lista să rămână sortată. Folosind aceasta funcție, să
se scrie o funcție de sortare a unei liste, care primește ca parametru o listă nesortată și returnează una sortată.
Programul nu va folosi niciun vector.*/

void inserare( Lista *l, int element)
{
	elem *crt = l->prim;
	if(crt==NULL|| element < l->prim->n)
	{
		adaugaInceput(l, element);
		return;
	}
	
	elem *crt_last = NULL;
	for( crt=l->prim; crt->n<element; crt=crt->urm)
	{
            	crt_last = crt;
	}
	crt_last->urm=nou(element, crt);
}

void inversare(Lista *lista)
{
    elem *prev = NULL;
    elem *current = lista->prim;
    elem *next = NULL;

    while (current != NULL)
    {
        next = current->urm;
        current->urm = prev;
        prev = current;
        current = next;
    }

    lista->ultim = lista->prim; // Update ultim pointer to the new first element
    lista->prim = prev; // Update prim pointer to the new last element (previously first)
}

/*Aplicația 7.5: Să se scrie o funcție care primește două liste și returnează 1 dacă ele sunt egale, indiferent de
ordinea și numărul elementelor, altfel returnează 0.
Exemple: listele {1, 7, 3, 1, 3} și {7, 1, 3, 7} sunt egale. Listele {1,2} și {2} nu sunt egale*/

int egale( Lista *l1, Lista *l2)
{
	if(l1->prim == NULL )
	{
		if( l2-> prim ==NULL)
			return 1;
		else return 0;
	}
	else 
		if( l2-> prim ==NULL)
			return 0;
	
	elem * crt1;
	elem * crt2;
	
	for( crt1= l1->prim; crt1; crt1=crt1->urm)
	{
		int ok=0;
		for( crt2= l2->prim; crt2; crt2=crt2->urm)
		{
			if( crt1->n == crt2->n)
				ok=1;	
		
		}
		if( ok == 0 ) 
			return 0;
	}
	
	return (crt1==NULL && crt2==NULL);
}


int main()
{
 Lista lista, lista2;
 init(&lista);
 init(&lista2);
 adaugaSfarsit(&lista,10);
 adaugaSfarsit(&lista,18);
 adaugaSfarsit(&lista,49);
 adaugaSfarsit(&lista2,10);
 adaugaSfarsit(&lista2,18);
 adaugaSfarsit(&lista2,49);
 
 //printf("%d\n",  identice(&lista2, &lista2));
 
 //Lista r;
 //r=reuniune(&lista, &lista2);
 //afisare(&r);
 
 //stergere(&lista, 1081);
 
 //inserare(&lista, 9);
 
 //inversare(&lista);
 
 printf("%d\n", egale( &lista, &lista2));
 
 afisare(&lista);
 eliberare(&lista);
 afisare(&lista2);
 eliberare(&lista2);
 
 
 return 0;
}
