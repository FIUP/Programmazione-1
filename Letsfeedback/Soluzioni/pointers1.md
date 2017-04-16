## 1)

```c++
  int x=0, *y=&x, **Q;
  Q=*y;
```

#### error: invalid conversion from 'int' to 'int**

- [ ] Corretto
- [x] Sbagliato

## 2)

```c++
  int x=0, *y=&x, **Q;
  Q=&y;
```

- [x] Corretto
- [ ] Sbagliato

## 3)

```c++
  int x=0, *y=&x, **Q;
  Q=&y;
  y=0;
  cout << **Q << endl;
```

- [ ] Corretto
- [x] Sbagliato

## 4)

```c++
  int x=10, **y;
  *y=&x;
  cout << **y << endl;
```

- [x] Corretto
- [ ] Sbagliato

## 5)

```c++
  int *p, *q, **Q, x=0, y=1;
  p=&x;
  q=p;
  Q=&p;
  (*q)++;
  (*p)++;
  cout << **Q << endl;
```
#### Cosa stampa?

- [ ] 0
- [ ] 1
- [x] 2

## 6)

```c++
  int x, &y=x;
  x=y+1;
  y=y*2;
  cout << x << ' ' << y << endl;
```
#### Cosa stampa?

- [ ] 2 2
- [x] Non stampa niente, è sbagliato (in realtà i moderni compilatori inizializzano le variabili unitialized del main a 0)
- [ ] 1 2

## 7)

```c++
  int x=1, &y=x, *p=&y;
  x=y+1;
  y=y*2;
  cout << *p << ' ' << x << endl;
```
#### Cosa stampa?

- [ ] 2 4
- [ ] 4 2
- [x] 4 4