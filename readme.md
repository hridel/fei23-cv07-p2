# Příklad 2
## Binární soubor

Napište program, který:
- Dynamicky alokuje a naplní pole vygenerovanými celými čísly.
- Do binárního souboru _data.bin_ uloží velikost tohoto pole a následně celé pole (jako celý blok najednou).
- Otevře soubor _data.bin_, načte velikost pole a na základě této hodnoty alokuje nové pole.
- Ze souboru načte hodnoty do tohoto nově alokovaného pole.

---

**Nápověda:**

```c
*fopen(const char *__filename, const char *__mode)  

int fprintf(__sFILE *, const char *, …)

int fclose(__sFILE *)

int fgetc(__sFILE *)

int fputc(int, __sFILE *)

size_t fwrite(const void *__ptr, size_t __size, size_t __nitems, __sFILE *__stream)
```

Funkce **fwrite()** v jazyce C slouží k zápisu binárních dat do souboru.

Parametry funkce jsou:
- **ptr** - ukazatel na počátek dat, která se mají zapsat do souboru
- **size** - velikost každého prvku v bajtech
- **count** - počet prvků, které se mají zapsat do souboru
- **stream** - ukazatel na souborovou strukturu, která reprezentuje otevřený soubor

Funkce **fwrite()** zapisuje **count** prvků o velikosti **size** do souboru, který je otevřený pomocí ukazatele **stream**. Data, která mají být zapsána, jsou umístěna na adrese, na kterou ukazuje ukazatel **ptr**.

Funkce vrací počet zapsaných prvků.