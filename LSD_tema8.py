cheie = "cheie"
stanga = "stanga"
dreapta = "dreapta"

nod1 = {cheie: 1, stanga: None, dreapta: None}  # frunza
nod7 = {cheie: 7, stanga: None, dreapta: None}  # frunza
nod4 = {cheie: 4, stanga: None, dreapta: None}  # frunza
nod5 = {cheie: 5, stanga: nod4, dreapta: nod7}
radacina = {cheie: 2, stanga: nod1, dreapta: nod5}  # = arborele binar



def afisare_inordine(arbore):
    if arbore is not None:
        afisare_inordine(arbore[stanga])
        print(arbore[cheie], end=" ")
        afisare_inordine(arbore[dreapta])


print("afisare inordine:", end="")
afisare_inordine(radacina)

'''
1. Scrieți o funcție care ia un arbore binar și returnează lista nodurilor care au un singur fiu. Ordinea nodurilor
în listă va fi cea din traversarea în inordine.
            2
           /\
          1  5
             /\
            4  7
'''

print("\n")
def singur_fiu(arbore):
    if arbore is not None:
        singur_fiu(arbore[stanga])
        if (arbore[stanga] is None) and (arbore[dreapta] is not None) or (arbore[stanga] is not None) and (arbore[dreapta] is  None) :
            print(arbore[cheie], end=" ")
        singur_fiu(arbore[dreapta])


print("singur fiu:", end="")
singur_fiu(radacina)


'''2. Scrieți o funcție care ia un arbore binar și returnează numărul total de noduri din arbore.'''

print("exercitiul 2;")
def nr_noduri(arbore):
    if arbore is not None:
        return 1+nr_noduri(arbore[stanga])
    elif arbore[dreapta] is not None:
        return 1+nr_noduri(arbore[dreapta])
    else:
        return 0
    
print(nr_noduri(radacina), end="")



print(radacina[dreapta])


