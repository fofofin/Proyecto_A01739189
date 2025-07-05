classDiagram
    class Unidad {
        - int vida
        - int salud
        - int ataque
        - int nivel

        + Unidad()
        + Unidad(int vida, int ataque, int nivel)

        + int getVida()
        + void setVida(int v)
        
        + int getSalud()
        + void setSalud(int s)

        + int getAtaque()
        + void setAtaque(int a)

        + int getNivel()
        + void setNivel(int n)

        + int porcentajeSalud()
        + void imprimeBarra()
        + void recibeAtaque(int ptosAtaque)
        + void atacar(Unidad& objetivo)
        + void imprimir()
    }